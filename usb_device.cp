#line 1 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
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
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stddef.h"




typedef int ptrdiff_t;
typedef int ptrdiffram_t;
typedef long int ptrdiffrom_t;


typedef unsigned int size_t;
typedef unsigned int sizeram_t;
typedef unsigned long int sizerom_t;


typedef unsigned char wchar_t;
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/string.h"





void * memchr(void *p, char n, unsigned int v);
int memcmp(void *s1, void *s2, int n);
void * memcpy(void * d1, void * s1, int n);
void * memmove(void * to, void * from, int n);
void * memset(void * p1, char character, int n);
char * strcat(char * to, char * from);
char * strchr(char * ptr, char chr);
int strcmp(char * s1, char * s2);
char * strcpy(char * to, char * from);
int strlen(char * s);
char * strncat(char * to, char * from, int size);
char * strncpy(char * to, char * from, int size);
int strspn(char * str1, char * str2);
char strcspn(char * s1, char * s2);
int strncmp(char * s1, char * s2, char len);
char * strpbrk(char * s1, char * s2);
char * strrchr(char *ptr, char chr);
char * strstr(char * s1, char * s2);
char * strtok(char * s1, char * s2);
#line 1 "c:/users/matth/mplabxprojects/oscar.x/usb_config.h"
#line 1 "c:/users/matth/mplabxprojects/oscar.x/usb.h"
#line 1 "c:/users/matth/mplabxprojects/oscar.x/usb_config.h"
#line 1 "c:/users/matth/mplabxprojects/oscar.x/usb_common.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/limits.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdbool.h"



 typedef char _Bool;
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
#line 1 "c:/users/matth/mplabxprojects/oscar.x/usb_ch9.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdint.h"
#line 69 "c:/users/matth/mplabxprojects/oscar.x/usb_ch9.h"
typedef struct __attribute__ ((packed)) _USB_DEVICE_DESCRIPTOR
{
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint16_t bcdUSB;
 uint8_t bDeviceClass;
 uint8_t bDeviceSubClass;
 uint8_t bDeviceProtocol;
 uint8_t bMaxPacketSize0;
 uint16_t idVendor;
 uint16_t idProduct;
 uint16_t bcdDevice;
 uint8_t iManufacturer;
 uint8_t iProduct;
 uint8_t iSerialNumber;
 uint8_t bNumConfigurations;
} USB_DEVICE_DESCRIPTOR;
#line 93 "c:/users/matth/mplabxprojects/oscar.x/usb_ch9.h"
typedef struct __attribute__ ((packed)) _USB_CONFIGURATION_DESCRIPTOR
{
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint16_t wTotalLength;
 uint8_t bNumInterfaces;
 uint8_t bConfigurationValue;
 uint8_t iConfiguration;
 uint8_t bmAttributes;
 uint8_t bMaxPower;
} USB_CONFIGURATION_DESCRIPTOR;
#line 116 "c:/users/matth/mplabxprojects/oscar.x/usb_ch9.h"
typedef struct __attribute__ ((packed)) _USB_INTERFACE_DESCRIPTOR
{
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bInterfaceNumber;
 uint8_t bAlternateSetting;
 uint8_t bNumEndpoints;
 uint8_t bInterfaceClass;
 uint8_t bInterfaceSubClass;
 uint8_t bInterfaceProtocol;
 uint8_t iInterface;
} USB_INTERFACE_DESCRIPTOR;
#line 135 "c:/users/matth/mplabxprojects/oscar.x/usb_ch9.h"
typedef struct __attribute__ ((packed)) _USB_ENDPOINT_DESCRIPTOR
{
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bEndpointAddress;
 uint8_t bmAttributes;
 uint16_t wMaxPacketSize;
 uint8_t bInterval;
} USB_ENDPOINT_DESCRIPTOR;
#line 185 "c:/users/matth/mplabxprojects/oscar.x/usb_ch9.h"
typedef struct
{
 uint8_t index;
 uint8_t type;
 uint16_t language_id;

} DESCRIPTOR_ID;
#line 200 "c:/users/matth/mplabxprojects/oscar.x/usb_ch9.h"
typedef struct __attribute__ ((packed)) _USB_OTG_DESCRIPTOR
{
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bmAttributes;
} USB_OTG_DESCRIPTOR;
#line 224 "c:/users/matth/mplabxprojects/oscar.x/usb_ch9.h"
typedef struct __attribute__ ((packed)) _USB_STRING_DSC
{
 uint8_t bLength;
 uint8_t bDescriptorType;

} USB_STRING_DESCRIPTOR;
#line 243 "c:/users/matth/mplabxprojects/oscar.x/usb_ch9.h"
typedef struct __attribute__ ((packed)) _USB_DEVICE_QUALIFIER_DESCRIPTOR
{
 uint8_t bLength;
 uint8_t bType;
 uint16_t bcdUSB;
 uint8_t bDeviceClass;
 uint8_t bDeviceSubClass;
 uint8_t bDeviceProtocol;
 uint8_t bMaxPacketSize0;
 uint8_t bNumConfigurations;
 uint8_t bReserved;

} USB_DEVICE_QUALIFIER_DESCRIPTOR;










