#include QMK_KEYBOARD_H

#define DEFAULT_LAYER 0
#define LAYER_1       1
#define LAYER_2       2
#define LAYER_3       3
#define LAYER_4       4
#define LAYER_5       5
#define LAYER_6       6


// これって、layerが始まるところをマークします。

enum custom_keycodes {
    MY_CUSTOM_MACRO = SAFE_RANGE,
    BTL,
    BTR,
    I3LEFT,
    I3RIGHT,
    I3UP,
    I3DOWN,
    I3CLOSE,
    WS0,
    WS1,
    WS2,
    WS3,
    WS4,
    WS5,
    WS6,
    WS7,
    WS8,
    WS9,
    NEWTAB,
    CLOSETAB
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEFAULT_LAYER] = LAYOUT_base(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, \
    KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC, KC_BSLS, \
    KC_CAPS,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,   KC_QUOT, KC_ENT, \
    OSM(MOD_LSFT),   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),  KC_UP, _______, \
    KC_LCTRL,  KC_LGUI,  KC_LALT, DF(LAYER_1),      KC_LEAD,      KC_SPC,  KC_RALT, KC_RCTL,  KC_LEFT, KC_DOWN, KC_RIGHT
  ),

// Route
  [LAYER_1] = LAYOUT_base( \
    DF(DEFAULT_LAYER), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, DF(LAYER_3), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, MY_CUSTOM_MACRO, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, DF(LAYER_4), DF(LAYER_2), _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,          DF(DEFAULT_LAYER), KC_LEAD, KC_SPC,          _______, _______, _______, _______, _______ \
  ),

// Num/math
  [LAYER_2] = LAYOUT_base( \
    DF(DEFAULT_LAYER), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_5, _______, _______, _______, _______, _______, KC_0, _______, _______, _______, _______, \
    _______, KC_1, KC_6, KC_4, _______, KC_7, KC_8, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_3, _______, KC_2, KC_9, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,          DF(DEFAULT_LAYER), KC_LEAD, KC_SPC,          _______, _______, _______, _______, _______ \
  ),

// i3/window manager * Just forget about layer 8.

  [LAYER_3] = LAYOUT_base( \
    DF(DEFAULT_LAYER), _______, _______, _______, _______, _______, _______, _______, WS8, _______, _______, _______, _______, \
    _______, KC_Q, _______, WS5, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, WS1, WS6, WS4, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, KC_ENT, \
    OSM(MOD_LSFT), _______, _______, WS3, _______, WS2, WS9, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,         DF(DEFAULT_LAYER), KC_LEAD, KC_SPC,          _______, _______, _______, _______, _______ \
  ),

// Browser layer
  [LAYER_4] = LAYOUT_base( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, CLOSETAB, _______, _______, NEWTAB, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, BTL, _______, _______, BTR, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,          DF(DEFAULT_LAYER), KC_LEAD, KC_SPC,          _______, _______, _______, _______, _______ \
  ),

  [LAYER_5] = LAYOUT_base( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,          _______, _______, _______,          _______, _______, _______, _______, _______ \
  ),

  [LAYER_6] = LAYOUT_base( \
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

/*
    SEQ_THREE_KEYS(KC_E, KC_S, KC_C) {
      register_code(DF(DEFAULT_LAYER));
      unregister_code(DF(DEFAULT_LAYER));
    }
    */

  }
}

const uint16_t PROGMEM fn_actions[] = {
};






bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case MY_CUSTOM_MACRO:
                SEND_STRING("QMK is the best thing ever!");
                return false;
            case BTL:
                SEND_STRING(
                  SS_DOWN(X_LSHIFT)
                  SS_DOWN(X_LCTRL)
                  SS_DOWN(X_TAB)
                  SS_UP(X_LSHIFT)
                  SS_UP(X_LCTRL)
                  SS_UP(X_TAB)
                  );
            case BTR:
                SEND_STRING(
                  SS_DOWN(X_LCTRL)
                  SS_DOWN(X_TAB)
                  SS_UP(X_LCTRL)
                  SS_UP(X_TAB)
                  );
            case I3LEFT:
                SEND_STRING(
                  SS_DOWN(X_LALT)
                  SS_DOWN(X_LEFT)
                  SS_UP(X_LALT)
                  SS_UP(X_LEFT)
                );
            case I3RIGHT:
                SEND_STRING(
                  SS_DOWN(X_LALT)
                  SS_DOWN(X_RIGHT)
                  SS_UP(X_LALT)
                  SS_UP(X_RIGHT)
                );
            case I3UP:
                SEND_STRING(
                  SS_DOWN(X_LALT)
                  SS_DOWN(X_UP)
                  SS_UP(X_LALT)
                  SS_UP(X_UP)
                );
            case I3DOWN:
                SEND_STRING(
                  SS_DOWN(X_LALT)
                  SS_DOWN(X_DOWN)
                  SS_UP(X_LALT)
                  SS_UP(X_DOWN)
                );
               case I3CLOSE:
                SEND_STRING(
                  SS_DOWN(X_LALT)
                  SS_DOWN(X_LSHIFT)
                  SS_DOWN(X_Q)
                  SS_UP(X_LALT)
                  SS_UP(X_LSHIFT)
                  SS_UP(X_LALT)
                );
                case WS0:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_0)
                    SS_UP(X_LALT)
                    SS_UP(X_0)
                );
                 case WS1:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_1)
                    SS_UP(X_LALT)
                    SS_UP(X_1)
                );
                  case WS2:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_2)
                    SS_UP(X_LALT)
                    SS_UP(X_2)
                );
                   case WS3:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_3)
                    SS_UP(X_LALT)
                    SS_UP(X_3)
                );
                    case WS4:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_4)
                    SS_UP(X_LALT)
                    SS_UP(X_0)
                );
                     case WS5:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_5)
                    SS_UP(X_LALT)
                    SS_UP(X_5)
                );
                 case WS6:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_6)
                    SS_UP(X_LALT)
                    SS_UP(X_6)
                );
                 case WS7:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_7)
                    SS_UP(X_LALT)
                    SS_UP(X_7)
                );
                     case WS8:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_8)
                    SS_UP(X_LALT)
                    SS_UP(X_8)
                );
                 case WS9:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_9)
                    SS_UP(X_LALT)
                    SS_UP(X_9)
                );              
                case NEWTAB:
                  SEND_STRING(
                    SS_DOWN(X_LCTRL)
                    SS_DOWN(X_T)
                    SS_UP(X_LCTRL)
                    SS_UP(X_T)
                  );
                  case CLOSETAB:
                  SEND_STRING(
                    SS_DOWN(X_LCTRL)
                    SS_DOWN(X_W)
                    SS_UP(X_LCTRL)
                    SS_UP(X_W)
                  );
                return false;
        }
    }
    return true;
};