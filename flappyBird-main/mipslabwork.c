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
int current_x = 110;
int current_x2 = 105;
int current_y = 122;
int current_y2 = 127;
int count2 = 0;
int i;
bool alive = true;
int flappy_direction = 0; //1 = neråt , -1 = uppåt , beroende på om man håller in knappen så ska detta ändra, om värdet är större accelererar den. 

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
	
	
    count2 ++;
  if(alive){      //sålänge alive är true så kommer en över och under border ritas och iconen rörsig, sen kollar check_collision om nån av pixlarna på iconen och bordersarna nuddar varandra och då stannar spelet
 
  display_clear();
    draw_border(0);
    draw_border(31);
    draw_icon(flappyrow,flappycol,16);
    if (count2 < 2){
      move_icon(flappyrow, flappycol, flappyrow_border, flappycol_border,16,12,-12,0);
    }
    move_icon(flappyrow, flappycol, flappyrow_border, flappycol_border,16,12,-0,0);
    draw_icon(pipe3_row, pipe3_col,18);
    draw_icon(pipe1_row, pipe1_col,28);
    move_icon(pipe3_row,pipe3_col, pipe3border_row, pipe3border_col,18,10,-0,-1); 
    move_icon(pipe1_row,pipe1_col, pipe1border_row, pipe1border_col,28,15,-0,-1); 
     
    if(check_collisionpipes(pipe3_row,pipe3_col)){ //
    alive = false;
     
    }
	 
  }
      
      // draw_icon(flappyrow,flappycol, 16);
      // move_icon(flappyrow, flappycol, flappyrow_border, flappycol_border,16,12,-0,0); 
      // display_clear();
      // draw_icon(titleslime_row, titleslime_col,178);
      
      // move_titlescrean(titleslime_row, titleslime_col, 178, -flappy_direction, 0);
     
      // draw_icon(pipe3_row, pipe3_col,18);
      // draw_icon(pipe1_row, pipe1_col,28);

      

      
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
