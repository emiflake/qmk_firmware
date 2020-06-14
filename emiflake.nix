let

  overlay = self: super:
    let
      addDarwinSupport = pkg:
        pkg.overrideAttrs (oldAttrs: {
          meta.platforms = (oldAttrs.meta.platforms or [ ])
            ++ self.lib.platforms.darwin;
        });
    in {
      dfu-programmer = addDarwinSupport super.dfu-programmer;
      teensy-loader-cli = addDarwinSupport super.teensy-loader-cli;

      avrgcc = super.avrgcc.overrideAttrs (oldAttrs: rec {
        name = "avr-gcc-8.1.0";
        src = super.fetchurl {
          url = "mirror://gcc/releases/gcc-8.1.0/gcc-8.1.0.tar.xz";
          sha256 = "0lxil8x0jjx7zbf90cy1rli650akaa6hpk8wk8s62vk2jbwnc60x";
        };
      });
    };

  nixpkgs = builtins.fetchTarball {
    url = "https://github.com/NixOS/nixpkgs/archive/0260747427737b980f0.tar.gz";
    sha256 = "1p2yc6b40xvvxvmlqd9wb440pkrimnlc2wsbpa5rddlpx1dn8qmf";
  };

  pkgs = import nixpkgs { overlays = [ overlay ]; };

in with pkgs;
let
  avr_incflags = [
    "-isystem ${avrlibc}/avr/include"
    "-B${avrlibc}/avr/lib/avr5"
    "-L${avrlibc}/avr/lib/avr5"
    "-B${avrlibc}/avr/lib/avr35"
    "-L${avrlibc}/avr/lib/avr35"
    "-B${avrlibc}/avr/lib/avr51"
    "-L${avrlibc}/avr/lib/avr51"
  ];

  avr = true;
in stdenv.mkDerivation {
  name = "emiflake";
  src = ./.;

  buildInputs = [
    dfu-programmer
    dfu-util
    diffutils
    git
    python3
    avrbinutils
    avrgcc
    avrlibc
    avrdude
    gcc-arm-embedded
    teensy-loader-cli
  ];

  AVR_CFLAGS = avr_incflags;
  AVR_ASFLAGS = avr_incflags;

  buildPhase = ''
    make planck/rev5:emiflake
  '';

  installPhase = ''
    mkdir -p $out/bin
    mv planck_rev5_emiflake.hex $out/bin
  '';
}
