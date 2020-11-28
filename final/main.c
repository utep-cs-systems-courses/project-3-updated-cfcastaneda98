#include <msp430.h>
#include <libTimer.h>
#include "p2switches.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "stateMachines.h"
#include "buzzer.h"

#define LED_GREEN BIT6             // P1.0

short redrawScreen = 1;
char curr_state_machine = 0;
void wdt_c_handler()
{
  static int count = 0;
  count++;
  if(count == 75 && curr_state_machine != 2){
    count = 0;
    redrawScreen = 1;
  }
  if(count == 150 && curr_state_machine == 2){
    count = 0;
    redrawScreen = 1;
  }
}


void main()
{
  P1DIR |= LED_GREEN;/**< Green led on when CPU on */
  P1OUT |= LED_GREEN;
  configureClocks();
  lcd_init();
  p2sw_init(15);
  buzzer_init();

  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);              /**< GIE (enable interrupts) */

  clearScreen(COLOR_BLACK);
  drawString8x12(10,25,"World Select", COLOR_WHITE, COLOR_BLACK);
  drawString11x16(13,50,"Pick one:", COLOR_WHITE, COLOR_BLACK);
  drawString5x7(10,80, "Button 1: World LW", COLOR_GREEN, COLOR_BLACK);
  drawString5x7(10,95, "Button 2: World ATH", COLOR_RED, COLOR_BLACK);
  drawString5x7(10,110, "Button 1: World PT", COLOR_YELLOW, COLOR_BLACK);
  drawString5x7(10,125, "Button 1: World VD", COLOR_PINK, COLOR_BLACK);
  while(1){
    if(redrawScreen){
      redrawScreen = 0;
      curr_state_machine = button_state;
      switch(button_state){
      case 1:
	state_song_zelda();
	break;
      case 2:
	state_song_pokemon();
	break;
      case 3:
	state_song_mario();
	break;
      case 4:
	state_song_kirby();
	break;
      }
    }
    P1OUT &= ~LED_GREEN;/* green off */
    or_sr(0x10);/**< CPU OFF */
    P1OUT |= LED_GREEN;/* green on */
  }
}
