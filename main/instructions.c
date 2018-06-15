#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mips_sim.h"
#define BADKEY -1
#define F1 1
#define F2 2
#define F3 3
#define F4 4
#define F5 5
#define F6 6
#define F7 7
#define F8 8
#define F9 9
#define F10 10
#define F11 11
#define F12 12
#define F13 13
#define F14 14
#define F15 15
#define F16 16 
#define F17 17
#define F18 18
#define F19 19
#define F20 20
#define F21 21
#define F22 22

typedef void (*fptr)(int x[]);
typedef struct { char *key; int val;} t_symstruct;

static t_symstruct lookupTable[] = {
	{"ADD", F1}, {"ADDU", F2}, {"AND", F3}, {"DIV", F4},
	{"DIVU", F5}, {"MFHI", F6}, {"MFLO", F7}, {"MULT", F8},
	{"MULTU", F9}, {"OR", F10}, {"SLL", F11}, {"SLLV", F12},
	{"SLT", F13}, {"SLTU", F14}, {"SRA", F15}, {"SRL", F16},
	{"SRLV", F17}, {"SUB", F18}, {"SUBU", F19}, {"SYSCALL", F20}, 
	{"XOR", F21}, {"JR", F22}
};

#define NUMKEYS (sizeof(lookupTable) / sizeof(t_symstruct))

int keyFromString(char* key)
{
	int i;
	for(i = 0; i < NUMKEYS; i++)
	{
		t_symstruct *sym = lookupTable + (i * sizeof(t_symstruct));
		if(strcmp(sym->key, key) == 0)
		{
			return sym->val;
		}
	}
	return BADKEY;
}

void ADD(int x[])
{
	printf("Executing ADD instruction\n");
}

void ADDU(int x[])
{
	printf("Executing ADDU instruction\n");
}

void AND(int x[])
{
	printf("Executing AND instruction\n");
}

void DIV(int x[])
{
	printf("Executing DIV instruction\n");
}

void DIVU(int x[])
{
	printf("Executing DIVU instruction\n");
}

void MFHI(int x[])
{
	printf("Executing MFHI instruction\n");
}

void MFLO(int x[])
{
	printf("Executing MFLO instruction\n");
}

void MULT(int x[])
{
	printf("Executing MULT instruction\n");
}

void MULTU(int x[])
{
	printf("Executing MULTU instruction\n");
}

void OR(int x[])
{
	printf("Executing OR instruction\n");
}

void SLL(int x[])
{
	printf("Executing SLL instruction\n");
}

void SLLV(int x[])
{
	printf("Executing SLLV instruction\n");
}

void SLT(int x[])
{
	printf("Executing SLT instruction\n");
}

void SLTU(int x[])
{
	printf("Executing SLTU instruction\n");
}

void SRA(int x[])
{
	printf("Executing SRA instruction\n");
}

void SRL(int x[])
{
	printf("Executing SRL instruction\n");
}

void SRLV(int x[])
{
	printf("Executing SRLV instruction\n");
}

void SUB(int x[])
{
	printf("Executing SUB instruction\n");
}

void SUBU(int x[])
{
	printf("Executing SUBU instruction\n");
}

void SYSCALL(int x[])
{
	printf("Executing SYSCALL instruction\n");
}

void XOR(int x[])
{
	printf("Executing XOR instruction\n");
}

void JR(int x[])
{
	printf("Executing JR instruction\n");
}

fptr selectInstruction(char* input)
{
	fptr f;
	printf("Name recieved: %s\n", input);
	switch(keyFromString(input))
	{
		case F1:
			return &ADD; 
			break;
		case F2:
			return &ADDU;
			break;
		case F3:
			return &AND;
			break;
		case F4:
			return &DIV;
			break;
		case F5:
			return &DIVU;
			break;
		case F6:
			return &MFHI;
			break;
		case F7:
			return &MFLO;
			break;
		case F8:
			return &MULT;
			break;
		case F9:
			return &MULTU;
			break;
		case F10:
			return &OR;
			break;
		case F11:
			return &SLL;
			break;
		case F12:
			return &SLLV;
			break;
		case F13:
			return &SLT;
			break;
		case F14:
			return &SLTU;
			break;
		case F15:
			return &SRA;
			break;
		case F16:
			return &SRL;
			break;
		case F17:
			return &SRLV;
			break;
		case F18:
			return &SUB;
			break;
		case F19:
			return &SUBU;
			break;
		case F20:
			return &SYSCALL;
			break;
		case F21:
			return &XOR;
			break;
		case F22:
			return &JR;
			break;
		case BADKEY:
			printf("Failed lookup in selectInstruction\n");
			break;
	}
}