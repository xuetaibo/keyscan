#include "hal_key.h"

#include <stdio.h>

KEY_CALLBACK key_callback = NULL;

uint8_t keyStep[KEY_NUM];                //�����������
uint16_t keyDebounceTime[KEY_NUM];       //��������ʱ��
uint16_t keyLongPressTime[KEY_NUM];      //��������ʱ��
uint16_t keyContinuePressTime[KEY_NUM];  //������������ʱ��
