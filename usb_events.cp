#line 1 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_events.c"
#line 1 "c:/users/matth/mplabxprojects/oscar.x/system.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdbool.h"



 typedef char _Bool;
#line 1 "c:/users/matth/mplabxprojects/oscar.x/usb_config.h"
#line 36 "c:/users/matth/mplabxprojects/oscar.x/system.h"
typedef enum
{
 SYSTEM_STATE_USB_START,
 SYSTEM_STATE_USB_SUSPEND,
 SYSTEM_STATE_USB_RESUME
} SYSTEM_STATE;
#line 55 "c:/users/matth/mplabxprojects/oscar.x/system.h"
void SYSTEM_Initialize( SYSTEM_STATE state );
#line 1 "c:/users/matth/mplabxprojects/oscar.x/app.h"



void APP_DeviceAudioMIDIInitialize(void);
void APP_DeviceAudioMIDITasks(void);
void APP_DeviceAudioMIDISOFHandler(void);
void APP_ControllerHandler(void);
void APP_ControllerInit(void);
#line 1 "c:/users/matth/mplabxprojects/oscar.x/status_led.h"



void APP_LEDUpdateUSBStatus(void);
#line 1 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdint.h"




typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;



typedef signed char int_fast8_t;
typedef signed int int_fast16_t;
typedef signed long int int_fast32_t;


typedef unsigned char uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned long int uint_fast32_t;


typedef signed int intptr_t;
typedef unsigned int uintptr_t;


typedef signed long int intmax_t;
typedef unsigned long int uintmax_t;
#line 1 "c:/users/matth/mplabxprojects/oscar.x/usb_common.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/limits.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdbool.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdint.h"
#line 132 "c:/users/matth/mplabxprojects/oscar.x/usb_common.h"
typedef union
{
 uint8_t bitmap;
 struct
 {
 uint8_t ep_num: 4;
 uint8_t zero_pkt: 1;
 uint8_t dts: 1;
 uint8_t force_dts: 1;
 uint8_t direction: 1;
 }field;

} TRANSFER_FLAGS;
#line 206 "c:/users/matth/mplabxprojects/oscar.x/usb_common.h"
typedef enum
{

 EVENT_NONE = 0,

 EVENT_DEVICE_STACK_BASE = 1,

 EVENT_HOST_STACK_BASE = 100,


 EVENT_HUB_ATTACH,


 EVENT_STALL,


 EVENT_VBUS_SES_REQUEST,




 EVENT_VBUS_OVERCURRENT,





 EVENT_VBUS_REQUEST_POWER,




 EVENT_VBUS_RELEASE_POWER,








 EVENT_VBUS_POWER_AVAILABLE,



 EVENT_UNSUPPORTED_DEVICE,



 EVENT_CANNOT_ENUMERATE,



 EVENT_CLIENT_INIT_ERROR,





 EVENT_OUT_OF_MEMORY,


 EVENT_UNSPECIFIED_ERROR,



 EVENT_DETACH,




 EVENT_TRANSFER,



 EVENT_SOF,


 EVENT_RESUME,



 EVENT_SUSPEND,



 EVENT_RESET,





 EVENT_DATA_ISOC_READ,





 EVENT_DATA_ISOC_WRITE,









 EVENT_OVERRIDE_CLIENT_DRIVER_SELECTION,







 EVENT_1MS,





 EVENT_ALT_INTERFACE,






 EVENT_HOLD_BEFORE_CONFIGURATION,


 EVENT_GENERIC_BASE = 400,

 EVENT_MSD_BASE = 500,

 EVENT_HID_BASE = 600,

 EVENT_PRINTER_BASE = 700,

 EVENT_CDC_BASE = 800,

 EVENT_CHARGER_BASE = 900,

 EVENT_AUDIO_BASE = 1000,

 EVENT_USER_BASE = 10000,




 EVENT_BUS_ERROR =  32767 

} USB_EVENT;
#line 371 "c:/users/matth/mplabxprojects/oscar.x/usb_common.h"
typedef struct _transfer_event_data
{
 TRANSFER_FLAGS flags;
 uint32_t size;
 uint8_t pid;

} USB_TRANSFER_EVENT_DATA;
#line 388 "c:/users/matth/mplabxprojects/oscar.x/usb_common.h"
typedef struct _vbus_power_data
{
 uint8_t port;
 uint8_t current;
} USB_VBUS_POWER_EVENT_DATA;
#line 401 "c:/users/matth/mplabxprojects/oscar.x/usb_common.h"
typedef struct _override_client_driver_data
{
 uint16_t idVendor;
 uint16_t idProduct;
 uint8_t bDeviceClass;
 uint8_t bDeviceSubClass;
 uint8_t bDeviceProtocol;
} USB_OVERRIDE_CLIENT_DRIVER_EVENT_DATA;
#line 463 "c:/users/matth/mplabxprojects/oscar.x/usb_common.h"
typedef  _Bool  (*USB_EVENT_HANDLER) ( USB_EVENT event, void *data, unsigned int size );
#line 1 "c:/users/matth/mplabxprojects/oscar.x/usb_config.h"
#line 73 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
typedef enum
{
#line 78 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
 DETACHED_STATE
 = 0x00 ,
#line 82 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
 ATTACHED_STATE
 = 0x01 ,
#line 86 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
 POWERED_STATE
 = 0x02 ,
#line 90 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
 DEFAULT_STATE
 = 0x04 ,
#line 97 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
 ADR_PENDING_STATE
 = 0x08 ,
#line 101 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
 ADDRESS_STATE
 = 0x10 ,
#line 108 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
 CONFIGURED_STATE
 = 0x20
} USB_DEVICE_STATE;



