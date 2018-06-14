#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mips_sim.h"
#define BADKEY -1
#define F1 1
#define F2 2

typedef void (*fptr)(int x[]);
typedef struct { char *key; int val;} t_symstruct;

static t_symstruct lookupTable[] = {
	{"ADD", F1}, {"ADDU", F2}
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
	printf("Executing ADD instruction\n");
}

fptr selectInstruction(char* input)
{
	fptr f;
	switch(keyFromString(input))
	{
		case F1:
			return &ADD; 
			break;
		case F2:
			return &ADDU;
			break;

		case BADKEY:
			printf("Failed lookup in selectInstruction\n");
			break;
	}
}