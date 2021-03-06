#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _GAME,
  _DVORAK,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  DVORAK = SAFE_RANGE,
  GAME,
  G_EXIT,
  PLOVER,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |Lower |      | Space|Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] =
{
 { KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,  KC_Y,    KC_F,   KC_G,  KC_C,    KC_R,    KC_L,  KC_BSPC },
 { KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,  KC_I,    KC_D,   KC_H,  KC_T,    KC_N,    KC_S,  KC_SLSH },
 { KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,  KC_X,    KC_B,   KC_M,  KC_W,    KC_V,    KC_Z,  KC_ENT  },
 { _______, KC_LCTL, KC_LALT, KC_LGUI, LOWER, _______, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT }
},


/* Game
 * ,-----------------------------------------------------------------------------------.
 * |   1  |  Tab |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |  Up  |   O  |  P   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   2  |  Esc |   A  |   S  |   D  |   F  |   G  |   H  | Left | Down | Right|  ;   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   3  | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   4  | Ctrl |      | Alt  |Lower |    Space    |Raise |      |      |      | Exit |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] =
{
 { KC_1,  KC_TAB, KC_Q,    KC_W,    KC_E,  KC_R,   KC_T,   KC_Y,  KC_U,    KC_UP,   KC_O,     KC_P    },
 { KC_2,  KC_ESC, KC_A,    KC_S,    KC_D,  KC_F,   KC_G,   KC_H,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_SCLN },
 { KC_3, KC_LSFT, KC_Z,    KC_X,    KC_C,  KC_V,   KC_B,   KC_N,  KC_M,    KC_COMM, KC_DOT,   KC_ENT  },
 { KC_4, KC_LCTL, _______, KC_LALT, LOWER, KC_SPC, KC_SPC, RAISE, _______, _______, _______,  G_EXIT  }
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   _  |  |   | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   =  |  (   |   [  |  ]   |   )  |   +  |   -  |  \   | Home |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  <   |   {  |  }   |   >  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] =
{
 { KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,     KC_PERC, KC_CIRC, KC_AMPR,   KC_ASTR, KC_UNDS,  KC_PIPE, KC_BSPC },
 { _______, _______, _______, KC_EQL,  KC_LPRN,    KC_LBRC, KC_RBRC, KC_RPRN,   KC_PLUS, KC_MINUS, KC_BSLS, KC_HOME },
 { _______, _______, _______, _______, S(KC_COMM), KC_LCBR, KC_RCBR, S(KC_DOT), _______, _______,  _______, _______ },
 { _______, _______, _______, _______, _______,    _______, _______, _______,   _______, _______,  _______, _______ }
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] =
{
 { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC },
 { KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, _______ },
 { _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______,  _______ },
 { _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU,  KC_MPLY }
},

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] =
{
 { KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1    },
 { XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC },
 { XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT },
 { EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX }
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |  M^  |      |      |      |  M1  |  M2  |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |  M<  |  Mv  |  M>  |AGnorm|AGswap|      | Game |Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =
{
 { _______, RESET,   _______,    KC_MS_UP,   _______,     _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______ },
 { _______, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, AG_NORM, AG_SWAP, _______, GAME,    DVORAK,  PLOVER,  _______ },
 { _______, _______, _______,    _______,    _______,     _______, _______, _______, _______, _______, _______, _______ },
 { _______, _______, _______,    _______,    _______,     _______, _______, _______, _______, _______, _______, _______ }
}


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case GAME:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GAME);
      }
      return false;
      break;
    case G_EXIT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        PORTE &= ~(1<<6);
      } else {
        unregister_code(KC_RSFT);
        PORTE |= (1<<6);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}