typedef union __attribute__ ((packed))
{

 struct __attribute__ ((packed))
 {
 uint8_t bmRequestType;
 uint8_t bRequest;
 uint16_t wValue;
 uint16_t wIndex;
 uint16_t wLength;
 };
 struct __attribute__ ((packed))
 {
 unsigned :8;
 unsigned :8;
 union
 {
 uint16_t Val;
 uint8_t v[2];
 struct
 {
 uint8_t LB;
 uint8_t HB;
 } byte;
 } W_Value;

 union
 {
 uint16_t Val;
 uint8_t v[2];
 struct
 {
 uint8_t LB;
 uint8_t HB;
 } byte;
 } W_Index;

 union
 {
 uint16_t Val;
 uint8_t v[2];
 struct
 {
 uint8_t LB;
 uint8_t HB;
 } byte;
 } W_Length;
 };
 struct __attribute__ ((packed))
 {
 unsigned Recipient:5;
 unsigned RequestType:2;
 unsigned DataDir:1;
 unsigned :8;
 uint8_t bFeature;
 unsigned :8;
 unsigned :8;
 unsigned :8;
 unsigned :8;
 unsigned :8;
 };
 struct __attribute__ ((packed))
 {
 union
 {
 uint8_t bmRequestType;
 struct
 {
 uint8_t recipient: 5;
 uint8_t type: 2;
 uint8_t direction: 1;
 };
 }requestInfo;
 };
 struct __attribute__ ((packed))
 {
 unsigned :8;
 unsigned :8;
 uint8_t bDscIndex;
 uint8_t bDescriptorType;
 uint16_t wLangID;
 unsigned :8;
 unsigned :8;
 };
 struct __attribute__ ((packed))
 {
 unsigned :8;
 unsigned :8;
 uint8_t bDevADR;
 uint8_t bDevADRH;
 unsigned :8;
 unsigned :8;
 unsigned :8;
 unsigned :8;
 };
 struct __attribute__ ((packed))
 {
 unsigned :8;
 unsigned :8;
 uint8_t bConfigurationValue;
 uint8_t bCfgRSD;
 unsigned :8;
 unsigned :8;
 unsigned :8;
 unsigned :8;
 };
 struct __attribute__ ((packed))
 {
 unsigned :8;
 unsigned :8;
 uint8_t bAltID;
 uint8_t bAltID_H;
 uint8_t bIntfID;
 uint8_t bIntfID_H;
 unsigned :8;
 unsigned :8;
 };
 struct __attribute__ ((packed))
 {
 unsigned :8;
 unsigned :8;
 unsigned :8;
 unsigned :8;
 uint8_t bEPID;
 uint8_t bEPID_H;
 unsigned :8;
 unsigned :8;
 };
 struct __attribute__ ((packed))
 {
 unsigned :8;
 unsigned :8;
 unsigned :8;
 unsigned :8;
 unsigned EPNum:4;
 unsigned :3;
 unsigned EPDir:1;
 unsigned :8;
 unsigned :8;
 unsigned :8;
 };



} CTRL_TRF_SETUP, SETUP_PKT, *PSETUP_PKT;
#line 1 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdint.h"
#line 1 "c:/users/matth/mplabxprojects/oscar.x/usb_common.h"
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
#line 1 "c:/users/matth/mplabxprojects/oscar.x/usb_hal.h"
#line 1 "c:/users/matth/mplabxprojects/oscar.x/usb_ch9.h"
#line 1 "c:/users/matth/mplabxprojects/oscar.x/usb_device.h"
#line 1 "c:/users/matth/mplabxprojects/oscar.x/usb_device_local.h"
#line 1 "c:/users/matth/mplabxprojects/oscar.x/usb_config.h"
#line 35 "c:/users/matth/mplabxprojects/oscar.x/usb_device_local.h"
typedef union
{
 struct
 {
 unsigned char ping_pong_state :1;
 unsigned char transfer_terminated :1;
 } bits;
 uint8_t Val;
} EP_STATUS;
#line 120 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
typedef union
{
 uint8_t Val;
 struct __PACKED
 {
 unsigned b0:1;
 unsigned b1:1;
 unsigned b2:1;
 unsigned b3:1;
 unsigned b4:1;
 unsigned b5:1;
 unsigned b6:1;
 unsigned b7:1;
 } bits;
} uint8_t_VAL, uint8_t_BITS;






  USB_DEVICE_STATE USBDeviceState;
  uint8_t USBActiveConfiguration;
  uint8_t USBAlternateInterface[ 1 ];
volatile BDT_ENTRY *pBDTEntryEP0OutCurrent;
volatile BDT_ENTRY *pBDTEntryEP0OutNext;
volatile BDT_ENTRY *pBDTEntryOut[ 1 +1];
volatile BDT_ENTRY *pBDTEntryIn[ 1 +1];
  uint8_t shortPacketStatus;
  uint8_t controlTransferState;
  IN_PIPE inPipes[1];
  OUT_PIPE outPipes[1];
  uint8_t *pDst;
   _Bool  RemoteWakeup;
   _Bool  USBBusIsSuspended;
  USTAT_FIELDS USTATcopy;
  uint8_t endpoint_number;
   _Bool  BothEP0OutUOWNsSet;
  EP_STATUS ep_data_in[ 1 +1];
  EP_STATUS ep_data_out[ 1 +1];
  uint8_t USBStatusStageTimeoutCounter;
volatile  _Bool  USBDeferStatusStagePacket;
volatile  _Bool  USBStatusStageEnabledFlag1;
volatile  _Bool  USBStatusStageEnabledFlag2;
volatile  _Bool  USBDeferINDataStagePackets;
volatile  _Bool  USBDeferOUTDataStagePackets;
  uint32_t USB1msTickCount;
  uint8_t USBTicksSinceSuspendEnd;
#line 174 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
volatile BDT_ENTRY BDT[BDT_NUM_ENTRIES] BDT_BASE_ADDR_TAG;
#line 179 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
volatile CTRL_TRF_SETUP SetupPkt CTRL_TRF_SETUP_ADDR_TAG;
volatile uint8_t CtrlTrfData[ 8 ] CTRL_TRF_DATA_ADDR_TAG;
#line 211 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
  extern const USB_DEVICE_DESCRIPTOR device_dsc ;




 extern const uint8_t *const USB_CD_Ptr[];
#line 221 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
extern const uint8_t *const USB_SD_Ptr[];







extern  _Bool  USER_USB_CALLBACK_EVENT_HANDLER(USB_EVENT event, void *pdata, uint16_t size);

