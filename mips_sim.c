#include <stdio.h>
#include "mips_sim.h"

void print_buf(int buf[])
{
	int i;

	for(i = 0; i < 32; ++i)
	{
		printf("%i", buf[i]);
	}
}

char check_type(int bytestream[])
{
	//There are three types of instructions: 
	//R type, I type, J type
	//R type will always have 0 as the opcode
	//there are only 2 J type instructions

	//DECLARATION
	bool flag;
	int i;
	int jumpcheck[5];

	//INITIALIZATION
	flag = true;
	for(i = 0; i < 4; i++)
	{
		jumpcheck[i] = 0;
	}
	jumpcheck[4] = 1;


	//FUNCTION BODY
	//R TYPE CHECK
	//check if the opcode is 0
	for(i = 0; i < 6; i++)
	{
		flag = flag && (bytestream[i] == 0) ? (TRUE) : (FALSE);
	}

	if(flag == TRUE)
	{
		return 'R';
	}

	//J TYPE CHECK
	flag = TRUE;
	for(i = 0; i < 5; i++)
	{
		flag = flag && (bytestream[i] == jumpcheck[i]) ? (TRUE) : (FALSE);
	}

	if(flag == TRUE)
	{
		return 'R';
	}

	//MUST BE I TYPE
	return 'I';
}