# makfile configuration
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c
AR		= msp430-eld-ar

all:final.elf

#additional rules for files
final.elf: ${COMMON_OBJECTS} assemblyZelda.o buzzer.o stateMachines.o led.o p2switches.o main.o wdt_handler.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd -lp2sw

load: final.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf *h ~*
