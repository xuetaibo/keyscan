#include "hal_key.h"

#include <stdio.h>

KEY_CALLBACK key_callback = NULL;

uint8_t keyStep[KEY_NUM];                //按键检测流程
uint16_t keyDebounceTime[KEY_NUM];       //按键消抖时间
uint16_t keyLongPressTime[KEY_NUM];      //按键长按时间
uint16_t keyContinuePressTime[KEY_NUM];  //按键连续按下时间