typedef enum
{

 EVENT_CONFIGURED
 = EVENT_DEVICE_STACK_BASE ,


 EVENT_SET_DESCRIPTOR,





 EVENT_EP0_REQUEST,
#line 156 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
 EVENT_ATTACH,




 EVENT_TRANSFER_TERMINATED

} USB_DEVICE_STACK_EVENTS;
#line 195 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
void USBDeviceInit(void);
#line 299 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
void USBDeviceTasks(void);
#line 351 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
void USBEnableEndpoint(uint8_t ep, uint8_t options);
#line 444 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
 void*  USBTransferOnePacket(uint8_t ep,uint8_t dir,uint8_t* data,uint8_t len);
#line 469 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
void USBStallEndpoint(uint8_t ep, uint8_t dir);
#line 493 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
void USBCancelIO(uint8_t endpoint);
#line 590 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
void USBDeviceDetach(void);
#line 635 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
void USBDeviceAttach(void);
#line 674 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
void USBCtrlEPAllowStatusStage(void);
#line 704 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
void USBCtrlEPAllowDataStage(void);
#line 780 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
void USBDeferOUTDataStage(void);
extern volatile  _Bool  USBDeferOUTDataStagePackets;
#line 850 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
void USBDeferStatusStage(void);
extern volatile  _Bool  USBDeferStatusStagePacket;
#line 902 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
 _Bool  USBOUTDataStageDeferred(void);
#line 985 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
void USBDeferINDataStage(void);
extern volatile  _Bool  USBDeferINDataStagePackets;
#line 1039 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
 _Bool  USBINDataStageDeferred(void);
#line 1109 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
 _Bool  USBGetRemoteWakeupStatus(void);
#line 1166 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
USB_DEVICE_STATE USBGetDeviceState(void);
#line 1222 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
 _Bool  USBGetSuspendState(void);
#line 1257 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
 _Bool  USBIsDeviceSuspended(void);
#line 1300 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
 _Bool  USBIsBusSuspended(void);
#line 1326 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
void USBSoftDetach(void);
#line 1364 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
 _Bool  USBHandleBusy( void*  handle);
#line 1402 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
uint16_t USBHandleGetLength( void*  handle);
#line 1434 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
uint16_t USBHandleGetAddr( void* );
#line 1534 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
 void*  USBGetNextHandle(uint8_t ep_num, uint8_t ep_dir);
#line 1567 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
void USBEP0Transmit(uint8_t options);
#line 1595 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
void USBEP0SendRAMPtr(uint8_t* src, uint16_t size, uint8_t Options);
#line 1627 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
void USBEP0SendROMPtr(uint8_t* src, uint16_t size, uint8_t Options);
#line 1655 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
void USBEP0Receive(uint8_t* dest, uint16_t size, void (*function));
#line 1690 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
 void*  USBTxOnePacket(uint8_t ep, uint8_t* data, uint16_t len);
#line 1727 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
 void*  USBRxOnePacket(uint8_t ep, uint8_t* data, uint16_t len);
#line 1759 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
 _Bool  USB_APPLICATION_EVENT_HANDLER(uint8_t address, USB_EVENT event, void *pdata, uint16_t size);
#line 1804 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
void USBIncrement1msInternalTimers(void);
#line 1863 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
uint32_t USBGet1msTickCount(void);
#line 1904 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
uint8_t USBGetTicksSinceSuspendEnd(void);
#line 1976 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
typedef union
{
 uint16_t Val;
 uint8_t v[2];
 struct
 {
 uint8_t LB;
 uint8_t HB;
 } byte;
} uint16_t_VAL;




typedef struct __attribute__ ((packed))
{
 union __attribute__ ((packed))
 {


 uint8_t *bRam;
 const uint8_t *bRom;
 uint16_t *wRam;
 const uint16_t *wRom;
 }pSrc;
 union __attribute__ ((packed))
 {
 struct __attribute__ ((packed))
 {

 uint8_t ctrl_trf_mem :1;
 uint8_t reserved :5;


 uint8_t includeZero :1;

 uint8_t busy :1;
 }bits;
 uint8_t Val;
 }info;
 uint16_t_VAL __attribute__((aligned)) wCount;
}IN_PIPE;

