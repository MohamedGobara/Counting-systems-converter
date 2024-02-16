
#ifndef COSYSCONVERTER_INTERFACE_H_H_
#define COSYSCONVERTER_INTERFACE_H_H_


#define F_CPU 8000000
#include <util/delay.h>

#include "StdTypes.h"
#include "KeyPad_interface.h"
#include "LCD_Interface.h"

#include <math.h>


#define ASCI_TO_DECIMAL(r,n)  (r=(r*10)+(n-'0'))



typedef enum {
	DECIMAL ,
	HEX  ,
	BINARY
	
	
	
}CoSyConverter_Systems_types;




void CoSyConverter_Init(void) ; 
	void CoSyConverter_FirstScreen(void) ; 
void CoSyConverter_ConvertFromScreen(CoSyConverter_Systems_types system) ; 
u8 CoSyConverter_Converter( CoSyConverter_Systems_types from , CoSyConverter_Systems_types to,u8 num) ;

u8 CoSyConverter_ConvertHexToDecimal (u8* str_h) ; 

u8 CoSyConverter_ConvertBinaryToDecimal (u8* str_b) ; 

	u16 power(u16 base, u16 exponent) ; 

#endif /* COSYSCONVERTER_INTERFACE_H_H_ */