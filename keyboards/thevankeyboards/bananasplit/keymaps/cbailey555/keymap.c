#include QMK_KEYBOARD_H

#define DEFAULT_LAYER 0
#define LAYER_1       1




// これって、layerが始まるところをマークします。

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEFAULT_LAYER] = LAYOUT_base(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, \
    KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC, KC_BSLS, \
    KC_CAPS,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,   KC_QUOT, KC_ENT, \
    KC_LSHIFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),  KC_UP, _______, \
    KC_LCTRL,  KC_LGUI,  KC_LALT, KC_ENT,      MO(LAYER_1),      KC_SPC,  KC_RALT, KC_RCTL,  KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [LAYER_1] = LAYOUT_base( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,          _______, _______, _______,          _______, _______, _______, _______, _______ \
  ),

};

LEADER_EXTERNS();

/*
 implies arrow: 2192
 Forall : 2200
 Exists : 2203
 Membership: 2208
 Pi : 220F
 Sigma : 2210
 and : 2227
 or : 2228
 intersection: 2229
 Union : 222A
 neq : 2260
 leq : 2265
 geq : 2265
 proper subset: 22282
 subset eq : 2286
 xor : 2295
 nat : 2115
 Rat : 211A
 Real : 211D
 Z : 2124

 KC_W: window -> i3
 KC_B: browser 
 KC_E: editor
 D M : 'dynamic menu' (rofi)
 */

// Leader -> B = browser layer; vim conrols for tabs -> escape
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();


    SEQ_TWO_KEYS(KC_L, KC_T) {
      register_code(KC_LSHIFT);
      register_code(KC_COMMA);
      unregister_code(KC_LSHIFT);
      unregister_code(KC_COMMA);
    }

    SEQ_TWO_KEYS(KC_G, KC_T) {
      register_code(KC_LSHIFT);
      register_code(KC_DOT);
      unregister_code(KC_LSHIFT);
      unregister_code(KC_DOT);
    }

    SEQ_TWO_KEYS(KC_N, KC_T) {
      register_code(KC_LCTRL);
      register_code(KC_LALT);
      register_code(KC_T);
      unregister_code(KC_LCTRL);
      unregister_code(KC_LALT);
      unregister_code(KC_T);
    }



// i3 new pane
    SEQ_TWO_KEYS(KC_W, KC_N) {
      register_code(KC_LGUI);
      register_code(KC_ENT);
      unregister_code(KC_LGUI);
      unregister_code(KC_ENT);
    }

// i3 one left
    SEQ_TWO_KEYS(KC_W, KC_L) {
      register_code(KC_LGUI);
      register_code(KC_LEFT);
      unregister_code(KC_LGUI);
      unregister_code(KC_LEFT);
    }
// i3 two left
    SEQ_THREE_KEYS(KC_W, KC_2, KC_L) {
      register_code(KC_LGUI);
      register_code(KC_LEFT);
      unregister_code(KC_LEFT);
      register_code(KC_LEFT);
      unregister_code(KC_LEFT);
      unregister_code(KC_LGUI);
    }

// i3 one right
    SEQ_TWO_KEYS(KC_W, KC_R) {
      register_code(KC_LGUI);
      register_code(KC_RIGHT);
      unregister_code(KC_LGUI);
      unregister_code(KC_RIGHT);
    }
// i3 two right
    SEQ_THREE_KEYS(KC_W, KC_2, KC_R) {
      register_code(KC_LGUI);
      register_code(KC_RIGHT);
      unregister_code(KC_RIGHT);
      register_code(KC_RIGHT);
      unregister_code(KC_RIGHT);
      unregister_code(KC_LGUI);
    }

// i3 one up
    SEQ_TWO_KEYS(KC_W, KC_R) {
      register_code(KC_LGUI);
      register_code(KC_UP);
      unregister_code(KC_LGUI);
      unregister_code(KC_UP);
    }
// i3 two up
    SEQ_THREE_KEYS(KC_W, KC_2, KC_R) {
      register_code(KC_LGUI);
      register_code(KC_UP);
      unregister_code(KC_UP);
      register_code(KC_UP);
      unregister_code(KC_UP);
      unregister_code(KC_LGUI);
    }


// i3 one down
    SEQ_TWO_KEYS(KC_W, KC_R) {
      register_code(KC_LGUI);
      register_code(KC_DOWN);
      unregister_code(KC_LGUI);
      unregister_code(KC_DOWN);
    }
// i3 two down
    SEQ_THREE_KEYS(KC_W, KC_2, KC_R) {
      register_code(KC_LGUI);
      register_code(KC_DOWN);
      unregister_code(KC_DOWN);
      register_code(KC_DOWN);
      unregister_code(KC_DOWN);
      unregister_code(KC_LGUI);
    }

   SEQ_TWO_KEYS(KC_N, KC_T) {
      register_code(KC_LCTRL);
      register_code(KC_T);
      unregister_code(KC_LCTRL);
      unregister_code(KC_T);
    }



    SEQ_TWO_KEYS(KC_W, KC_0) {
      register_code(KC_LALT);
      register_code(0);
      unregister_code(KC_LALT);
      unregister_code(0);
    }

    SEQ_TWO_KEYS(KC_D, KC_M) {
      register_code(KC_LALT);
      register_code(KC_M);
      unregister_code(KC_LALT);
      unregister_code(KC_M);
    }

    SEQ_THREE_KEYS(KC_P, KC_R, KC_O) {
      SEND_STRING(" ::= ");
    }

    SEQ_THREE_KEYS(KC_C, KC_E, KC_Q) {
      SEND_STRING(" := ");
    }

    SEQ_TWO_KEYS(KC_E, KC_Q) {
      SEND_STRING(" = ");
    }

  }
}

const uint16_t PROGMEM fn_actions[] = {
};


