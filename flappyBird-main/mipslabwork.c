/* mipslabwork.c

   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall

   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):

   This file modified 2017-04-31 by Ture Teknolog

   For copyright and licensing, see file COPYING */

#include <stdint.h>  /* Declarations of uint_32 and the like */
#include <pic32mx.h> /* Declarations of system-specific addresses etc */
#include "mipslab.h" /* Declatations for these labs */
#include <stdbool.h>

#define timeP ((80000000 / 256) / 100) // 100 ms
int mytime = 0x5957;
int prime = 1234567;

volatile int *trisE = (volatile int *)0xbf886100;
volatile int* portE = (volatile int*) 0xbf886110;


char textstring[] = "text, more text, and even more text!";
int timeoutcount = 0;
int count = 0;
int offset = 28;
int current_x = 115;
int current_x2 = 111;
int current_y = 122;
int current_y2 = 127;
int count2 = 0;
// int pipes[1] = {draw_quad(24,122--, 32, 127--), draw_quad(0, current_x++, 11, current_x2++) };
 int i;

/* Interrupt Service Routine */
void user_isr(void)
{
  if (IFS(0) & 0x80000)//Check if interrupt is caused by switch 4
  {
    IFS(0) = (IFS(0) & 0xff7fffff);
    count++;
    *portE = (*portE & 0xffffff00) | count;
  }

  if (IFS(0) & 0x100)
  {
    IFSCLR(0) = IFS(0) & 0xffff7fff;
    timeoutcount++;
    if(timeoutcount == 10){
      timeoutcount = 0;
      // time2string(textstring, mytime);
      // display_string(3, textstring);
      // display_update();
      // display_image(96,icon);

      // tick(&mytime);
      // offset = movment(offset);
      // display_update();
      // display_image(offset, icon);
     
      // for(i = 0; i < 2; i++){
      //   count2 ++;
      //   if(count2 == 7){
      //     pipes[i];
      //     // current_x --;
      //     // current_x2 --;

      //     // current_y --;
      //     // current_y2 --;

      //   }
      //   if(i == 1){
      //     i = 0;
      //   }
       
      display_image(0, icon);
      //pipe1
      draw_quad(0, current_x, 11, current_x2);
      current_x --;
      current_x2 --;
      //pipe 2 
      draw_quad(24,current_y, 32, current_y2);
      current_y --;
      current_y2 --;   
    

   }      
  }
}

/* Lab-specific initialization goes here */
void labinit(void)
{
  //Switch 4 interrupt
  *trisE = 0x00 & *trisE;//Sets portE to output, LED lights
  TRISDSET = 0x800; //Sets switch 4 to input
  IPC(4) = 0x7 << 2 | 0x3; //Prioritet
  IEC(0) = (IEC(0) | 0x80000); //Enable switch 4 interrupt


  //Timer2
  TMR2 = 0;          // Initalize timer 2
  T2CONSET = 0x0070; // Set to prescale 1:256
  PR2 = timeP;
  T2CONSET = 0x8000;

  IPCSET(2) = 6;
  IECSET(0) = 0x100;

  enable_interrupt();


  return;
}

/* This function is called repetitively from the main program */
void labwork(void)
{
  prime = nextprime(prime);
  // display_string(0, itoaconv(prime));
  // display_update();

}
