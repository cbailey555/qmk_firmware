#include QMK_KEYBOARD_H

#define L_0     0
#define L_1     1
#define L_2     2
#define L_3     3
//#define L_4     4

enum custom_keycodes {
    MY_CUSTOM_MACRO = SAFE_RANGE,
    BTL,
    BTR,
    I3LEFT,
    I3RIGHT,
    I3UP,
    I3DOWN,
    I3CLOSE,
    I3NEW,
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
    EXPI3,
    NEWTAB,
    CLOSETAB,
    HOSTKEY,
    HOSTTHENRIGHT,
//    HSS, // host screenshot; do this later through I3
    GUESTSCREENSHOT,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_0] = LAYOUT_hhkb_arrow( \
        KC_ESC,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSLS,    KC_GRAVE,     \
        KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,                KC_BSPC,    \
        KC_LCTRL,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,       KC_L,       KC_SCLN,    KC_QUOT,                            KC_ENT,     \
        OSM(MOD_LSFT),            KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,       KC_COMM,    KC_DOT,     MT(MOD_RSFT, KC_SLSH),  KC_UP,      KC_F,  \
        KC_CAPS,   KC_LGUI,    KC_LALT,    TO(L_1),       KC_LEAD, KC_SPACE,   KC_RALT,    KC_LEFT,             KC_DOWN,    KC_UP,    KC_RIGHT    \
    ),

    [L_1] = LAYOUT_hhkb_arrow( \
        TO(L_0),     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSLS,    KC_GRAVE,     \
        KC_TAB,     KC_Q,   TO(L_3),   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,                KC_BSPC,    \
        KC_LCTRL,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,       KC_L,       KC_SCLN,    KC_QUOT,                            KC_ENT,     \
        OSM(MOD_LSFT),            KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   TO(L_2),   KC_M,       KC_COMM,    KC_DOT,     MT(MOD_RSFT, KC_SLSH),  KC_UP,      KC_F,  \
        KC_CAPS,   KC_LGUI,    KC_LALT,    TO(L_1),       KC_LEAD, KC_SPACE,   KC_RALT,    KC_LEFT,             KC_DOWN,    KC_UP,    KC_RIGHT    \
    ),

// number/math
    [L_2] = LAYOUT_hhkb_arrow( \
        TO(L_0),     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSLS,    KC_GRAVE,     \
        TO(L_0),     TO(L_0),   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,                KC_BSPC,    \
        KC_LCTRL,  KC_1,   KC_6,   KC_4,   KC_F,   KC_7,   KC_8,   KC_J,   KC_K,       KC_L,       KC_SCLN,    KC_QUOT,                            KC_ENT,     \
        OSM(MOD_LSFT),            KC_Z,   KC_X,   KC_C,   KC_V,   KC_2,   KC_9,   KC_M,       KC_COMM,    KC_DOT,     MT(MOD_RSFT, KC_SLSH),  KC_UP,      KC_F,  \
        KC_CAPS,   KC_LGUI,    KC_LALT,    TO(L_1),       KC_LEAD, KC_SPACE,   KC_RALT,    KC_LEFT,             KC_DOWN,    KC_UP,    KC_RIGHT    \
    ),

// i3 layer
    [L_3] = LAYOUT_hhkb_arrow( \
        TO(L_0),     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   WS8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSLS,    KC_GRAVE,     \
        TO(L_0),     I3CLOSE,   KC_W,   EXPI3,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,       WS0,       KC_P,       KC_LBRC,    KC_RBRC,                KC_BSPC,    \
        KC_LCTRL,  WS1,   WS6,   WS4,   KC_F,   WS7,   I3LEFT,   I3DOWN,   I3UP,       I3RIGHT,       KC_SCLN,    KC_QUOT,                            I3NEW,     \
        OSM(MOD_LSFT),            KC_Z,   KC_X,   WS3,   KC_V,   WS2,   WS9,   KC_M,       KC_COMM,    KC_DOT,     MT(MOD_RSFT, KC_SLSH),  KC_UP,      KC_F,  \
        KC_CAPS,   KC_LGUI,    KC_LALT,    TO(L_1),       KC_LEAD, KC_SPACE,   KC_RALT,    KC_LEFT,             KC_DOWN,    KC_UP,    KC_RIGHT    \
    ),


};

