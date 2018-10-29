#include QMK_KEYBOARD_H

#define DEFAULT_LAYER 0
#define LAYER_1       1
#define LAYER_2       2
#define LAYER_3       3




// これって、layerが始まるところをマークします。

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEFAULT_LAYER] = LAYOUT_base(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, \
    KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC, KC_BSLS, \
    KC_LCTL,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,   KC_QUOT, KC_ENT, \
    KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),  MO(LAYER_1) , \
    KC_CAPS,  KC_LGUI,  KC_LALT, MO(LAYER_2),   KC_LEAD,      KC_SPC,  KC_RALT, KC_RCTL,  KC_LEFT, KC_DOWN, KC_RIGHT


  ),

  [LAYER_1] = LAYOUT_base( \
    KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F0, KC_F10, KC_F11, KC_F12, \
    _______, _______, _______, KC_5   , _______, _______, _______, _______, _______, KC_0   , _______, _______, _______, _______, \
    _______, KC_1   , KC_6   , KC_4   , _______, KC_7   , KC_8   , KC_VOLD, KC_VOLU, _______, _______, _______, _______, \
    _______, _______, _______, KC_3   , _______, KC_2   , KC_9   , _______, KC_MUTE, _______, _______, _______, _______, _______, \
    _______, _______, _______,          _______, _______, _______,          _______, _______, _______, _______, _______ \
  ),

  [LAYER_2] = LAYOUT_base( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,          _______, _______, _______,          _______, _______, _______, _______, _______ \
  ),
//  [LAYER_3] = LAYOUT_base( \
//    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
//    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
//    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
//    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
//    _______, _______, _______,          _______, _______, _______,          _______, _______, _______, _______, _______ \
//  ),


};

LEADER_EXTERNS();

// implies arrow: 2192
// Forall : 2200
// Exists : 2203
// Membership: 2208
// Pi : 220F
// Sigma : 2210
// and : 2227
// or : 2228
// intersection: 2229
// Union : 222A
// neq : 2260
// leq : 2265
// geq : 2265
// proper subset: 22282
// subset eq : 2286
// xor : 2295
// nat : 2115
// Rat : 211A
// Real : 211D
// Z : 2124


void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();


    SEQ_ONE_KEY(KC_T) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_T);
      unregister_code(KC_LCTL);
      unregister_code(KC_LALT);
      unregister_code(KC_T);
    }


    SEQ_TWO_KEYS(KC_N, KC_P) {
      register_code(KC_LGUI);
      register_code(KC_ENT);
      unregister_code(KC_LGUI);
      unregister_code(KC_ENT);
    }

   SEQ_TWO_KEYS(KC_N, KC_T) {
      register_code(KC_LCTL);
      register_code(KC_T);
      unregister_code(KC_LCTL);
      unregister_code(KC_T);
    }


    SEQ_THREE_KEYS(KC_C, KC_E, KC_Q) {
      SEND_STRING(" := ");
    }


  }
}

const uint16_t PROGMEM fn_actions[] = {
};

// Leader key Examples;

//    SEQ_ONE_KEY(KC_F) {
//      // Anything you can do in a macro.
//      SEND_STRING("QMK is awesome.");
//    }

//    SEQ_TWO_KEYS(KC_D, KC_D) {
//      SEND_STRING(SS_LCTRL("a")SS_LCTRL("c"));
//    }