extern   IN_PIPE inPipes[];

typedef struct __attribute__ ((packed))
{
 union __attribute__ ((packed))
 {


 uint8_t *bRam;
 uint16_t *wRam;
 }pDst;
 union __attribute__ ((packed))
 {
 struct __attribute__ ((packed))
 {
 uint8_t reserved :7;

 uint8_t busy :1;
 }bits;
 uint8_t Val;
 }info;
 uint16_t_VAL wCount;
  void  (*pFunc)( void );
}OUT_PIPE;

extern    _Bool  RemoteWakeup;
extern    _Bool  USBBusIsSuspended;
extern   USB_DEVICE_STATE USBDeviceState;
extern   uint8_t USBActiveConfiguration;
extern   uint8_t USBTicksSinceSuspendEnd;
#line 1 "c:/users/matth/mplabxprojects/oscar.x/usb_hal.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdint.h"
#line 167 "c:/users/matth/mplabxprojects/oscar.x/usb_hal.h"
void  OTGCORE_SetDeviceAddr ( uint8_t addr );
#line 206 "c:/users/matth/mplabxprojects/oscar.x/usb_hal.h"
 void  OTGCORE_ControlUsbResistors ( uint8_t flags );
#line 237 "c:/users/matth/mplabxprojects/oscar.x/usb_hal.h"
 _Bool  USBHALSessionIsValid( void );
#line 263 "c:/users/matth/mplabxprojects/oscar.x/usb_hal.h"
 _Bool  USBHALControlBusPower( uint8_t cmd );
#line 293 "c:/users/matth/mplabxprojects/oscar.x/usb_hal.h"
unsigned long USBHALGetLastError( void );
#line 326 "c:/users/matth/mplabxprojects/oscar.x/usb_hal.h"
void USBHALHandleBusEvent ( void );
#line 367 "c:/users/matth/mplabxprojects/oscar.x/usb_hal.h"
 _Bool   OTGCORE_StallPipe ( TRANSFER_FLAGS pipe );
#line 404 "c:/users/matth/mplabxprojects/oscar.x/usb_hal.h"
 _Bool   OTGCORE_UnstallPipe ( TRANSFER_FLAGS pipe );
#line 438 "c:/users/matth/mplabxprojects/oscar.x/usb_hal.h"
uint16_t  OTGCORE_GetStalledEndpoints  ( void );
#line 475 "c:/users/matth/mplabxprojects/oscar.x/usb_hal.h"
 _Bool  USBHALFlushPipe( TRANSFER_FLAGS pipe );
#line 535 "c:/users/matth/mplabxprojects/oscar.x/usb_hal.h"
 _Bool  USBHALTransferData ( TRANSFER_FLAGS flags,
 void *buffer,
 unsigned int size );
#line 575 "c:/users/matth/mplabxprojects/oscar.x/usb_hal.h"
 _Bool  USBHALSetEpConfiguration ( uint8_t ep_num, uint16_t max_pkt_size, uint16_t flags );
#line 603 "c:/users/matth/mplabxprojects/oscar.x/usb_hal.h"
 _Bool  USBHALInitialize ( unsigned long flags );
#line 1 "c:/users/matth/mplabxprojects/oscar.x/usb_device_midi.h"
#line 22 "c:/users/matth/mplabxprojects/oscar.x/usb_device_midi.h"
typedef union
{
 uint32_t Val;
 uint8_t v[4];
 union
 {
 struct
 {
 uint8_t CIN :4;
 uint8_t CN :4;
 uint8_t MIDI_0;
 uint8_t MIDI_1;
 uint8_t MIDI_2;
 };
 struct
 {
 uint8_t CodeIndexNumber :4;
 uint8_t CableNumber :4;
 uint8_t DATA_0;
 uint8_t DATA_1;
 uint8_t DATA_2;
 };
 };
} USB_AUDIO_MIDI_EVENT_PACKET, *P_USB_AUDIO_MIDI_EVENT_PACKET;
#line 30 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_events.c"
 _Bool  USER_USB_CALLBACK_EVENT_HANDLER(USB_EVENT event, void *pdata, uint16_t size)
{
 switch( (int) event )
 {
 case EVENT_TRANSFER:
 break;

 case EVENT_SOF:
#line 40 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_events.c"
 APP_LEDUpdateUSBStatus();
 APP_DeviceAudioMIDISOFHandler();
 break;

 case EVENT_SUSPEND:

 APP_LEDUpdateUSBStatus();
 break;

 case EVENT_RESUME:

 APP_LEDUpdateUSBStatus();
 break;

 case EVENT_CONFIGURED:
#line 57 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_events.c"
 APP_DeviceAudioMIDIInitialize();
 break;

 case EVENT_SET_DESCRIPTOR:
 break;

 case EVENT_EP0_REQUEST:
 break;

 case EVENT_BUS_ERROR:
 break;

 case EVENT_TRANSFER_TERMINATED:
 break;

 default:
 break;
 }
 return  1 ;
}
