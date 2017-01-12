#ifndef __SPI_INTERFACE_
#define __SPI_INTERFACE_

void InitSPIPins(void);
void ConfigSPIInterrupts(void);
void ConfigSPIPeriph(void);

unsigned char SPIReadWrite(unsigned char);

#endif