const uint16_t PROGMEM fn_actions[] = {
};


LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

// < = lt
    SEQ_TWO_KEYS(KC_L, KC_T) {
      register_code(KC_LSHIFT);
      register_code(KC_COMMA);
      unregister_code(KC_LSHIFT);
      unregister_code(KC_COMMA);
    }

// > = gt
    SEQ_TWO_KEYS(KC_G, KC_T) {
      register_code(KC_LSHIFT);
      register_code(KC_DOT);
      unregister_code(KC_LSHIFT);
      unregister_code(KC_DOT);
    }

// next tab = n t
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


   SEQ_TWO_KEYS(KC_N, KC_T) {
      register_code(KC_LCTRL);
      register_code(KC_T);
      unregister_code(KC_LCTRL);
      unregister_code(KC_T);
    }



// Go to workspace 0; W 0
    SEQ_TWO_KEYS(KC_W, KC_0) {
      register_code(KC_LALT);
      register_code(0);
      unregister_code(KC_LALT);
      unregister_code(0);
    }

// Move window to workspace 0; M W 0
    SEQ_THREE_KEYS(KC_M, KC_W, KC_0) {
      register_code(KC_LALT);
      register_code(KC_LSHIFT);
      register_code(0);
      unregister_code(KC_LALT);
      unregister_code(KC_LSHIFT);
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

    SEQ_THREE_KEYS(KC_C, KC_E, KC_K) {
      SEND_STRING(" := ");
    }

    SEQ_TWO_KEYS(KC_E, KC_K) {
      SEND_STRING(" = ");
    }

// Double quote sequence
    SEQ_TWO_KEYS(KC_D, KC_K) {
      SEND_STRING("\"\"");
      register_code(KC_LEFT);
      register_code(KC_LEFT);
    }

    SEQ_TWO_KEYS(KC_P, KC_A) {
      SEND_STRING("()");
      register_code(KC_LEFT);
      register_code(KC_LEFT);
    }

    SEQ_THREE_KEYS(KC_D, KC_O, KC_T) {
      SEND_STRING(".");
    }

    SEQ_THREE_KEYS(KC_M, KC_D, KC_C) {
      SEND_STRING("```");
      register_code(KC_ENTER);
      unregister_code(KC_ENTER);
      SEND_STRING("```");
      register_code(KC_UP);
      unregister_code(KC_UP);
      register_code(KC_ENTER);
      unregister_code(KC_ENTER);
    }

// guest screen shot = g s s
    SEQ_THREE_KEYS(KC_G, KC_S, KC_S) {
      register_code(KC_RCTRL);
      register_code(KC_E);
      unregister_code(KC_RCTRL);
      unregister_code(KC_E);
    }

// tilde = t i l
    SEQ_THREE_KEYS(KC_T, KC_I, KC_L) {
      register_code(KC_LSHIFT);
      register_code(KC_GRAVE);
      unregister_code(KC_GRAVE);
      unregister_code(KC_LSHIFT);
    }

/*
// grave = g r a
    SEQ_THREE_KEYS(KC_G, KC_R, KC_A) {
      register_code(KC_GRAVE);
      unregister_code(KC_GRAVE);
    }
    */

// pipe =  p i p
    SEQ_THREE_KEYS(KC_P, KC_I, KC_P) {
      register_code(KC_LSHIFT);
      register_code(KC_BSLASH);
      unregister_code(KC_BSLASH);
      unregister_code(KC_LSHIFT);
    }


    SEQ_THREE_KEYS(KC_C, KC_A, KC_P) {
      register_code(KC_CAPS);
      unregister_code(KC_CAPS);
    }

    SEQ_TWO_KEYS(KC_H, KC_K) {
      register_code(KC_RCTRL);
      unregister_code(KC_RCTRL);
    }

    SEQ_TWO_KEYS(KC_H, KC_R) {
      SEND_STRING(SS_TAP(X_RCTRL) SS_DOWN(X_RALT) SS_TAP(X_L) SS_UP(X_RALT));
    }

/*
 ampersand = a m p
    SEQ_THREE_KEYS(KC_P, KC_I, KC_P) {
      register_code(KC_LSHIFT);
      register_code(KC_7);
      unregister_code(KC_7);
      unregister_code(KC_LSHIFT);
    }
    */

/*
 exponent = p o w
    SEQ_THREE_KEYS(KC_P, KC_I, KC_P) {
      register_code(KC_LSHIFT);
      register_code(KC_7);
      unregister_code(KC_7);
      unregister_code(KC_LSHIFT);
    }
    */


    SEQ_THREE_KEYS(KC_H, KC_O, KC_M) {
      SEND_STRING("~/");
    }

  }
}




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
                  SS_TAP(X_TAB)
                  SS_UP(X_LSHIFT)
                  SS_UP(X_LCTRL)
                  );
            case BTR:
                SEND_STRING(
                  SS_DOWN(X_LCTRL)
                  SS_TAP(X_TAB)
                  SS_UP(X_LCTRL)
                  );
            case I3NEW:
                SEND_STRING(
                  SS_DOWN(X_LALT)
                  SS_TAP(X_ENTER)
                  SS_UP(X_LALT)
                );
            case I3LEFT:
                SEND_STRING(
                  SS_DOWN(X_LALT)
                  SS_TAP(X_H)
                  SS_UP(X_LALT)
                );
            case I3RIGHT:
                SEND_STRING(
                  SS_DOWN(X_LALT)
                  SS_TAP(X_L)
                  SS_UP(X_LALT)
                );
            case I3UP:
                SEND_STRING(
                  SS_DOWN(X_LALT)
                  SS_TAP(X_K)
                  SS_UP(X_LALT)
                );
            case I3DOWN:
                SEND_STRING(
                  SS_DOWN(X_LALT)
                  SS_TAP(X_J)
                  SS_UP(X_LALT)
                );
               case I3CLOSE:
                SEND_STRING(
                  SS_DOWN(X_LALT)
                  SS_DOWN(X_LSHIFT)
                  SS_TAP(X_Q)
                  SS_UP(X_LALT)
                  SS_UP(X_LSHIFT)
                );
                case WS0:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_TAP(X_0)
                    SS_UP(X_LALT)
                );
                 case WS1:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_TAP(X_1)
                    SS_UP(X_LALT)
                );
                  case WS2:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_TAP(X_2)
                    SS_UP(X_LALT)
                );
                   case WS3:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_TAP(X_3)
                    SS_UP(X_LALT)
                );
                    case WS4:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_TAP(X_4)
                    SS_UP(X_LALT)
                );
                     case WS5:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_TAP(X_5)
                    SS_UP(X_LALT)
                );
                 case WS6:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_TAP(X_6)
                    SS_UP(X_LALT)
                );
                 case WS7:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_TAP(X_7)
                    SS_UP(X_LALT)
                );
                     case WS8:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_TAP(X_8)
                    SS_UP(X_LALT)
                );
                 case WS9:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_TAP(X_9)
                    SS_UP(X_LALT)
                );              
                case NEWTAB:
                  SEND_STRING(
                    SS_DOWN(X_LCTRL)
                    SS_TAP(X_T)
                    SS_UP(X_LCTRL)
                  );
                  case CLOSETAB:
                  SEND_STRING(
                    SS_DOWN(X_LCTRL)
                    SS_TAP(X_W)
                    SS_UP(X_LCTRL)
                  );
                  case GUESTSCREENSHOT:
                  SEND_STRING(
                    SS_DOWN(X_RCTRL)
                    SS_TAP(X_E)
                    SS_UP(X_RCTRL)
                  );
                  case HOSTKEY:
                  SEND_STRING(
                    SS_DOWN(X_RCTRL)
                    SS_TAP(E)
                    SS_UP(X_RCTRL)
                  );
                  case HOSTTHENRIGHT:
                  SEND_STRING(
                    SS_DOWN(X_RCTRL)
                    SS_TAP(E)
                    SS_UP(X_RCTRL)
                    SS_DOWN(X_LALT)
                    SS_TAP(X_RIGHT)
                    SS_UP(X_LALT)
                  );
                  case EXPI3:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_K)
                    SS_UP(X_LALT)
                    SS_UP(X_K)
                  );
                return false;
        }
    }
    return true;
};