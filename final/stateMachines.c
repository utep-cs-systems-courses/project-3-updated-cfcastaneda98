#include <msp430.h>
#include <libTimer.h>
#include "stateMachines.h"
#include "buzzer.h"
#include "led.h"
#include "notes.h"
#include "assemblyZelda.h"
#include "lcdutils.h"
#include "lcddraw.h"

char button_state = 0;
static char state_dim = 0;

static char state_zelda = -1;

static char state_mario = -1;
static char state_buzz_mario = -1;

static char state_pokemon = -1;
static char state_buzz_pokemon = -1;

static char state_kirby = -1;
static char state_buzz_kirby = -1;


short note_assembly(short n){
return 20000000/n;
}
char toggle_off()
{
  static char state = 0;
  char changed = 0;

  switch(state){
  case 0:
    green_on = 0;
    state++;
    changed = 1;
    break;
  case 1:
    green_on = 1;
    state++;
    changed = 1;
    break;
  case 2:
    green_on = 1;
    state = 0;
    changed = 0;
    break;
  }
  return changed;
}
char toggle_on()
{
  static char state = 0;
  char changed = 0;

  switch(state){
  case 0:
    green_on = 1;
    state++;
    changed = 1;
    break;
  case 1:
    green_on = 0;
    state++;
    changed = 1;
    break;
  case 2:
    green_on = 0;
    state = 0;
    changed = 0;
    break;
  }
  return changed;
}
void dim()
{
  switch(state_dim){
  case 0:
    green_on = 1;
    led_changed = 1;
    led_update();
    break;
  case 1:
    led_changed = toggle_off();
    led_update();
    break;
  case 2:
    led_changed = toggle_on();
    led_update();
    break;
  default:
    state_dim = 0;
    break;
  }
}
void changeButtonState(char button_pushed)
{
  button_state = button_pushed;

  state_zelda = -1;

  state_mario = -1;
  state_buzz_mario = -1;

  state_pokemon = -1;
  state_buzz_pokemon = -1;

  state_kirby = -1;
  state_buzz_kirby = -1;

  buzzer_set_period(0);
}
void state_song_zelda()
{
  short note = 0;
  
  switch(state_zelda){
  case 0:
    drawTriangle(63,30,20,COLOR_YELLOW);
    break;
  case 1:
    drawTriangle(33,30,50,COLOR_YELLOW);
    break;
  case 2:
    drawTriangle(93,30,50,COLOR_YELLOW);
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    drawTriangle(63,30,20,COLOR_BROWN);
    break;
  case 7:
    drawTriangle(33,30,50,COLOR_BROWN);
    break;
  case 8:
    drawTriangle(93,30,50,COLOR_BROWN);
    break;
  case 9:
    break;
  case 10:
    break;
  case 11:
    break;
  case 12:
    drawTriangle(63,30,20,COLOR_YELLOW);
    break;
  case 13:
    drawTriangle(33,30,50,COLOR_YELLOW);
    break;
  case 14:
    drawTriangle(93,30,50,COLOR_YELLOW);
    break;
  case 15:
    break;
  case 16:
    break;
  case 17:
    break;
  case 18:
    drawTriangle(63,30,20,COLOR_BROWN);
    break;
  case 19:
    drawTriangle(33,30,50,COLOR_BROWN);
    break;
  case 20:
    drawTriangle(93,30,50,COLOR_BROWN);
    break;
  case 21:
    break;
  case 22:
    break;
  case 23:
    break;
  case 24:
    drawTriangle(63,30,20,COLOR_YELLOW);
    break;
  case 25:
    drawTriangle(33,30,50,COLOR_YELLOW);
    break;
  case 26:
    drawTriangle(93,30,50,COLOR_YELLOW);
    break;
  case 27:
    break;
  case 28:
    break;
  case 29:
    break;
  case 30:
    drawTriangle(63,30,20,COLOR_BROWN);
    break;
  case 31:
    drawTriangle(33,30,50,COLOR_BROWN);
    break;
  case 32:
    drawTriangle(93,30,50,COLOR_BROWN);
    break;
  case 33:
    break;
  default:
    clearScreen(COLOR_GREEN);
    drawString8x12(20,125,"Lost Woods",COLOR_WHITE,COLOR_GREEN);
    state_zelda = -1;
    break;
  }
  note = buzz_song_zelda(state_zelda);
  state_zelda++;
  buzzer_set_period(note);
  state_dim++;
}
void buzz_song_mario()
{
  short note = 0;

  switch(state_buzz_mario){
  case 0:
    note = E;
    break;
  case 1:
    note = E;
    break;
  case 2:
    note = C;
    break;
  case 3:
    note = C;
    break;
  case 4:
    note = G;
    break;
  case 5:
    note = A;
    break;
  case 6:
    note = CNOTE;
    break;
  case 7:
    note = 0;
    break;
  case 8:
    note = CNOTE;
    break;
  case 9:
    note = CNOTE;
    break;
  case 10:
    note = CNOTE;
    break;
  case 11:
    note = A;
    break;
  case 12:
    note = G;
    break;
  case 13:
    note = CNOTE;
    break;
  case 14:
    note = 0;
    break;
  case 15:
    note = CNOTE;
    break;
  case 16:
    note = G;
    break;
  case 17:
    note = E;
    break;
  case 18:
    note = D;
    break;
  case 19:
    note = D;
    break;
  case 20:
    note = G;
    break;
  case 21:
    note = E;
    break;
  case 22:
    note = E;
    break;
  case 23:
    note = E;
    break;
  case 24:
    note = CNOTE;
    break;
  case 25:
    note = CNOTE;
    break;
  case 26:
    note = G;
    break;
  case 27:
    note = A;
    break;
  case 28:
    note = CNOTE;
    break;
  case 29:
    note = 0;
    break;
  case 30:
    note = CNOTE;
    break;
  case 31:
    note = CNOTE;
    break;
  case 32:
    note = A;
    break;
  case 33:
    note = G;
    break;
  case 34:
    note = CNOTE;
    break;
  case 35:
    note = F;
    break;
  case 36:
    note = E;
    break;
  case 37:
    note = D;
    break;
  case 38:
    note = CNOTE;
    break;
  case 39:
    note = CNOTE;
    break;
  case 40:
    note = CNOTE;
    break;
  case 41:
    note = 0;
    break;
  default:
    note = 0;
    state_buzz_mario = -1;
    break;
  }
  state_buzz_mario++;
buzzer_set_period(note);
}
void state_song_mario()
{

  switch(state_mario){
  case 0:
    drawMario(20,70,COLOR_YELLOW);
    break;
  case 1:
    break;
  default:
    clearScreen(COLOR_YELLOW);
    drawString8x12(20,125,"Athletic",COLOR_WHITE,COLOR_YELLOW);
    state_mario = 0;
    break;
  }
  buzz_song_mario();
  state_dim++;
}
void buzz_song_pokemon()
{
  short note = 0;

  switch(state_buzz_pokemon){
   case 0:
    note = G;
    break;
  case 1:
    note = F;
    break;
  case 2:
    note = E;
    break;
  case 3:
    note = D;
    break;
  case 4:
    note = C;
    break;
  case 5:
    note = A;
    break;
  case 6:
    note = B;
    break;
  case 7:
    note = A;
    break;
  case 8:
    note = G;
    break;
  case 9:
    note = G;
    break;
  case 10:
    note = G;
    break;
  case 11:
    note = E;
    break;
  case 12:
    note = CNOTE;
    break;
  case 13:
    note = CNOTE;
    break;
  case 14:
    note = 0;
    break;
  case 15:
    note = CNOTE;
    break;
  case 16:
    note = D;
    break;
  case 17:
    note = E;
    break;
  case 18:
    note = F;
    break;
  case 19:
    note = F;
    break;
  case 20:
    note = F;
    break;
  case 21:
    note = F;
    break;
  case 22:
    note = F;
    break;
  case 23:
    note = B;
    break;
  case 24:
    note = CNOTE;
    break;
  case 25:
    note = D;
    break;
  case 26:
    note = E;
    break;
  case 27:
    note = E;
    break;
  case 28:
    note = E;
    break;
  case 29:
    note = F;
    break;
  case 30:
    note = E;
    break;
  case 31:
    note = D;
    break;
  case 32:
    note = D;
    break;
  case 33:
    note = D;
    break;
  case 34:
    note = D;
    break;
  case 35:
    note = 0;
    break;
  default:
    state_buzz_pokemon = -1;
    note = 0;
    break;
  }

  state_buzz_pokemon++;
buzzer_set_period(note);

}
void state_song_pokemon()
{
  switch(state_pokemon){
  case 0:
    drawPokeball(20,70,COLOR_RED);
    state_pokemon++;
    break;
  case 1:
    drawPokeball(40,30,COLOR_RED);
    state_pokemon++;
    break;
  case 2:
    drawPokeball(60,70,COLOR_RED);
    state_pokemon++;
    break;
  case 3:
    break;
  default:
    state_pokemon = 0;
    drawString8x12(10,110, "Pallet Town",COLOR_WHITE,COLOR_RED);
    clearScreen(COLOR_RED);
    break;
  }
  buzz_song_pokemon();
}

