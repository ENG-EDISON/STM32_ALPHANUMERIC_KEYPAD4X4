/*
Library:	              KEYPAD4X4.c
Written by:		      Edison (Edison YouTube Channel)
Date Written:		       Oct 7, 2021
Last modified:
Description:		      This is an STM32 device driver library for the Keypad4X4 alphabets, using STM HAL libraries

										
* Copyright (C) 2021 Edison Ngunjiri
   This is a free software under the GNU license, you can redistribute it and/or modify it under the terms
   of the GNU General Public Licenseversion 3 as published by the Free Software Foundation.
	
   This software library is shared with puplic for educational purposes, without WARRANTY and Author is not liable for any damages caused directly
   or indirectly by this software, read more about this on the GNU General Public License.
*/


#include "KeypadAlphanum.h"
#include "main.h"
#include "stm32f4xx_hal_tim.h"
#include "STM_MY_LCD16X2.h"


extern TIM_HandleTypeDef htim7;

char key;
int tick1[16]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int final=0;
int record=0;

char Get_Alpha(void)
{
    while(1)
    {

        if(final==0)
        {
            HAL_GPIO_WritePin (KC0_GPIO_Port, KC0_Pin, GPIO_PIN_SET);     // Pull the C0 HIGH
            HAL_GPIO_WritePin (KC1_GPIO_Port, KC1_Pin, GPIO_PIN_RESET);   // Pull the C1 LOW
            HAL_GPIO_WritePin (KC2_GPIO_Port, KC2_Pin, GPIO_PIN_RESET);   // Pull the C2 LOW
            HAL_GPIO_WritePin (KC3_GPIO_Port, KC3_Pin, GPIO_PIN_RESET);   // Pull the C3 LOW
            if ((HAL_GPIO_ReadPin (KR0_GPIO_Port, KR0_Pin)))   // if R0 is HIGH
            {
                HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
                while ((HAL_GPIO_ReadPin (KR0_GPIO_Port, KR0_Pin)))
                {
                    HAL_TIM_Base_Start_IT(&htim7);
                };  // wait till the button is pressed

                if(tick1[0]==0)
                {
                    key='A';
                }
                else if(tick1[0]==1)
                {
                    key='B';
                }
                else if(tick1[0]==2)
                {
                    key='C';
                }
                else if(tick1[0]==3)
                {
                    key='1';
                }
                else if(tick1[0]==4)
                {
                    tick1[0]=1;
                }
                tick1[0]++;
            }
            if ((HAL_GPIO_ReadPin (KR1_GPIO_Port, KR1_Pin)))   // if  R1 is HIGH
            {
                HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
                while ((HAL_GPIO_ReadPin (KR1_GPIO_Port, KR1_Pin)))
                {
                    HAL_TIM_Base_Start_IT(&htim7);
                };   // wait till the button is pressed
                if(tick1[1]==0)
                {
                    key='J';
                }
                else if(tick1[1]==1)
                {
                    key='K';
                }
                else if(tick1[1]==2)
                {
                    key='L';
                }
                else if(tick1[1]==3)
                {
                    key='4';
                }
                else if(tick1[1]==4)
                {
                    tick1[1]=0;
                }
                tick1[1]++;
            }
            if ((HAL_GPIO_ReadPin (KR2_GPIO_Port, KR2_Pin)))   // if  R1 is HIGH
            {
                HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
                while ((HAL_GPIO_ReadPin (KR2_GPIO_Port, KR2_Pin)))
                {
                    HAL_TIM_Base_Start_IT(&htim7);
                };   // wait till the button is pressed
                if(tick1[2]==0)
                {
                    key='S';
                }
                else if(tick1[2]==1)
                {
                    key='T';
                }
                else if(tick1[2]==2)
                {
                    key='U';
                }
                else if(tick1[2]==3)
                {
                    key='7';
                }
                else if(tick1[2]==4)
                {
                    tick1[2]=0;
                }
                tick1[2]++;
            }

            if ((HAL_GPIO_ReadPin (KR3_GPIO_Port, KR3_Pin)))   // if R3 is HIGH
            {
                HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
                while ((HAL_GPIO_ReadPin (KR3_GPIO_Port, KR3_Pin)))
                {
                    HAL_TIM_Base_Start_IT(&htim7);
                };   // wait till the button is pressed
                if(tick1[3]==0)
                {
                    key='*';
                }
                if(tick1[3]==1 )
                {
                    tick1[3]=0;
                }
            }
            //COLUMN 2
            HAL_GPIO_WritePin (KC0_GPIO_Port, KC0_Pin, GPIO_PIN_RESET);   // Pull the C0 LOW
            HAL_GPIO_WritePin (KC1_GPIO_Port, KC1_Pin, GPIO_PIN_SET);     // Pull the C1 HIGH
            HAL_GPIO_WritePin (KC2_GPIO_Port, KC2_Pin, GPIO_PIN_RESET);   // Pull the C2 LOW
            HAL_GPIO_WritePin (KC3_GPIO_Port, KC3_Pin, GPIO_PIN_RESET);   // Pull the C3 LOW
            if ((HAL_GPIO_ReadPin (KR0_GPIO_Port, KR0_Pin)))   // if R0 is HIGH
            {
                HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
                while ((HAL_GPIO_ReadPin (KR0_GPIO_Port, KR0_Pin)))
                {
                    HAL_TIM_Base_Start_IT(&htim7);
                };   // wait till the button is pressed
                if(tick1[4]==0)
                {
                    key='D';
                }
                else if(tick1[4]==1)
                {
                    key='E';
                }
                else if(tick1[4]==2)
                {
                    key='F';
                }
                else if(tick1[4]==3)
                {
                    key='2';
                }
                else if(tick1[4]==4)
                {
                    tick1[4]=0;
                }
                tick1[4]++;
            }
            if ((HAL_GPIO_ReadPin (KR1_GPIO_Port, KR1_Pin)))   // if R0 is HIGH
            {

                HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
                while ((HAL_GPIO_ReadPin (KR1_GPIO_Port, KR1_Pin)))
                {
                    HAL_TIM_Base_Start_IT(&htim7);
                };   // wait till the button is pressed
                if(tick1[5]==0)
                {
                    key='M';
                }
                else if(tick1[5]==1)
                {
                    key='N';
                }
                else if(tick1[5]==2)
                {
                    key='0';
                }
                else if(tick1[5]==3)
                {
                    key='5';
                }
                else if(tick1[5]==4)
                {
                    tick1[5]=0;
                }
                tick1[5]++;
            }
            if ((HAL_GPIO_ReadPin (KR2_GPIO_Port, KR2_Pin)))   // if R0 is HIGH
            {
                HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
                while ((HAL_GPIO_ReadPin (KR2_GPIO_Port, KR2_Pin)))
                {
                    HAL_TIM_Base_Start_IT(&htim7);
                };   // wait till the button is pressed
                if(tick1[6]==0)
                {
                    key='V';
                }
                else if(tick1[6]==1)
                {
                    key='W';
                }
                else if(tick1[6]==2)
                {
                    key='X';
                }
                else if(tick1[6]==3)
                {
                    key='8';
                }
                else if(tick1[6]==4)
                {
                    tick1[6]=0;
                }
                tick1[6]++;
            }
            if ((HAL_GPIO_ReadPin (KR3_GPIO_Port, KR3_Pin)))   // if R3 is HIGH
            {
                HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
                while ((HAL_GPIO_ReadPin (KR3_GPIO_Port, KR3_Pin)))
                {
                    HAL_TIM_Base_Start_IT(&htim7);
                };   // wait till the button is pressed
                if(tick1[7]==0)
                {
                    key='0';
                }
                if(tick1[7]==1)
                {
                    key=' ';
                }
								if(tick1[7]==2)
                {
                    tick1[7]=0;
                }
                tick1[7]++;
            }
            //COLUMN 1
            HAL_GPIO_WritePin (KC0_GPIO_Port, KC0_Pin, GPIO_PIN_RESET);  // Pull the C0 LOW
            HAL_GPIO_WritePin (KC1_GPIO_Port, KC1_Pin, GPIO_PIN_RESET);  // Pull the C1 LOW
            HAL_GPIO_WritePin (KC2_GPIO_Port, KC2_Pin, GPIO_PIN_SET);    // Pull the C2 HIGH
            HAL_GPIO_WritePin (KC3_GPIO_Port, KC3_Pin, GPIO_PIN_RESET);  // Pull the C3 LOW
            if ((HAL_GPIO_ReadPin (KR0_GPIO_Port, KR0_Pin)))   // if R0 is HIGH
            {
                HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
                while ((HAL_GPIO_ReadPin (KR0_GPIO_Port, KR0_Pin)))
                {
                    HAL_TIM_Base_Start_IT(&htim7);
                };   // wait till the button is pressed
                if(tick1[8]==0)
                {
                    key='G';
                }
                else if(tick1[8]==1)
                {
                    key='H';
                }
                else if(tick1[8]==2)
                {
                    key='I';
                }
                else if(tick1[8]==3)
                {
                    key='3';
                }
                else if(tick1[8]==4)
                {
                    tick1[8]=0;
                }
                tick1[8]++;
            }
            if ((HAL_GPIO_ReadPin (KR1_GPIO_Port, KR1_Pin)))   // if R0 is HIGH
            {
                HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
                while ((HAL_GPIO_ReadPin (KR1_GPIO_Port, KR1_Pin)))
                {
                    HAL_TIM_Base_Start_IT(&htim7);
                };   // wait till the button is pressed
                if(tick1[9]==0)
                {
                    key='P';
                }
                else if(tick1[9]==1)
                {
                    key='Q';
                }
                else if(tick1[9]==2)
                {
                    key='R';
                }
                else if(tick1[9]==3)
                {
                    key='6';
                }
                else if(tick1[9]==4)
                {
                    tick1[9]=0;
                }
                tick1[9]++;
            }
            if ((HAL_GPIO_ReadPin (KR2_GPIO_Port, KR2_Pin)))   // if R0 is HIGH
            {
                HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
                while ((HAL_GPIO_ReadPin (KR2_GPIO_Port, KR2_Pin)))
                {
                    HAL_TIM_Base_Start_IT(&htim7);
                };   // wait till the button is pressed
                if(tick1[10]==0)
                {
                    key='Y';
                }
                else if(tick1[10]==1)
                {
                    key='Z';
                }
                else if(tick1[10]==2)
                {
                    key='9';
                }
                else if(tick1[10]==3)
                {
                    tick1[10]=0;
                }
                tick1[10]++;
            }
            if ((HAL_GPIO_ReadPin (KR3_GPIO_Port, KR3_Pin)))   // if R3 is HIGH
            {
                HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
                while ((HAL_GPIO_ReadPin (KR3_GPIO_Port, KR3_Pin)))
                {
                    HAL_TIM_Base_Start_IT(&htim7);
                };   // wait till the button is pressed
                if(tick1[11]==0)
                {
                    key='#';
                }
                if(tick1[11]==1)
                {
                    tick1[11]=0;
                }
                tick1[11]++;
            }
            HAL_GPIO_WritePin (KC0_GPIO_Port, KC0_Pin, GPIO_PIN_RESET);   // Pull the C0 LOW
            HAL_GPIO_WritePin (KC1_GPIO_Port, KC1_Pin, GPIO_PIN_RESET);   // Pull the C1 LOW
            HAL_GPIO_WritePin (KC2_GPIO_Port, KC2_Pin, GPIO_PIN_RESET);   // Pull the C2 LOW
            HAL_GPIO_WritePin (KC3_GPIO_Port, KC3_Pin, GPIO_PIN_SET);     // Pull the C3 HIGH
            if ((HAL_GPIO_ReadPin (KR0_GPIO_Port, KR0_Pin)))   // if R0 is HIGH
            {
                HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
                while ((HAL_GPIO_ReadPin (KR0_GPIO_Port, KR0_Pin)))
                {
                    HAL_TIM_Base_Start_IT(&htim7);
                };   // wait till the button is pressed
                if(tick1[12]==0)
                {
                    key='A';
                }
                if(tick1[8]==1)
                {
                    tick1[12]=0;
                }
                tick1[12]++;
            }
            if ((HAL_GPIO_ReadPin (KR1_GPIO_Port, KR1_Pin)))   // if R0 is HIGH
            {
                HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
                while ((HAL_GPIO_ReadPin (KR1_GPIO_Port, KR1_Pin)))
                {
                    HAL_TIM_Base_Start_IT(&htim7);
                };   // wait till the button is pressed
                if(tick1[13]==0)
                {
                    key='B';
                }
                if(tick1[13]==1)
                {
                    tick1[13]=0;
                }
                tick1[13]++;
            }
            if ((HAL_GPIO_ReadPin (KR2_GPIO_Port, KR2_Pin)))   // if R0 is HIGH
            {
                HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
                while ((HAL_GPIO_ReadPin (KR2_GPIO_Port, KR2_Pin)))
                {
                    HAL_TIM_Base_Start_IT(&htim7);
                };   // wait till the button is pressed
                if(tick1[14]==0)
                {
                    key='C';
                }

                if(tick1[14]==1)
                {
                    tick1[14]=0;
                }
                tick1[14]++;
            }
            if ((HAL_GPIO_ReadPin (KR3_GPIO_Port, KR3_Pin)))   // if R3 is HIGH
            {
                HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
                while ((HAL_GPIO_ReadPin (KR3_GPIO_Port, KR3_Pin)))
                {
                    HAL_TIM_Base_Start_IT(&htim7);
                };   // wait till the button is pressed
                if(tick1[15]==0)
                {
                    key='D';
                }
                if(tick1[15]==1)
                {
                    tick1[15]=0;
                }
                tick1[15]++;
            }
						HAL_Delay(200);
        }


        else
        {
					final=0;
            if(record==1)
            {

                HAL_Delay(100);
								 return key;
            }
						else
						{
            record=1;
						}

        }
    }

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
		for(int k=0; k<16; k++)
		{
			tick1[k]=0;
		}
    if(final==0)
    {
				HAL_TIM_Base_Stop_IT(&htim7);
        final=1;
    }
		HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_6);
}


