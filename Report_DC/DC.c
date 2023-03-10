/*
 * Name: DC.c
 * Author: Mahmoud Adel
 * Description: This file contains main information of DC motor
 * Version: v1.0
 * */
 
#include <16F628A.h>
#fuses NOMCLR,NOWDT,NOPROTECT,INTRC_IO
#use delay(clock=4M)

/*************Macros***************/
#define isPressed              FALSE
#define isUnPressed            TRUE
#define US                     PIN_B2
#define DS                     PIN_B4
#define CLOCK_WISE             PIN_B5
#define COUNTER_CLOCK_WISE     PIN_B6
#define limit                  8
#define delay                  5
/***********************************/

int main()
{
      int8 c1=0;
      int8 c2=0;
      int8 c3=0;
      int8 c4=0;
      int8 speed=0;
      
      Port_b_pullups(TRUE);
      
      setup_timer_2 ( T2_DIV_BY_16, 0xFF, 2) ;    //F= 0.25 kHZ
      setup_ccp1(CCP_PWM);
      set_pwm1_duty(32);
      
      output_high(PIN_B0);
      output_low(PIN_B1);
      //set_pwm1_duty(speed+=64);
      
      
      while(TRUE)
      {
            
            //check if the switch of down speed is not pressed
            if(input(US)==isUnPressed)
            {
                     //check if the counter is less than the specific limit
                     if(c1<limit) c1++;
            }
            //The action if the switch is pressed 
            else
            {
                  //check if the counter is equal to the specific limit
                  if(c1==limit)
                  {
                        //looping until reach the maximum speed
                        if(speed<128){
                          set_pwm1_duty(speed+=16);
                        }
                        else{
                           /*Do nothing*/
                        }
                    //ending of if condition    
                  }
                  else{
                     /*Do nothing*/
                  }
                  c1=0;
               //ending of else
             }
         //check if the switch of down speed is not pressed
         if(input(DS)==isUnPressed)
         {
                  //check if the counter is less than the specific limit
                  if(c2<limit) c2++;
         }
         //The action if the switch is pressed 
         else
         {
               //check if the counter is equal to the specific limit
               if(c2==limit)
               {
                     //looping until reach the maximum speed
                     if(speed>0){
                       set_pwm1_duty(speed-=16);
                     }
                     else{
                        /*Do nothing*/
                     }
                 //ending of if condition    
               }
               else{
                  /*Do nothing*/
               }
               c2=0;
            //ending of else
          }
            
         //check if the switch of down speed is not pressed
         if(input(CLOCK_WISE)==isUnPressed)
         {
                  //check if the counter is less than the specific limit
                  if(c3<limit) c3++;
         }
         //The action if the switch is pressed 
         else
         {
               //check if the counter is equal to the specific limit
               if(c3==limit)
               {
                     output_high(PIN_B0);
                     output_low(PIN_B1);
               }
               c3=0;
          }
      
        //check if the switch of up speed is not pressed 
        if(input(COUNTER_CLOCK_WISE)==isUnPressed)
        {
               //check if the counter is less than the specific limit
               if(c4<limit)  c4++;
        }
         //The action if the switch is pressed
         else
         {
               //check if the counter is equal to the specific limit
               if(c4==limit)
               {
                      output_high(PIN_B1);
                      output_low(PIN_B0);
               }
               c4=0;
         }
       //ending of loop
   }
      
      return 0;
}

