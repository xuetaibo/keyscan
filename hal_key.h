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
  KEY_IDLE,                 //����
  KEY_PRESS,                //����
  KEY_PRESS_RELEASE,        //���²��ͷ�
  KEY_LONG_PRESS,           //����
  KEY_LONG_PRESS_CONTINUE,  //��������
  KEY_LONG_PRESS_RELEASE,   //�����ͷ�
} KEY_STATUS;

//����������
typedef enum {
  KEY_STEP_WAIT,            //�ȴ���������
  KEY_STEP_PRESS,           //��������
  KEY_STEP_LONG_PRESS,      //��������
  KEY_STEP_CONTINUE_PRESS,  //������������
} KEY_STEP_TYPEDEF;

//����һ������ָ������
typedef void (*KEY_CALLBACK)(KEY_TYPEDEF key_type, KEY_STATUS key_status);

//����ɨ�趨ʱ��Tick,ÿ��Tickʱ��Ϊ1ms
#define KEY_SACN_TICK_MS 10  // 10ms

//��������ʱ��,��10msΪTick
#define KEY_DEBOUNCE_TICK_MS 2  // 20ms

//��������ʱ��,��10msΪTick
#define KEY_LONG_PRESS_TICK_MS 200  // 2s

#endif
