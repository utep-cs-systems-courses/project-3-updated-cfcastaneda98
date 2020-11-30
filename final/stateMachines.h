#ifndef stateMachine_included
#define stateMachine_included

extern char button_state;
void dim();
void changeButtonState(char button_pushed);
void state_song_zelda();
void state_song_mario();
void state_song_pokemon();
void state_song_kirby();
#endif //included
