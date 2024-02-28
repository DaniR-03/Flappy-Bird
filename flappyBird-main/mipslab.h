/* mipslab.h
   Header file for all labs.
   This file written 2015 by F Lundevall
   Some parts are original code written by Axel Isaksson

   Latest update 2015-08-28 by F Lundevall

   For copyright and licensing, see file COPYING */

/* Declare display-related functions from mipslabfunc.c */
#include <stdbool.h>

void display_image(int x, const uint8_t *data);
void display_pixel(int row, int col, int val);
void draw_pixel(int x, int y);
void draw_quad(int x1, int y1, int x2, int y2);
void draw_icon(uint8_t* data_row, uint8_t* data_col, int size);
void move_icon(uint8_t* data_row, uint8_t* data_col, uint8_t* border_row, uint8_t* border_col,int iconsize, int bordersize, int rowmovment, int colmovment);
void move_titlescrean(uint8_t* data_row, uint8_t* data_col, int size, int rowmovement, int colmovment);
void display_init(void);
void display_string(int line, char *s);
void display_update(void);
bool check_collision(void);
bool check_collisionpipes(uint8_t* piperow, uint8_t* pipecol);
void display_clear(void);
void draw_border(int row);
uint8_t spi_send_recv(uint8_t data);

/* Declare lab-related functions from mipslabfunc.c */
char * itoaconv( int num );
void labwork(void);
int nextprime( int inval );
void quicksleep(int cyc);
void tick( unsigned int * timep );

/* Declare display_debug - a function to help debugging.

   After calling display_debug,
   the two middle lines of the display show
   an address and its current contents.

   There's one parameter: the address to read and display.

   Note: When you use this function, you should comment out any
   repeated calls to display_image; display_image overwrites
   about half of the digits shown by display_debug.
*/
void display_debug( volatile int * const addr );

/* Declare bitmap array containing font */
extern const uint8_t const font[128*8];
/* Declare bitmap array containing icon */
extern const uint8_t const icon[512];


const uint8_t flappy_size;
const uint8_t flappyborder_size;
extern uint8_t flappyrow[16];
extern uint8_t flappycol[16];

extern uint8_t flappyrow_border[12];
extern uint8_t flappycol_border[12];
//pipes
extern uint8_t pipe1_row[28];
extern uint8_t pipe1_col[28];
extern uint8_t pipe2_row[26];
extern uint8_t pipe2_col[26];
extern uint8_t pipe3_row[18];
extern uint8_t pipe3_col[18];
extern uint8_t pipe4_row[26];
extern uint8_t pipe4_col[26];

extern uint8_t pipe1border_row[15]; 
extern uint8_t pipe1border_col[15]; 
extern uint8_t pipe2border_row[14]; 
extern uint8_t pipe2border_col[14]; 
extern uint8_t pipe3border_row[10]; 
extern uint8_t pipe3border_col[10]; 
extern uint8_t pipe4border_row[14]; 
extern uint8_t pipe4border_col[14]; 

extern uint8_t titleslime_row[178];
extern uint8_t titleslime_col[178];


extern const int decimalPosToBinary[8];
/* Declare text buffer for display output */
extern char textbuffer[4][16];

/* Declare functions written by students.
   Note: Since we declare these functions here,
   students must define their functions with the exact types
   specified in the laboratory instructions. */
/* Written as part of asm lab: delay, time2string */
void delay(int);
void time2string( char *, int );
/* Written as part of i/o lab: getbtns, getsw, enable_interrupt */
int getbtns(void);
int getsw(void);
void enable_interrupt(void);
