	.arch msp430g2553       ;initial table 
	.p2align 1,0
	.text			

	
jt:				;references the jump table of jt
	.word case0		;
	.word case1		;
	.word case2		;
	.word case3		;
	.word case4		;
	.word case5		;
	.word case6		;
	.word case7		;
	.word case8		;
	.word case9		;
	.word case10		;
	.word case11		;
	.word case12		;
	.word case13		;
	.word case14		;
	.word case15		;
	.word case16		;
	.word case17		;
	.word case18		;
	.word case19		;
	.word case20		;
	.word case21		;
	.word case22		;
	.word case23		;
	.word case24		;
	.word case25		;
	.word case26		;
	.word case27		;
	.word case28		;
	.word case29		;
	.word case30		;
	.word case31		;
	.word case32            ;
	.word case33		;
	.word default		;

	.extern note_assembly	;
	.global buzz_song_zelda ;
	
buzz_song_zelda:
	SUB #2, R1		;make room in the stack for a short
	MOV #0, 0(R1)		;note = 0
	CMP #0, R12		;state - 0
	JLO default		;state < 0 (signed comparison)
	CMP #34, R12		;state - 34 (34 due to the number of switch statements)
	JC  default		;state >= 34 (as an unsigned comparison)
	ADD R12, R12		;r12 = 2*state
	MOV jt(R12), R0		;jmp jt[state]

case0:				;Notes are from the previous lab
	MOV #0, 0(R1)		;note = 0
	JMP noteConvert		;
case1:
	MOV #286, 0(R1)		;note = F
	JMP noteConvert		;
case2:
	MOV #454, 0(R1)		;note = A
	JMP noteConvert		;
case3:
	MOV #404, 0(R1)		;note = B
	JMP noteConvert		;
case4:
	MOV #404, 0(R1)		;note = B
	JMP noteConvert		;
case5:
	MOV #286, 0(R1)		;note = F
	JMP noteConvert		;
case6:
	MOV #454, 0(R1)		;note = A
	JMP noteConvert		;
case7:
	MOV #404, 0(R1)		;note = B
	JMP noteConvert		;
case8:
	MOV #404, 0(R1)		;note = B
	JMP noteConvert		;
case9:
	MOV #286, 0(R1)		;note = F
	JMP noteConvert		;
case10:
	MOV #454, 0(R1)		;note = A
	JMP noteConvert		;
case11:
	MOV #404, 0(R1)		;note = E
	JMP noteConvert		;
case12:
	MOV #303, 0(R1)		;note = E
	JMP noteConvert		;
case13:
	MOV #340, 0(R1)		;note = D
	JMP noteConvert		;
case14:
	MOV #340, 0(R1)		;note = D
	JMP noteConvert		;
case15:
	MOV #404, 0(R1)		;note = D
	JMP noteConvert		;
case16:
	MOV #381, 0(R1)		;note = B
	JMP noteConvert		;
case17:
	MOV #404, 0(R1)		;note = CNOTE
	JMP noteConvert		;
case18:
	MOV #255, 0(R1)		;note = B
	JMP noteConvert		;
case19:
	MOV #303, 0(R1)		;note = G
	JMP noteConvert		;
case20:
	MOV #303, 0(R1)		;note = E
	JMP noteConvert		;
case21:
	MOV #303, 0(R1)		;note = E
	JMP noteConvert		;
case22:
	MOV #303, 0(R1)		;note = E
	JMP noteConvert		;
case23:
	MOV #303, 0(R1)		;note = E
	JMP noteConvert		;
case24:
	MOV #340, 0(R1)		;note = D
	JMP noteConvert		;
case25:
	MOV #303, 0(R1)		;note = E
	JMP noteConvert		;
case26:
	MOV #255, 0(R1)		;note = G
	JMP noteConvert		;
case27:
	MOV #303, 0(R1)		;note = E
	JMP noteConvert		;
case28:
	MOV #303, 0(R1)		;note = E
	JMP noteConvert		;
case29:
	MOV #303, 0(R1)		;note = E
	JMP noteConvert		;
case30:
	MOV #303, 0(R1)		;note = E
	JMP noteConvert		;
case31:
	MOV #303, 0(R1)		;note = E
	JMP noteConvert		;
case32:
	MOV #303, 0(R1)		;note = E
	JMP noteConvert		;
case33:
	MOV #0, 0(R1)		;note = E
	JMP noteConvert		;
default:
	MOV #0, 0(R1)		;note = 0
	JMP end		        ;
noteConvert:
	MOV 0(R1), R12		;converts a note a short
	CALL #note_assembly	;calls on note_assembly method
	JMP end			;ends conversiom
end:
	ADD #2, R1		;resets stack
	POP R0			;returns
