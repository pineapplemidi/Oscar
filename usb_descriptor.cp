#line 1 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_descriptor.c"
#line 1 "c:/users/matth/mplabxprojects/oscar.x/usb.h"
#line 1 "c:/users/matth/mplabxprojects/oscar.x/usb_config.h"
#line 1 "c:/users/matth/mplabxprojects/oscar.x/usb_common.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/limits.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdbool.h"



 typedef char _Bool;
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
#line 151 "C:/Users/matth/MPLABXProjects/Oscar.X/usb_descriptor.c"
const USB_DEVICE_DESCRIPTOR device_dsc=
{
 0x12,
  0x01 ,
 0x0200,
 0x00,
 0x00,
 0x00,
  8 ,
 0x04D8,
 0x0059,
 0x0002,
 0x01,
 0x02,
 0x01,
 0x01
};



const uint8_t configDescriptor1[]={

 0x09,
  0x02 ,
 101,0x00,
 2,
 1,
 0,
  (0x01<<7)  |  (0x01<<6) ,
 50,


 0x09,
  0x04 ,
 0,
 0,
 0,
 1,
 1,
 0,
 0,


 0x09,
 0x24,
 0x01,
 0x00,0x01,
 0x09,0x00,
 0x01,
 0x01,


 0x09,
 0x04,
 0x01,
 0x00,
 0x02,
 0x01,
 0x03,
 0x00,
 0x00,


 0x07,
 0x24,
 0x01,
 0x00,0x01,
 0x41,0x00,


 0x06,
 0x24,
 0x02,
 0x01,
 0x01,
 0x00,


 0x06,
 0x24,
 0x02,
 0x02,
 0x02,
 0x00,


 0x09,
 0x24,
 0x03,
 0x01,
 0x03,
 0x01,
 0x02,
 0x01,
 0x00,


 0x09,
 0x24,
 0x03,
 0x02,
 0x04,
 0x01,
 0x01,
 0x01,
 0x00,


 0x09,
 0x05,
  1  |  0x00 ,
 0x02,
 0x40,0x00,
 0x00,
 0x00,
 0x00,


 0x05,
 0x25,
 0x01,
 0x01,
 0x01,


 0x09,
 0x05,
  1  |  0x80 ,
 0x02,
 0x40,0x00,
 0x00,
 0x00,
 0x00,


 0x05,
 0x25,
 0x01,
 0x01,
 0x03
};



const struct{uint8_t bLength;uint8_t bDscType;uint16_t string[1];}sd000={
sizeof(sd000), 0x03 ,{0x0409
}};


const struct{uint8_t bLength;uint8_t bDscType;uint16_t string[25];}sd001={
sizeof(sd001), 0x03 ,
{'M','i','c','r','o','c','h','i','p',' ',
'T','e','c','h','n','o','l','o','g','y',' ','I','n','c','.'
}};


const struct{uint8_t bLength;uint8_t bDscType;uint16_t string[12];}sd002={
sizeof(sd002), 0x03 ,
{'B','E','R','R','Y','H','I','L','L',' ',' ',' '}};


const uint8_t *const USB_CD_Ptr[]=
{
 (const uint8_t *const)&configDescriptor1
};


const uint8_t *const USB_SD_Ptr[]=
{
 (const uint8_t *const)&sd000,
 (const uint8_t *const)&sd001,
 (const uint8_t *const)&sd002
};
