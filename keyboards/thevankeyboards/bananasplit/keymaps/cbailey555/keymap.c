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
    I3UP2,
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
    NEWTAB,
    CLOSETAB,
    PAUSEGUEST,
//    HSS, // host screenshot; do this later through I3
    GUESTSCREENSHOT,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_0] = LAYOUT_hhkb_arrow( \
        KC_ESC,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSLS,    KC_GRAVE,     \
        KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,                KC_BSPC,    \
        KC_LCTRL,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,       KC_L,       KC_SCLN,    KC_QUOT,                            KC_ENT,     \
        OSM(MOD_LSFT),            KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,       KC_COMM,    KC_DOT,     MT(MOD_RSFT, KC_SLSH),  KC_UP,      KC_F,  \
        KC_CAPS,   KC_LGUI,    KC_LALT,    TO(L_1),       KC_LEAD, KC_SPACE,   KC_RCTRL,    KC_LEFT,             KC_DOWN,    KC_UP,    KC_RIGHT    \
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
        TO(L_0),     I3CLOSE,   KC_W,   WS5,   KC_R,   KC_T,   KC_Y,   I3UP2,   KC_I,       WS0,       PAUSEGUEST,       KC_LBRC,    KC_RBRC,                KC_BSPC,    \
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


    SEQ_THREE_KEYS(KC_C, KC_E, KC_K) {
      SEND_STRING(" := ");
    }
    SEQ_FOUR_KEYS(KC_T, KC_A, KC_G, KC_S) {
      SEND_STRING(" <> </> "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
    }
  }
}




// macros
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
                  return false;
            case BTR:
                SEND_STRING(
                  SS_DOWN(X_LCTRL)
                  SS_TAP(X_TAB)
                  SS_UP(X_LCTRL)
                  );
                  return false;
            case I3NEW:
                SEND_STRING(
                  SS_DOWN(X_LALT)
                  SS_DOWN(X_ENTER)
                  SS_UP(X_LALT)
                  SS_UP(X_ENTER)
                );
                  return false;
            case I3LEFT:
                SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_H)
                    SS_UP(X_LALT)
                    SS_UP(X_H)
                );
                  return false;
            case I3RIGHT:
                SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_L)
                    SS_UP(X_LALT)
                    SS_UP(X_L)
                );
                  return false;
            case I3UP:
                SEND_STRING(
                  SS_LALT("k")
                );
                  return false;
            case I3UP2:
                SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_K)
                    SS_UP(X_K)
                    SS_UP(X_LALT)
                );
                  return false;
            case I3DOWN:
                SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_J)
                    SS_UP(X_LALT)
                    SS_UP(X_J)
                );
                  return false;
               case I3CLOSE:
                SEND_STRING(
                  SS_DOWN(X_LALT)
                  SS_DOWN(X_LSHIFT)
                  SS_DOWN(X_Q)
                  SS_UP(X_LALT)
                  SS_UP(X_LSHIFT)
                  SS_UP(X_Q)
                );
                  return false;
                case WS0:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_0)
                    SS_UP(X_LALT)
                    SS_UP(X_0)
                );
                  return false;
                 case WS1:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_1)
                    SS_UP(X_LALT)
                    SS_UP(X_1)
                );
                  return false;
                  case WS2:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_2)
                    SS_UP(X_LALT)
                    SS_TAP(X_2)
                );
                  return false;
                   case WS3:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_3)
                    SS_UP(X_LALT)
                    SS_TAP(X_3)
                );
                  return false;
                    case WS4:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_4)
                    SS_UP(X_LALT)
                    SS_TAP(X_4)
                );
                  return false;
                     case WS5:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_5)
                    SS_UP(X_LALT)
                    SS_TAP(X_5)
                );
                  return false;
                 case WS6:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_6)
                    SS_UP(X_LALT)
                    SS_TAP(X_6)
                );
                  return false;
                 case WS7:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_7)
                    SS_UP(X_LALT)
                    SS_TAP(X_7)
                );
                  return false;
                     case WS8:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_8)
                    SS_UP(X_LALT)
                    SS_TAP(X_8)
                );
                  return false;
                 case WS9:
                  SEND_STRING(
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_9)
                    SS_UP(X_LALT)
                    SS_TAP(X_9)
                );              
                  return false;
                case NEWTAB:
                  SEND_STRING(
                    SS_DOWN(X_LCTRL)
                    SS_DOWN(X_T)
                    SS_UP(X_LCTRL)
                    SS_UP(X_T)
                  );
                  return false;
                  case CLOSETAB:
                  SEND_STRING(
                    SS_DOWN(X_LCTRL)
                    SS_DOWN(X_W)
                    SS_UP(X_LCTRL)
                    SS_UP(X_W)
                  );
                  return false;
                  case GUESTSCREENSHOT:
                  SEND_STRING(
                    SS_DOWN(X_RCTRL)
                    SS_TAP(X_E)
                    SS_UP(X_RCTRL)
                  );
                  return false;
                  case PAUSEGUEST:
                  SEND_STRING(
                    SS_DOWN(X_RCTRL)
                    SS_TAP(X_P)
                    SS_UP(X_RCTRL)
                  );
                  return false;
        }
    }
    return true;
};