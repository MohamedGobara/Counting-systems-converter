/*
* learning.c
*
* Created: 30/10/2022 7:12:38 AM
* Author : Mohamed Hussein
*/

//CTRL + K + D  => FORMAT CODE


#define F_CPU 8000000
#include <util/delay.h>

#include "MemMaph.h"
#include "StdTypes.h"
#include "Utils.h"
#include "SEGMENT_interface.h"
#include "DIO_interface.h"
#include "MOTOR_Interface.h"
#include "LCD_Interface.h"
#include "STEPPER_Interface.h"
#include "ADC_interface.h"
#include "KeyPad_interface.h"
#include "CoSysConverter_interface.h"




int main(void)
{
	
	
	
	DIO_Init() ;
	LCD_Init()  ;
	KeyPad_Init();
	CoSyConverter_Init() ;
	u8 k = NO_KEY ;
	
	Bool_type convertFrom_Skiped = FALSE, convertTo_Skiped = FALSE ;
	CoSyConverter_Systems_types from = -1 , to = -1 ;
	
	u8 num = 0 , str_hex[2] ={0} ;
	u8 str_binary[8]={0} ,  index= 0;

	
	while(1) {
		
		/*************** Start While ********************/
		k = KeyPad_GetKey() ;
		if(convertFrom_Skiped==FALSE&&convertTo_Skiped==FALSE){
			CoSyConverter_FirstScreen() ;
			
		}
		else if(convertFrom_Skiped==TRUE&&convertTo_Skiped==FALSE){
			CoSyConverter_ConvertFromScreen(from) ;
			
		}
		
		if(k!=NO_KEY) {
			
			if(convertFrom_Skiped==FALSE&&convertTo_Skiped==FALSE) {
				CoSyConverter_FirstScreen() ;
				
				if(k>='1'&&k<='3') {
					if (k=='1')
					{
						from=DECIMAL ;
						CoSyConverter_ConvertFromScreen(from) ;
					}
					else if (k=='2')
					{
						from=HEX ;
						
						index =1 ;
						CoSyConverter_ConvertFromScreen(from) ;
					}
					else if (k=='3')
					{
						from=BINARY ;
						index=7 ;

						CoSyConverter_ConvertFromScreen(from) ;
					}
					convertFrom_Skiped=TRUE ;
				}
				
				
				
			}
			
			else if(convertFrom_Skiped==TRUE&&convertTo_Skiped==FALSE) {
				
				if(k>='1'&&k<='2') {
					
					if (k=='1')
					{
						if(from==DECIMAL) {
							to = HEX ;
							
							
						}
						else if (from==HEX)
						{
							to = DECIMAL ;
							
						}
						else if (from==BINARY)
						{
							to = DECIMAL ;

						}
						
						
					}
					else if (k=='2')
					{
						
						if(from==DECIMAL) {
							to = BINARY ;
							
							
						}
						else if (from==HEX)
						{
							to = BINARY ;

						}
						else if (from==BINARY)
						{
							to = HEX ;

						}
						
					}
					
					convertTo_Skiped=TRUE ;
					
					LCD_Clear()  ;
					
				}
				/**********Back to First screen **********/
				else if(k=='='){
					
					from=-1 ;
					to=-1;
					convertFrom_Skiped=FALSE ;
					convertTo_Skiped=FALSE ;
					
				}
				
				
				
				
			}
			
			
			
			/****************** wait user enter number *************/
			else if ( convertFrom_Skiped = TRUE && convertTo_Skiped == TRUE &&k!='=')
			{
				/*********** Decimal Number ********/
				if(from==DECIMAL) {
					
					LCD_WriteChar(k) ;
					num = ASCI_TO_DECIMAL (num,k) ;
					
				}
				
				
				/*********** Hex Number need to conver u8 ********/

				else if(from==HEX) {
					LCD_WriteChar(k) ;
					if(k>='0'&&k<='9') {
						str_hex[index--] = k-'0' ;
					}
					else if(k>='A'&&k<='F') {
						
						if(k=='A') {
							
							str_hex[index--] = 10 ;
						}
						
						else if(k=='B') {
							
							str_hex[index--] = 11 ;
						}
						else if(k=='C') {
							
							str_hex[index--] = 12 ;
						}
						else if(k=='D') {
							
							str_hex[index--] = 13 ;
						}
						else if(k=='E') {
							
							str_hex[index--] = 14 ;
						}
						else if(k=='F') {
							
							str_hex[index--] = 15 ;
						}
					}
					
					
				}
				
				/***********  Binary Number need to conver u8 ********/
				
				else if(from==BINARY) {
					LCD_WriteChar(k) ;
					
					if(k>='0'&&k<='1') {
						str_binary[index--] = k -'0' ;
					}
					
					
				}
				
				
			}
			
			
			else if ( convertFrom_Skiped = TRUE && convertTo_Skiped == TRUE&&k=='=') {
				index = 0 ;
				
				if(from==HEX) {
					
					num = CoSyConverter_ConvertHexToDecimal(str_hex) ;
					
				}
				
				else if(from==BINARY) {
					
					num = CoSyConverter_ConvertBinaryToDecimal(str_binary) ;
					
				}
				
				CoSyConverter_Converter(from,to,num ) ;
				
				
				if(from==HEX) {
					index=1 ; 
				}
				else if(from==BINARY) {
					index=7   ; 
				}
				
				k=KeyPad_GetKey() ; 
				while(k==NO_KEY) {
					
					k=KeyPad_GetKey() ; 
					
				}
				
				/***** back convert to screen  ****/
				if(k=='=') {
					u8 i =0 ; 
					for(i=0 ; i<2 ; i++) {
						
						str_hex[i]=0 ;
					}
					for(i=0 ; i<8 ; i++) {
						
						str_binary[i]=0 ;
					}
				
					
						num =0 ;
						to =-1 ;
						convertFrom_Skiped = TRUE ;
						convertTo_Skiped=FALSE;
						
					
				}
				/*else if (k)
				{
				}*/
			
				
			}
			
			
		}
		
		/*************** End While ********************/
	}
	
	/*************** End Main ********************/

}