void buzz_song_kirby()
{
  short note = 0;

  switch(state_buzz_kirby){
   case 0:
    note = FSH;
    break;
  case 1:
    note = GSH;
    break;
  case 2:
    note = ASH;
    break;
  case 3:
    note = B;
    break;
  case 4:
    note = ASH;
    break;
  case 5:
    note = B;
    break;
  case 6:
    note = CSH;
    break;
  case 7:
    note = GSH;
    break;
  case 8:
    note = E;
    break;
  case 9:
    note = FSH;
    break;
  case 10:
    note = GSH;
    break;
  case 11:
    note = ASH;
    break;
  case 12:
    note = B;
    break;
  case 13:
    note = ASH;
    break;
  case 14:
    note = B;
    break;
  case 15:
    note = CNOTE;
    break;
  case 16:
    note = CNOTE;
    break;
  case 17:
    note = CNOTE;
    break;
  case 18:
    note = CNOTE;
    break;
  case 19:
    note = CNOTE;
    break;
  case 20:
    note = E;
    break;
  case 21:
    note = E;
    break;
  case 22:
    note = E;
    break;
  case 23:
    note = FSH;
    break;
  case 24:
    note = GSH;
    break;
  case 25:
    note = ASH;
    break;
  case 26:
    note = B;
    break;
  case 27:
    note = ASH;
    break;
  case 28:
    note = B;
    break;
  case 29:
    note = CNOTE;
    break;
  case 30:
    note = CNOTE;
    break;
  case 31:
    note = F;
    break;
  case 32:
    note = GSH;
    break;
  case 33:
    note = E;
    break;
  case 34:
    note = E;
    break;
  case 35:
    note = G;
    break;
  case 36:
    note = F;
    break;
  case 37:
    note = F;
    break;
  case 38:
    note = E;
    break;
  case 39:
    note = D;
    break;
  case 40:
    note = D;
    break;
  case 41:
    note = E;
    break;
  case 42:
    note = CSH;
    break;
  case 43:
    note = CSH;
    break;
  case 44:
    note = CSH;
    break;
  case 45:
    note = CNOTE;
    break;
  case 46:
    note = CNOTE;
    break;
  case 47:
    note = CNOTE;
    break;
  case 48:
    note = 0;
    break;
  default:
    state_buzz_kirby = -1;
    note = 0;
    break;
  }
  state_buzz_kirby++;
  buzzer_set_period(note);
}
void state_song_kirby()
{
  static u_int tree_colorBGR = COLOR_GREEN;

  switch(state_kirby){
  case 0:
    state_kirby++;
    break;
  case 1:
    state_kirby++;
    break;
  case 2:
    state_kirby++;
    break;
  case 3:
    state_kirby = 1;
    break;
  default:
    state_kirby = 0;
    drawString8x12(20,125,"Victory",COLOR_WHITE,COLOR_BLUE);
    clearScreen(COLOR_RED);
    break;
  }
  buzz_song_kirby();
}
