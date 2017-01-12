#line 1 "C:/Users/matth/MPLABXProjects/Oscar.X/spi_interface.c"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdio.h"
#line 1 "c:/users/matth/mplabxprojects/oscar.x/spi_interface.h"



void InitSPIPins(void);
void ConfigSPIInterrupts(void);
void ConfigSPIPeriph(void);

unsigned char SPIReadWrite(unsigned char);
#line 7 "C:/Users/matth/MPLABXProjects/Oscar.X/spi_interface.c"
void InitSPIPins(void) {
 LATB = 0b00000000;
 TRISB = 0b00100000;

 LATC = 0b00000011;
 TRISC = 0b00000000;

 LATD = 0b00000001;
 TRISD = 0x00000010;
}

void ConfigSPIPeriph(void) {
 SSP1STATbits.CKE = 1;
 SSP1CON1bits.CKP = 0;
 SSP1CON1bits.SSPM = 0b0001;
 SSP1CON1bits.SSPEN = 1;
}

unsigned char SPIReadWrite(unsigned char byte) {
 unsigned char r;
 SSP1BUF = byte;
 while (SSP1STATbits.BF == 0);
 r = SSP1BUF;

 return r;
}
