#include "CoSysConverter_interface.h"

void CoSyConverter_Init(void) {
	
	
	/************************** Intial Screen ***********************/
	
	u8 str[]="System Converter";
	u8 size  = sizeof(str)/sizeof(str[0]) ;
	u8 j = size-1 ;
	LCD_GoTo(0,0) ;
	LCD_WriteChar(str[j]) ;
	
	
	for (u8 i = 0 ; i<size ;i++)
	{
	j = j-i ;
	//LCD_GoTo(0,0) ;
	//LCD_WriteString("                       ") ;
	LCD_GoTo(0,0) ;

	for(j ; j<size-1 ; j++)
	{
	
	
	LCD_WriteChar(str[j]) ;
	
	}
	_delay_ms(300) ;

	
	}
	
	_delay_ms(1500) ;

	LCD_GoTo(1,0) ;
	LCD_WriteString("Made By:Mohamed") ;
	_delay_ms(2500) ;
	/************************** View Screen ***********************/
		LCD_Clear() ;
	
	
	
	CoSyConverter_FirstScreen();

	}
	
	
	
	void CoSyConverter_FirstScreen(void){
	
	
	LCD_GoTo(0,0);
	LCD_WriteString("Convert From") ;
	LCD_GoTo(1,0) ;
	
	LCD_WriteString("1.D   2.H   3.B") ;

	
	}

	void CoSyConverter_ConvertFromScreen(CoSyConverter_Systems_types system)  {
	
	switch (system) {
	case DECIMAL :
	
	LCD_GoTo(0,0);
	LCD_WriteString("Convert D to") ;
	LCD_GoTo(1,0) ;
	
	LCD_WriteString("1.H         2.B") ;
	
	break;
	case HEX :
	
	LCD_GoTo(0,0);
	LCD_WriteString("Convert H to") ;
	LCD_GoTo(1,0) ;
	
	LCD_WriteString("1.D         2.B") ;
	
	break;
	case BINARY :
	
	LCD_GoTo(0,0);
	LCD_WriteString("Convert B to") ;
	LCD_GoTo(1,0) ;
	
	LCD_WriteString("1.D         2.H") ;
	
	break;
	
	}
	
	
	
	}

u16 power(u16 base, u16 exponent)
{
	u16 result=1;
	for (exponent; exponent>0; exponent--)
	{
		result = result * base;
	}
	return result;
}


u8 CoSyConverter_Converter( CoSyConverter_Systems_types from, CoSyConverter_Systems_types to,u8 num)
{


	if(from==DECIMAL)
	{


		if(to==HEX)
		{
			LCD_GoToClear(1,0,16) ;
			LCD_GoTo(1,0) ;
			LCD_WriteHex(num) ;

		}

		else if(to==BINARY)
		{
			LCD_GoToClear(1,0,16) ;
			LCD_GoTo(1,0) ;

			LCD_WriteBinary(num) ;

		}
	}
	else if(from==HEX)
	{

		if(to==DECIMAL)
		{
			LCD_GoToClear(1,0,16) ;
			LCD_GoTo(1,0) ;

			LCD_WriteNumber(num) ;

		}

		else if(to==BINARY)
		{
			LCD_GoToClear(1,0,16) ;
			LCD_GoTo(1,0) ;

			LCD_WriteBinary(num) ;

		}



	}

	else if(from==BINARY)
	{

		if(to==DECIMAL)
		{
			LCD_GoToClear(1,0,16) ;
			LCD_GoTo(1,0) ;

			LCD_WriteNumber(num) ;

		}

		else if(to==HEX)
		{
			LCD_GoToClear(1,0,16) ;
			LCD_GoTo(1,0) ;

			LCD_WriteHex(num) ;

		}

	}

}

	u8 CoSyConverter_ConvertHexToDecimal (u8* str_h) {
	
	u8 n = 0 ;
	
	for(s8 i = 1  ; i >=0 ;i--) {
	
	n = n + (str_h[i]*pow(16,i)) ;
	
			}
	
	return n ;
	

	}
	
	
	
	
	
	u8 CoSyConverter_ConvertBinaryToDecimal (u8* str_b) {
		
	u16 n = 0 ;
	
	for(u16 i  =0; i <8 ; i++) {
		
		
		n = n + (str_b[i]*(u16)power(2,i)) ;
		
	

	}
	
	return n ;
	

	}
	
	