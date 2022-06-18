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

//��������
typedef enum { KEY_S2, KEY_S3, KEY_S4, KEY_NUM } KEY_TYPEDEF;

//������״̬
typedef enum {
  KEY_IDLE,                   //����
  KEY_CLICK,                  //����
  KEY_CLICK_RELEASE,          //���²��ͷ�
  KEY_LONG_PRESS,             //����
  KEY_LONG_PRESS_CONTINUOUS,  //��������
  KEY_LONG_PRESS_RELEASE,     //�����ͷ�
} KEY_EVENT_TYPEDEF;

//����������
typedef enum {
  KEY_STEP_WAIT,              //�ȴ���������
  KEY_STEP_CLICK,             //��������
  KEY_STEP_LONG_PRESS,        //��������
  KEY_STEP_CONTINUOUS_PRESS,  //������������
} KEY_STEP_TYPEDEF;

//����һ������ָ������
typedef void (*KeyEvent_CallBack_t)(KEY_TYPEDEF keys, KEY_EVENT_TYPEDEF state);

//����ɨ�趨ʱ��Tick,ÿ��Tickʱ��Ϊ1ms
#define KEY_SCANT_TICK 10  // 10ms

//��������ʱ��,��10msΪTick
#define KEY_SCANTIME 2  // 20ms

//��������ʱ��,��10msΪTick
#define KEY_PRESS_LONG_TIME 200  // 2s

//�����������ʱ��
#define KEY_PRESS_CONTINUE_TIME 15  // 150ms

void hal_KeyInit(void);
void hal_keyProc(void);
void hal_KeyScanCBSRegister(KeyEvent_CallBack_t pCBS);
void hal_KeyScan(void);

#endif
