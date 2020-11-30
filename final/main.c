#include <msp430.h>
#include <libTimer.h>
#include "p2switches.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "stateMachines.h"
#include "buzzer.h"

#define LED_RED BIT6             // P1.0

short redrawScreen = 1;
char curr_state_machine = 0;

void wdt_c_handler()
{
  static int blink_count = 0;
  blink_count++;
  
  if(blink_count == 60 && curr_state_machine != 4){
    dim();
    blink_count = 0;
    redrawScreen = 1;
  }
  if(blink_count == 50 && curr_state_machine == 1){
    blink_count = 0;
    redrawScreen = 1;
  }
  if(blink_count == 30 && curr_state_machine == 2){
    blink_count = 0;
    redrawScreen = 1;
  }
  if(blink_count == 60 && curr_state_machine == 3){
    blink_count = 0;
    redrawScreen = 1;
  }
  if(blink_count == 30 && curr_state_machine == 4){
    blink_count = 0;
    redrawScreen = 1;
  }
}

void main()
{
  P1DIR |= LED_RED;/**< Red led on when CPU on */
  P1OUT |= LED_RED;//Red blinks as we are using the new model of the MSP430
  configureClocks();
  lcd_init();
  p2sw_init(15);
  buzzer_init();

  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);              /**< GIE (enable interrupts) */

  clearScreen(COLOR_BLACK);
  drawString8x12(10,25, "World Select", COLOR_WHITE, COLOR_BLACK);
  drawString11x16(13,50,"Pick one:", COLOR_WHITE, COLOR_BLACK);
  drawString5x7(10,80,  "Button 1: World LW", COLOR_GREEN, COLOR_BLACK);
  drawString5x7(10,95,  "Button 2: World ATH", COLOR_RED, COLOR_BLACK);
  drawString5x7(10,110, "Button 3: World PT", COLOR_YELLOW, COLOR_BLACK);
  drawString5x7(10,125, "Button 4: World VD", COLOR_PINK, COLOR_BLACK);
  while(1){
    if(redrawScreen){
      redrawScreen = 0;
      curr_state_machine = button_state;
      switch(button_state){
      case 1:
	state_song_zelda();
	break;
      case 2:
	state_song_mario();
	break;
      case 3:
	state_song_pokemon();
	break;
      case 4:
	state_song_kirby();
	break;
      }
    }
    P1OUT &= ~LED_RED;/* red off */
    or_sr(0x10);/**< CPU OFF */
    P1OUT |= LED_RED;/* red on */
  }
}
