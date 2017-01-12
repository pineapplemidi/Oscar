#include <xc.h>
#include <stdio.h>
#include <pic18f47j53.h>

#include "spi_interface.h"

void InitSPIPins(void) {    
    LATB = 0b00000000; // Slave Selects will be on PORT C
    TRISB = 0b00100000;
    
    LATC = 0b00000011; // Slave Selects will be on PORT C
    TRISC = 0b00000000; // Slave Selects Set to Logic High; NOT SELECTED
    
    LATD = 0b00000001;
    TRISD = 0x00000010;
}

void ConfigSPIPeriph(void) {
    SSP1STATbits.CKE = 1;
	SSP1CON1bits.CKP = 0;  //SPI mode 0,0
	SSP1CON1bits.SSPM = 0b0001;	//SPI Master - FOSC/8 = 2.5 MHz
	SSP1CON1bits.SSPEN = 1;	//Enable MSSP
}

unsigned char SPIReadWrite(unsigned char byte) {
	unsigned char r;
	SSP1BUF = byte; //transmit byte
	while (SSP1STATbits.BF == 0);  //Wait for tx/rx
	r = SSP1BUF;  //read received byte

	return r;
}