static void USBCtrlEPService(void);
static void USBCtrlTrfSetupHandler(void);
static void USBCtrlTrfInHandler(void);
static void USBCheckStdRequest(void);
static void USBStdGetDscHandler(void);
static void USBCtrlEPServiceComplete(void);
static void USBCtrlTrfTxService(void);
static void USBCtrlTrfRxService(void);
static void USBStdSetCfgHandler(void);
static void USBStdGetStatusHandler(void);
static void USBStdFeatureReqHandler(void);
static void USBCtrlTrfOutHandler(void);
static void USBConfigureEndpoint(uint8_t EPNum, uint8_t direction);
static void USBWakeFromSuspend(void);
static void USBSuspend(void);
static void USBStallHandler(void);
#line 277 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
void USBDeviceInit(void)
{
 uint8_t i;

 USBDisableInterrupts();



 USB_HAL_VBUSTristate();


 USBClearInterruptRegister(U1EIR);


 USBClearInterruptRegister(U1IR);


 U1EP0 = 0;

 DisableNonZeroEndpoints( 1 );

 SetConfigurationOptions();


 USBPowerModule();


 USBSetBDTAddress(BDT);


 for(i = 0; i < (sizeof(BDT)/sizeof(BDT_ENTRY)); i++)
 {
 BDT[i].Val = 0x00;
 }


 USBPingPongBufferReset = 1;


 U1ADDR = 0x00;


 USBPacketDisable = 0;


 USBPingPongBufferReset = 0;


 do
 {
 USBClearInterruptFlag(USBTransactionCompleteIFReg,USBTransactionCompleteIFBitNum);

 inPipes[0].info.Val = 0;
 outPipes[0].info.Val = 0;
 outPipes[0].wCount.Val = 0;
 }while(USBTransactionCompleteIF == 1);



 USBStatusStageEnabledFlag1 =  1 ;
 USBStatusStageEnabledFlag2 =  1 ;

 USBDeferINDataStagePackets =  0 ;
 USBDeferOUTDataStagePackets =  0 ;
 USBBusIsSuspended =  0 ;



 for(i = 0; i < (uint8_t)( 1 +1u); i++)
 {
 pBDTEntryIn[i] = 0u;
 pBDTEntryOut[i] = 0u;
 ep_data_in[i].Val = 0u;
 ep_data_out[i].Val = 0u;
 }


 pBDTEntryIn[0] = (volatile BDT_ENTRY*)&BDT[ 2 ];

 U1EP0 = EP_CTRL|USB_HANDSHAKE_ENABLED;

 BDT[ 0 ].ADR = ConvertToPhysicalAddress(&SetupPkt);
 BDT[ 0 ].CNT =  8 ;
 BDT[ 0 ].STAT.Val = _DAT0|_BSTALL;
 BDT[ 0 ].STAT.Val |= _USIE;


 USBActiveConfiguration = 0;

 USB1msTickCount = 0;
 USBTicksSinceSuspendEnd = 0;


 USBDeviceState = DETACHED_STATE;
}
#line 477 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
void USBDeviceTasks(void)
{
 uint8_t i;
#line 505 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 if ( 1  != 1)
 {

 U1CON = 0;


 U1IE = 0;


 USBDeviceState = DETACHED_STATE;
#line 542 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 USBClearUSBInterrupt();
 return;
 }
#line 566 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 if(USBDeviceState == DETACHED_STATE)
 {

 U1CON = 0;


 U1IE = 0;



 SetConfigurationOptions();


 while(!U1CONbits.USBEN){U1CONbits.USBEN = 1;}


 USBDeviceState = ATTACHED_STATE;
#line 587 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 }


 if(USBDeviceState == ATTACHED_STATE)
 {
#line 601 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 if(!USBSE0Event)
 {





 USBClearInterruptRegister(U1IR);



 U1IE=0;

 USBResetIE = 1;
 USBIdleIE = 1;
 USBDeviceState = POWERED_STATE;
 }
 }
#line 634 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 if(USBActivityIF && USBActivityIE)
 {
 USBClearInterruptFlag(USBActivityIFReg,USBActivityIFBitNum);



 USBWakeFromSuspend();

 }
#line 647 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 if(USBSuspendControl==1)
 {
 USBClearUSBInterrupt();
 return;
 }
#line 663 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 if(USBResetIF && USBResetIE)
 {
 USBDeviceInit();



 USBUnmaskInterrupts();

 USBDeviceState = DEFAULT_STATE;
#line 681 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 USBClearInterruptFlag(USBResetIFReg,USBResetIFBitNum);
 }
#line 687 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 if(USBIdleIF && USBIdleIE)
 {





 USBSuspend();

 }
#line 708 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 if(USBSOFIF)
 {

 if(USBSOFIE)
 {
  USER_USB_CALLBACK_EVENT_HANDLER(EVENT_SOF,0,1) ;
 }
 USBClearInterruptFlag(USBSOFIFReg,USBSOFIFBitNum);
#line 735 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 if(USBStatusStageTimeoutCounter != 0u)
 {
 USBStatusStageTimeoutCounter--;
 }





 if(USBStatusStageTimeoutCounter == 0)
 {
 USBCtrlEPAllowStatusStage();
 }

 }

 if(USBStallIF && USBStallIE)
 {
 USBStallHandler();
 }

 if(USBErrorIF && USBErrorIE)
 {
  USER_USB_CALLBACK_EVENT_HANDLER(EVENT_BUS_ERROR,0,1) ;
 USBClearInterruptRegister(U1EIR);
#line 767 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 }
#line 774 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 if(USBDeviceState < DEFAULT_STATE)
 {
 USBClearUSBInterrupt();
 return;
 }
#line 783 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 if(USBTransactionCompleteIE)
 {
 for(i = 0; i < 4u; i++)
 {
 if(USBTransactionCompleteIF)
 {

 USTATcopy.Val = U1STAT;
 endpoint_number = USBHALGetLastEndpoint(USTATcopy);

 USBClearInterruptFlag(USBTransactionCompleteIFReg,USBTransactionCompleteIFBitNum);




 if(USBHALGetLastDirection(USTATcopy) ==  0 )
 {
 ep_data_out[endpoint_number].bits.ping_pong_state ^= 1;
 }
 else
 {
 ep_data_in[endpoint_number].bits.ping_pong_state ^= 1;
 }




 if(endpoint_number == 0)
 {
 USBCtrlEPService();
 }
 else
 {
  USER_USB_CALLBACK_EVENT_HANDLER(EVENT_TRANSFER,(uint8_t*)&USTATcopy.Val,0) ;
 }
 }
 else
 {
 break;
 }
 }
 }

 USBClearUSBInterrupt();
}
#line 878 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
void USBEnableEndpoint(uint8_t ep, uint8_t options)
{
 unsigned char* p;



 if(options & USB_OUT_ENABLED)
 {
 USBConfigureEndpoint(ep,  0 );
 }
 if(options & USB_IN_ENABLED)
 {
 USBConfigureEndpoint(ep,  1 );
 }







 p = (unsigned char*)(&U1EP0+ep);

 *p = options;
}
#line 995 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 void*  USBTransferOnePacket(uint8_t ep,uint8_t dir,uint8_t* data,uint8_t len)
{
 volatile BDT_ENTRY* handle;


 if(dir != 0)
 {

 handle = pBDTEntryIn[ep];
 }
 else
 {

 handle = pBDTEntryOut[ep];
 }



 if(handle == 0)
 {
 return 0;
 }
#line 1029 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 handle->ADR = ConvertToPhysicalAddress(data);
 handle->CNT = len;
 handle->STAT.Val &= _DTSMASK;
 handle->STAT.Val |= (_DTSEN &  _DTSEN );
 handle->STAT.Val |= _USIE;


 if(dir !=  0 )
 {

 pBDTEntryIn[ep] = (BDT_ENTRY*)(((uintptr_t)pBDTEntryIn[ep]) ^ USB_NEXT_PING_PONG);
 }
 else
 {

 pBDTEntryOut[ep] = (BDT_ENTRY*)(((uintptr_t)pBDTEntryOut[ep]) ^ USB_NEXT_PING_PONG);
 }
 return ( void* )handle;
}
#line 1073 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
void USBStallEndpoint(uint8_t ep, uint8_t dir)
{
 BDT_ENTRY *p;

 if(ep == 0)
 {



 pBDTEntryEP0OutNext->CNT =  8 ;
 pBDTEntryEP0OutNext->ADR = ConvertToPhysicalAddress(&SetupPkt);
 pBDTEntryEP0OutNext->STAT.Val = _DAT0|(_DTSEN &  _DTSEN )|_BSTALL;
 pBDTEntryEP0OutNext->STAT.Val |= _USIE;
 pBDTEntryIn[0]->STAT.Val = _BSTALL;
 pBDTEntryIn[0]->STAT.Val |= _USIE;

 }
 else
 {
 p = (BDT_ENTRY*)(&BDT[ (4*ep+2*dir+0) ]);
 p->STAT.Val |= _BSTALL;
 p->STAT.Val |= _USIE;




 p = (BDT_ENTRY*)(&BDT[ (4*ep+2*dir+1) ]);
 p->STAT.Val |= _BSTALL;
 p->STAT.Val |= _USIE;

 }
}
#line 1129 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
void USBCancelIO(uint8_t endpoint)
{
 if(USBPacketDisable == 1)
 {


 pBDTEntryIn[endpoint]->Val &= _DTSMASK;
 pBDTEntryIn[endpoint]->Val ^= _DTSMASK;






 pBDTEntryIn[endpoint] = (BDT_ENTRY*)(((uintptr_t)pBDTEntryIn[endpoint]) ^ USB_NEXT_PING_PONG);

 pBDTEntryIn[endpoint]->STAT.Val &= _DTSMASK;
 pBDTEntryIn[endpoint]->STAT.Val ^= _DTSMASK;

 }
}
#line 1416 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
void USBCtrlEPAllowStatusStage(void)
{





 if(USBStatusStageEnabledFlag1 ==  0 )
 {
 USBStatusStageEnabledFlag1 =  1 ;
 if(USBStatusStageEnabledFlag2 ==  0 )
 {
 USBStatusStageEnabledFlag2 =  1 ;



 if(controlTransferState ==  2 )
 {
 pBDTEntryIn[0]->CNT = 0;
 pBDTEntryIn[0]->STAT.Val = _DAT1|(_DTSEN &  _DTSEN );
 pBDTEntryIn[0]->STAT.Val |= _USIE;
 }
 else if(controlTransferState ==  1 )
 {
 BothEP0OutUOWNsSet =  0 ;




 pBDTEntryEP0OutCurrent->CNT =  8 ;
 pBDTEntryEP0OutCurrent->ADR = ConvertToPhysicalAddress(&SetupPkt);
 pBDTEntryEP0OutCurrent->STAT.Val = _BSTALL;
 pBDTEntryEP0OutCurrent->STAT.Val |= _USIE;
 BothEP0OutUOWNsSet =  1 ;



 pBDTEntryEP0OutNext->CNT =  8 ;
 pBDTEntryEP0OutNext->ADR = ConvertToPhysicalAddress(&SetupPkt);
 pBDTEntryEP0OutNext->STAT.Val = _USIE;
 }
 }
 }
}
#line 1488 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
void USBCtrlEPAllowDataStage(void)
{
 USBDeferINDataStagePackets =  0 ;
 USBDeferOUTDataStagePackets =  0 ;

 if(controlTransferState ==  2 )
 {

 pBDTEntryEP0OutNext->CNT =  8 ;
 pBDTEntryEP0OutNext->ADR = ConvertToPhysicalAddress(&CtrlTrfData);
 pBDTEntryEP0OutNext->STAT.Val = _DAT1|(_DTSEN &  _DTSEN );
 pBDTEntryEP0OutNext->STAT.Val |= _USIE;
 }
 else
 {


 if(SetupPkt.wLength < inPipes[0].wCount.Val)
 {
 inPipes[0].wCount.Val = SetupPkt.wLength;
 }
 USBCtrlTrfTxService();




 pBDTEntryIn[0]->ADR = ConvertToPhysicalAddress(&CtrlTrfData);
 pBDTEntryIn[0]->STAT.Val = _DAT1|(_DTSEN &  _DTSEN );
 pBDTEntryIn[0]->STAT.Val |= _USIE;
 }
}
#line 1543 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
static void USBConfigureEndpoint(uint8_t EPNum, uint8_t direction)
{
 volatile BDT_ENTRY* handle;



 handle = (volatile BDT_ENTRY*)&BDT[ 0 ];
 handle +=  (4*EPNum+2*direction+0u) ;

 handle->STAT.UOWN = 0;




 if(direction ==  0 )
 {
 pBDTEntryOut[EPNum] = handle;
 }
 else
 {
 pBDTEntryIn[EPNum] = handle;
 }


 handle->STAT.DTS = 0;
 (handle+1)->STAT.DTS = 1;
#line 1585 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
}
#line 1616 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
static void USBCtrlEPServiceComplete(void)
{
#line 1622 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 USBPacketDisable = 0;





 if(inPipes[0].info.bits.busy == 0)
 {
 if(outPipes[0].info.bits.busy == 1)
 {
 controlTransferState =  2 ;
#line 1643 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 if(USBDeferOUTDataStagePackets ==  0 )
 {
 USBCtrlEPAllowDataStage();
 }



 USBStatusStageEnabledFlag2 =  0 ;
 USBStatusStageEnabledFlag1 =  0 ;
 }
 else
 {
#line 1659 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 pBDTEntryEP0OutNext->CNT =  8 ;
 pBDTEntryEP0OutNext->ADR = ConvertToPhysicalAddress(&SetupPkt);
 pBDTEntryEP0OutNext->STAT.Val = _DAT0|(_DTSEN &  _DTSEN )|_BSTALL;
 pBDTEntryEP0OutNext->STAT.Val |= _USIE;
 pBDTEntryIn[0]->STAT.Val = _BSTALL;
 pBDTEntryIn[0]->STAT.Val |= _USIE;
 }
 }
 else
 {
 if(SetupPkt.DataDir ==  ( 0x80 >>7) )
 {
 controlTransferState =  1 ;
#line 1685 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 if(USBDeferINDataStagePackets ==  0 )
 {
 USBCtrlEPAllowDataStage();
 }
#line 1710 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 USBStatusStageEnabledFlag2 =  0 ;
 USBStatusStageEnabledFlag1 =  0 ;
 if(USBDeferStatusStagePacket ==  0 )
 {
 USBCtrlEPAllowStatusStage();
 }
 }
 else
 {










 controlTransferState =  2 ;


 pBDTEntryEP0OutNext->CNT =  8 ;
 pBDTEntryEP0OutNext->ADR = ConvertToPhysicalAddress(&SetupPkt);
 pBDTEntryEP0OutNext->STAT.Val = _BSTALL;
 pBDTEntryEP0OutNext->STAT.Val |= _USIE;


 USBStatusStageEnabledFlag2 =  0 ;
 USBStatusStageEnabledFlag1 =  0 ;
 if(USBDeferStatusStagePacket ==  0 )
 {
 USBCtrlEPAllowStatusStage();
 }
 }

 }

}
#line 1771 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
static void USBCtrlTrfTxService(void)
{
 uint8_t byteToSend;



 byteToSend =  8 ;
 if(inPipes[0].wCount.Val < (uint8_t) 8 )
 {
 byteToSend = inPipes[0].wCount.Val;






 if(shortPacketStatus ==  0 )
 {
 shortPacketStatus =  1 ;
 }
 else if(shortPacketStatus ==  1 )
 {
 shortPacketStatus =  2 ;
 }
 }



 inPipes[0].wCount.Val -= byteToSend;




 pBDTEntryIn[0]->CNT = byteToSend;



 pDst = (  uint8_t*)CtrlTrfData;
 if(inPipes[0].info.bits.ctrl_trf_mem ==  0x00 )
 {
 while(byteToSend)
 {
 *pDst++ = *inPipes[0].pSrc.bRom++;
 byteToSend--;
 }
 }
 else
 {
 while(byteToSend)
 {
 *pDst++ = *inPipes[0].pSrc.bRam++;
 byteToSend--;
 }
 }
}
#line 1852 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
static void USBCtrlTrfRxService(void)
{
 uint8_t byteToRead;
 uint8_t i;



 byteToRead = pBDTEntryEP0OutCurrent->CNT;





 if(byteToRead > outPipes[0].wCount.Val)
 {
 byteToRead = outPipes[0].wCount.Val;
 }

 outPipes[0].wCount.Val -= byteToRead;



 for(i=0;i<byteToRead;i++)
 {
 *outPipes[0].pDst.bRam++ = CtrlTrfData[i];
 }



 if(outPipes[0].wCount.Val > 0)
 {
 pBDTEntryEP0OutNext->CNT =  8 ;
 pBDTEntryEP0OutNext->ADR = ConvertToPhysicalAddress(&CtrlTrfData);
 if(pBDTEntryEP0OutCurrent->STAT.DTS == 0)
 {
 pBDTEntryEP0OutNext->STAT.Val = _DAT1|(_DTSEN &  _DTSEN );
 pBDTEntryEP0OutNext->STAT.Val |= _USIE;
 }
 else
 {
 pBDTEntryEP0OutNext->STAT.Val = _DAT0|(_DTSEN &  _DTSEN );
 pBDTEntryEP0OutNext->STAT.Val |= _USIE;
 }
 }
 else
 {



 pBDTEntryEP0OutNext->CNT =  8 ;
 pBDTEntryEP0OutNext->ADR = ConvertToPhysicalAddress(&SetupPkt);



 pBDTEntryEP0OutNext->STAT.Val = _BSTALL;
 pBDTEntryEP0OutNext->STAT.Val |= _USIE;






 if(outPipes[0].pFunc !=  ((void *)0) )
 {








 outPipes[0].pFunc();

 }
 outPipes[0].info.bits.busy = 0;
#line 1941 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 if(USBDeferStatusStagePacket ==  0 )
 {
 USBCtrlEPAllowStatusStage();
 }
 }

}
#line 1968 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
static void USBStdSetCfgHandler(void)
{
 uint8_t i;


 inPipes[0].info.bits.busy = 1;


 DisableNonZeroEndpoints( 1 );


 memset((void*)&BDT[0], 0x00, sizeof(BDT));


 USBPingPongBufferReset = 1;




 for(i = 0; i < (uint8_t)( 1 +1u); i++)
 {
 ep_data_in[i].Val = 0u;
 ep_data_out[i].Val = 0u;
 }


 memset((void*)&USBAlternateInterface,0x00, 1 );


 USBPingPongBufferReset = 0;

 pBDTEntryIn[0] = (volatile BDT_ENTRY*)&BDT[ 2 ];


 pBDTEntryEP0OutCurrent = (volatile BDT_ENTRY*)&BDT[ 0 ];
 pBDTEntryEP0OutNext = pBDTEntryEP0OutCurrent;


 USBActiveConfiguration = SetupPkt.bConfigurationValue;


 if(USBActiveConfiguration == 0)
 {

 USBDeviceState = ADDRESS_STATE;
 }
 else
 {

  USER_USB_CALLBACK_EVENT_HANDLER(EVENT_CONFIGURED,(void*)&USBActiveConfiguration,1) ;




 USBDeviceState = CONFIGURED_STATE;
 }
}
#line 2043 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
static void USBStdGetDscHandler(void)
{
 if(SetupPkt.bmRequestType == 0x80)
 {
 inPipes[0].info.Val =  0x00  |  0x80  |  0x40 ;

 switch(SetupPkt.bDescriptorType)
 {
 case  0x01 :



 inPipes[0].pSrc.bRom = (const uint8_t*) &device_dsc ;

 inPipes[0].wCount.Val = sizeof(device_dsc);
 break;
 case  0x02 :



 if(SetupPkt.bDscIndex <  1 )
 {

 inPipes[0].pSrc.bRom = *(USB_CD_Ptr+SetupPkt.bDscIndex);
#line 2074 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 inPipes[0].wCount.byte.LB = *(inPipes[0].pSrc.bRom+2);
 inPipes[0].wCount.byte.HB = *(inPipes[0].pSrc.bRom+3);
 }
 else
 {
 inPipes[0].info.Val = 0;
 }
 break;
 case  0x03 :



 if(SetupPkt.bDscIndex< 3 )
 {

 inPipes[0].pSrc.bRom = *(USB_SD_Ptr+SetupPkt.bDscIndex);

 inPipes[0].wCount.Val = *inPipes[0].pSrc.bRom;
 }
#line 2102 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 else
 {
 inPipes[0].info.Val = 0;
 }
 break;
 default:
 inPipes[0].info.Val = 0;
 break;
 }
 }
}
#line 2129 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
static void USBStdGetStatusHandler(void)
{
 CtrlTrfData[0] = 0;
 CtrlTrfData[1] = 0;

 switch(SetupPkt.Recipient)
 {
 case  ( 0x00 ) :
 inPipes[0].info.bits.busy = 1;
#line 2142 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 if( 0  == 1)
 {
 CtrlTrfData[0]|=0x01;
 }

 if(RemoteWakeup ==  1 )
 {
 CtrlTrfData[0]|=0x02;
 }
 break;
 case  ( 0x01 ) :
 inPipes[0].info.bits.busy = 1;
 break;
 case  ( 0x02 ) :
 inPipes[0].info.bits.busy = 1;
#line 2160 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 {
 BDT_ENTRY *p;

 if(SetupPkt.EPDir == 0)
 {
 p = (BDT_ENTRY*)pBDTEntryOut[SetupPkt.EPNum];
 }
 else
 {
 p = (BDT_ENTRY*)pBDTEntryIn[SetupPkt.EPNum];
 }

 if((p->STAT.UOWN == 1) && (p->STAT.BSTALL == 1))
 CtrlTrfData[0]=0x01;
 break;
 }
 }

 if(inPipes[0].info.bits.busy == 1)
 {
 inPipes[0].pSrc.bRam = (uint8_t*)&CtrlTrfData;
 inPipes[0].info.bits.ctrl_trf_mem =  0x01 ;
 inPipes[0].wCount.v[0] = 2;
 }
}
#line 2202 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
static void USBStallHandler(void)
{
#line 2214 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 if(U1EP0bits.EPSTALL == 1)
 {

 if((pBDTEntryEP0OutCurrent->STAT.Val == _USIE) && (pBDTEntryIn[0]->STAT.Val == (_USIE|_BSTALL)))
 {

 pBDTEntryEP0OutCurrent->STAT.Val = _DAT0|(_DTSEN &  _DTSEN )|_BSTALL;
 pBDTEntryEP0OutCurrent->STAT.Val |= _USIE;
 }
 U1EP0bits.EPSTALL = 0;
 }

 USBClearInterruptFlag(USBStallIFReg,USBStallIFBitNum);
}
#line 2245 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
static void USBSuspend(void)
{
#line 2270 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 USBActivityIE = 1;
 USBClearInterruptFlag(USBIdleIFReg,USBIdleIFBitNum);
#line 2277 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 USBBusIsSuspended =  1 ;
 USBTicksSinceSuspendEnd = 0;
#line 2285 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
  USER_USB_CALLBACK_EVENT_HANDLER(EVENT_SUSPEND,0,0) ;
}
#line 2303 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
static void USBWakeFromSuspend(void)
{
 USBBusIsSuspended =  0 ;
#line 2311 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
  USER_USB_CALLBACK_EVENT_HANDLER(EVENT_RESUME,0,0) ;
#line 2323 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 USBActivityIE = 0;
#line 2343 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 {
 USBClearInterruptFlag(USBActivityIFReg,USBActivityIFBitNum);
 }

 USBTicksSinceSuspendEnd = 0;

}
#line 2372 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
static void USBCtrlEPService(void)
{




 USBStatusStageTimeoutCounter =  (uint8_t)45 ;



 if((USTATcopy.Val & USTAT_EP0_PP_MASK) == USTAT_EP0_OUT_EVEN)
 {










 pBDTEntryEP0OutNext = pBDTEntryEP0OutCurrent;

 pBDTEntryEP0OutNext = (volatile BDT_ENTRY*)(((uintptr_t)pBDTEntryEP0OutNext) ^ USB_NEXT_EP0_OUT_PING_PONG);


 if(pBDTEntryEP0OutCurrent->STAT.PID ==  0xD )
 {




 memcpy((uint8_t*)&SetupPkt, (uint8_t*)ConvertToVirtualAddress(pBDTEntryEP0OutCurrent->ADR), 8);


 USBCtrlTrfSetupHandler();
 }
 else
 {

 USBCtrlTrfOutHandler();
 }
 }
 else if((USTATcopy.Val & USTAT_EP0_PP_MASK) == USTAT_EP0_IN)
 {


 USBCtrlTrfInHandler();
 }

}
#line 2465 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
static void USBCtrlTrfSetupHandler(void)
{



 shortPacketStatus =  0 ;
 USBDeferStatusStagePacket =  0 ;
 USBDeferINDataStagePackets =  0 ;
 USBDeferOUTDataStagePackets =  0 ;
 BothEP0OutUOWNsSet =  0 ;
 controlTransferState =  0 ;








 pBDTEntryIn[0]->STAT.Val &= ~(_USIE);

 pBDTEntryIn[0] = (volatile BDT_ENTRY*)(((uintptr_t)pBDTEntryIn[0]) ^ USB_NEXT_EP0_IN_PING_PONG);
 pBDTEntryIn[0]->STAT.Val &= ~(_USIE);
 pBDTEntryIn[0] = (volatile BDT_ENTRY*)(((uintptr_t)pBDTEntryIn[0]) ^ USB_NEXT_EP0_IN_PING_PONG);
 pBDTEntryEP0OutNext->STAT.Val &= ~(_USIE);

 inPipes[0].info.Val = 0;
 inPipes[0].wCount.Val = 0;
 outPipes[0].info.Val = 0;
 outPipes[0].wCount.Val = 0;





 USBCheckStdRequest();
  USER_USB_CALLBACK_EVENT_HANDLER(EVENT_EP0_REQUEST,0,0) ;
#line 2514 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 USBCtrlEPServiceComplete();
}
#line 2538 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
static void USBCtrlTrfOutHandler(void)
{
 if(controlTransferState ==  2 )
 {
 USBCtrlTrfRxService();
 }
 else
 {


 controlTransferState =  0 ;






 if(BothEP0OutUOWNsSet ==  0 )
 {
 pBDTEntryEP0OutNext->CNT =  8 ;
 pBDTEntryEP0OutNext->ADR = ConvertToPhysicalAddress(&SetupPkt);
 pBDTEntryEP0OutNext->STAT.Val = _DAT0|(_DTSEN &  _DTSEN )|_BSTALL;
 pBDTEntryEP0OutNext->STAT.Val |= _USIE;
 }
 else
 {
 BothEP0OutUOWNsSet =  0 ;
 }
 }
}
#line 2592 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
static void USBCtrlTrfInHandler(void)
{
 uint8_t lastDTS;

 lastDTS = pBDTEntryIn[0]->STAT.DTS;


 pBDTEntryIn[0] = (volatile BDT_ENTRY*)(((uintptr_t)pBDTEntryIn[0]) ^ USB_NEXT_EP0_IN_PING_PONG);




 if(USBDeviceState == ADR_PENDING_STATE)
 {
 U1ADDR = (SetupPkt.bDevADR & 0x7F);
 if(U1ADDR != 0u)
 {
 USBDeviceState=ADDRESS_STATE;
 }
 else
 {
 USBDeviceState=DEFAULT_STATE;
 }
 }


 if(controlTransferState ==  1 )
 {
 pBDTEntryIn[0]->ADR = ConvertToPhysicalAddress(CtrlTrfData);
 USBCtrlTrfTxService();





 if(shortPacketStatus ==  2 )
 {


 pBDTEntryIn[0]->STAT.Val = _BSTALL;
 pBDTEntryIn[0]->STAT.Val |= _USIE;
 }
 else
 {
 if(lastDTS == 0)
 {
 pBDTEntryIn[0]->STAT.Val = _DAT1|(_DTSEN &  _DTSEN );
 pBDTEntryIn[0]->STAT.Val |= _USIE;
 }
 else
 {
 pBDTEntryIn[0]->STAT.Val = _DAT0|(_DTSEN &  _DTSEN );
 pBDTEntryIn[0]->STAT.Val |= _USIE;
 }
 }
 }
 else
 {



 if(outPipes[0].info.bits.busy == 1)
 {
 if(outPipes[0].pFunc !=  ((void *)0) )
 {
 outPipes[0].pFunc();
 }
 outPipes[0].info.bits.busy = 0;
 }

 controlTransferState =  0 ;


 }

}
#line 2686 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
static void USBCheckStdRequest(void)
{
 if(SetupPkt.RequestType !=  ( 0x00 >>5) ) return;

 switch(SetupPkt.bRequest)
 {
 case  5 :
 inPipes[0].info.bits.busy = 1;
 USBDeviceState = ADR_PENDING_STATE;

 break;
 case  6 :
 USBStdGetDscHandler();
 break;
 case  9 :
 USBStdSetCfgHandler();
 break;
 case  8 :
 inPipes[0].pSrc.bRam = (uint8_t*)&USBActiveConfiguration;
 inPipes[0].info.bits.ctrl_trf_mem =  0x01 ;
 inPipes[0].wCount.v[0] = 1;
 inPipes[0].info.bits.busy = 1;
 break;
 case  0 :
 USBStdGetStatusHandler();
 break;
 case  1 :
 case  3 :
 USBStdFeatureReqHandler();
 break;
 case  10 :
 inPipes[0].pSrc.bRam = (uint8_t*)&USBAlternateInterface[SetupPkt.bIntfID];
 inPipes[0].info.bits.ctrl_trf_mem =  0x01 ;
 inPipes[0].wCount.v[0] = 1;
 inPipes[0].info.bits.busy = 1;
 break;
 case  11 :
 inPipes[0].info.bits.busy = 1;
 USBAlternateInterface[SetupPkt.bIntfID] = SetupPkt.bAltID;
 break;
 case  7 :
  USER_USB_CALLBACK_EVENT_HANDLER(EVENT_SET_DESCRIPTOR,0,0) ;
 break;
 case  12 :
 default:
 break;
 }
}
#line 2754 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
static void USBStdFeatureReqHandler(void)
{
 BDT_ENTRY *p;
 EP_STATUS current_ep_data;



 unsigned char* pUEP;
#line 2799 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 if((SetupPkt.bFeature ==  1 )&&
 (SetupPkt.Recipient ==  ( 0x00 ) ))
 {
 inPipes[0].info.bits.busy = 1;
 if(SetupPkt.bRequest ==  3 )
 RemoteWakeup =  1 ;
 else
 RemoteWakeup =  0 ;
 }


 if((SetupPkt.bFeature ==  0 )&&
 (SetupPkt.Recipient ==  ( 0x02 ) )&&
 (SetupPkt.EPNum != 0) && (SetupPkt.EPNum <=  1 )&&
 (USBDeviceState == CONFIGURED_STATE))
 {


 inPipes[0].info.bits.busy = 1;


 if(SetupPkt.EPDir ==  0 )
 {
 p = (BDT_ENTRY*)pBDTEntryOut[SetupPkt.EPNum];
 current_ep_data.Val = ep_data_out[SetupPkt.EPNum].Val;
 }
 else
 {
 p = (BDT_ENTRY*)pBDTEntryIn[SetupPkt.EPNum];
 current_ep_data.Val = ep_data_in[SetupPkt.EPNum].Val;
 }





 if(current_ep_data.bits.ping_pong_state == 0)
 {
 p = (BDT_ENTRY*)(((uintptr_t)p) & (~USB_NEXT_PING_PONG));
 }
 else
 {
 p = (BDT_ENTRY*)(((uintptr_t)p) | USB_NEXT_PING_PONG);
 }




 if(SetupPkt.EPDir ==  0 )
 {
 pBDTEntryOut[SetupPkt.EPNum] = (volatile BDT_ENTRY *)p;
 }
 else
 {
 pBDTEntryIn[SetupPkt.EPNum] = (volatile BDT_ENTRY *)p;
 }


 if(SetupPkt.bRequest ==  3 )
 {
 if(p->STAT.UOWN == 1)
 {


 if(SetupPkt.EPDir ==  0 )
 {
 ep_data_out[SetupPkt.EPNum].bits.transfer_terminated = 1;
 }
 else
 {
 ep_data_in[SetupPkt.EPNum].bits.transfer_terminated = 1;
 }
 }


 p->STAT.Val |= _BSTALL;
 p->STAT.Val |= _USIE;
 }
 else
 {



 p = (BDT_ENTRY*)(((uintptr_t)p) ^ USB_NEXT_PING_PONG);

 if(p->STAT.UOWN == 1)
 {


 p->STAT.Val &= (~_USIE);
 p->STAT.Val |= _DAT1;
  USER_USB_CALLBACK_EVENT_HANDLER(EVENT_TRANSFER_TERMINATED,p,sizeof(p)) ;
 }
 else
 {

 p->STAT.Val |= _DAT1;
 }



 p = (BDT_ENTRY*)(((uintptr_t)p) ^ USB_NEXT_PING_PONG);





 if((current_ep_data.bits.transfer_terminated != 0) || (p->STAT.UOWN == 1))
 {
 if(SetupPkt.EPDir ==  0 )
 {
 ep_data_out[SetupPkt.EPNum].bits.transfer_terminated = 0;
 }
 else
 {
 ep_data_in[SetupPkt.EPNum].bits.transfer_terminated = 0;
 }

 p->STAT.Val &= ~(_USIE | _DAT1 | _BSTALL);


  USER_USB_CALLBACK_EVENT_HANDLER(EVENT_TRANSFER_TERMINATED,p,sizeof(p)) ;
 }
 else
 {

 p->STAT.Val &= ~(_USIE | _DAT1 | _BSTALL);
 }
#line 2973 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 pUEP = (unsigned char*)(&U1EP0+SetupPkt.EPNum);



 *pUEP &= ~UEP_STALL;
 }
 }
}
#line 3025 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
void USBIncrement1msInternalTimers(void)
{






 USB1msTickCount++;
 if( USBBusIsSuspended  ==  0 )
 {
 USBTicksSinceSuspendEnd++;

 if(USBTicksSinceSuspendEnd == 0)
 {
 USBTicksSinceSuspendEnd = 255;
 }
 }
}
#line 3104 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
uint32_t USBGet1msTickCount(void)
{
#line 3120 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_device.c"
 return USB1msTickCount;

}
