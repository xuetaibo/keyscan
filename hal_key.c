#include "hal_key.h"

#include <stdio.h>

KeyEvent_CallBack_t KeyScanCBS;

static uint8_t hal_keyConfig(void);

static uint8_t hal_getKeyS2Sta(void);
static uint8_t hal_getKeyS3Sta(void);
static uint8_t hal_getKeyS4Sta(void);

uint8_t (*getKeyState[KEY_NUM])(void) = {
    hal_getKeyS2Sta,
    hal_getKeyS3Sta,
    hal_getKeyS4Sta,
};

uint8_t keyStep[KEY_NUM];            //按键检测流程
uint16_t keyScanTime[KEY_NUM];       //按键消抖时间
uint16_t keyPressLongTime[KEY_NUM];  //按键长按时间
uint16_t keyContPressTime[KEY_NUM];  //按键连续按下时间

void hal_keyInit(void) {
  uint8_t i;
  KeyScanCBS = 0;
  hal_keyConfig();

  for (i = 0; i < KEY_NUM; i++) {
    keyStep[i] = KEY_STEP_WAIT;
    keyScanTime[i] = KEY_SCANTIME;
    keyPressLongTime[i] = KEY_PRESS_LONG_TIME;
    keyContPressTime[i] = KEY_PRESS_CONTINUE_TIME;
  }
}

void hal_KeyScanCBSRegister(KeyEvent_CallBack_t pCBS) {
  if (KeyScanCBS == 0) {
    KeyScanCBS = pCBS;
  }
}

void hal_keyProc(void) {
  uint8_t i, KeyState[KEY_NUM];
  uint16_t keys;
  uint16_t state;

  for (i = 0; i < KEY_NUM; i++) {
    keys = 0;
    state = 0;
    KeyState[i] = getKeyState[i]();
    switch (keyStep[i]) {
      case KEY_STEP_WAIT:  //等待按键按下
        if (KeyState[i]) {
          keyStep[i] = KEY_STEP_CLICK;
        }
        break;
      case KEY_STEP_CLICK:  //按键按下
        if (KeyState[i]) {
          if (!(--keyScanTime[i])) {
            keyScanTime[i] = KEY_SCANTIME;
            keyStep[i] = KEY_STEP_LONG_PRESS;
            keys = i + 1;
            state = KEY_CLICK;
          } else {
            keyScanTime[i] = KEY_SCANTIME;
            keyStep[i] = KEY_STEP_WAIT;
          }
          break;
          case KEY_STEP_LONG_PRESS:  //按键长按
            if (KeyState[i]) {
              if (!(--keyPressLongTime[i])) {
                keyPressLongTime[i] = KEY_PRESS_LONG_TIME;
                keyStep[i] = KEY_STEP_WAIT;
                keys = i + 1;
                state = KEY_LONG_PRESS;
              } else {
                keyPressLongTime[i] = KEY_PRESS_LONG_TIME;
                keyStep[i] = KEY_STEP_WAIT;
                keys = i + 1;
                state = KEY_CLICK_RELEASE;
              }
            }
            break;
          case KEY_STEP_CONTINUOUS_PRESS:  //按键连续按下
            if (KeyState[i]) {
              if (!(--keyContPressTime[i])) {
                keyContPressTime[i] = KEY_PRESS_CONTINUE_TIME;
                keyStep[i] = KEY_STEP_WAIT;
                keys = i + 1;
                state = KEY_LONG_PRESS_CONTINUOUS;
              } else {
                keyContPressTime[i] = KEY_PRESS_CONTINUE_TIME;
                keyStep[i] = KEY_STEP_WAIT;
                keys = i + 1;
                state = KEY_LONG_PRESS_RELEASE;
              }
            }
            break;
        }
    }
  }
}

//----------------
static uint8_t hal_getKeyS2Status(void) {
  return (!GPIO_ReadInputDataBit(S2_PORT, S2_PIN));
}

static uint8_t hal_getKeyS3Status(void) {
  return (!GPIO_ReadInputDataBit(S3_PORT, S3_PIN));
}

static uint8_t hal_getKeyS4Status(void) {
  return (!GPIO_ReadInputDataBit(S4_PORT, S4_PIN));
}

//----------------
static uint8_t hal_getKeyS2Sta(void) {
  uint8_t sta = 0;
  if (hal_getKeyS2Status()) {
    sta = 1;
  }
  return sta;
}
//按键扫描
static uint8_t hal_getKeyS3Sta(void) {
  uint8_t sta = 0;
  if (hal_getKeyS3Status()) {
    sta = 1;
  }
  return sta;
}
