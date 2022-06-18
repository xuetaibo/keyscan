#ifndef hal_key_h
#define hal_key_h

#include "hal_key.h"

#define uint8_t unsigned char
#define uint16_t unsigned short
#define uint32_t unsigned int

#define S2_PORT PORTC
#define S2_PIN GPIO_Pin_0

#define S3_PORT PORTC
#define S3_PIN GPIO_Pin_1

#define S4_PORT PORTC
#define S4_PIN GPIO_Pin_2

//按键定义
typedef enum { KEY_S2, KEY_S3, KEY_S4, KEY_NUM } KEY_TYPEDEF;

//按键的状�?
typedef enum {
  KEY_IDLE,                   //空闲
  KEY_CLICK,                  //按下
  KEY_CLICK_RELEASE,          //按下并释�?
  KEY_LONG_PRESS,             //长按
  KEY_LONG_PRESS_CONTINUOUS,  //长按继续
  KEY_LONG_PRESS_RELEASE,     //长按释放
} KEY_EVENT_TYPEDEF;

//按键检测过�?
typedef enum {
  KEY_STEP_WAIT,              //等待按键按下
  KEY_STEP_CLICK,             //按键按下
  KEY_STEP_LONG_PRESS,        //按键长按
  KEY_STEP_CONTINUOUS_PRESS,  //按键持续按下
} KEY_STEP_TYPEDEF;

//定义一个函数指针类�?
typedef void (*KeyEvent_CallBack_t)(KEY_TYPEDEF keys, KEY_EVENT_TYPEDEF state);

//按键扫描定时器Tick,每个Tick时间�?1ms
#define KEY_SCANT_TICK 10  // 10ms

//按键消抖时间,�?10ms为Tick
#define KEY_SCANTIME 2  // 20ms

//连续长按时间,�?10ms为Tick
#define KEY_PRESS_LONG_TIME 200  // 2s

//持续长按间隔时间
#define KEY_PRESS_CONTINUE_TIME 15  // 150ms

void hal_KeyInit(void);
void hal_keyProc(void);
void hal_KeyScanCBSRegister(KeyEvent_CallBack_t pCBS);
#endif
