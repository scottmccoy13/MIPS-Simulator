#include <stdio.h>
#include "mips_sim.h"

typedef int bool;
#define FALSE 0
#define TRUE 1 	


char check_type(int bytestream[])
{
	/*
	*There are three types of instructions: 
	*R type, I type, J type
	*R type will always have 0 as the opcode
	*there are only 2 J type instructions
	*/
	//DECLARATION
	bool flag;
	int i;
	int jumpcheck[5];

	//INITIALIZATION
	flag = TRUE;
	for(i = 0; i < 4; i++)
	{
		jumpcheck[i] = 0;
	}
	jumpcheck[4] = 1;

	print_buf(bytestream);

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
		return 'J';
	}

	//MUST BE I TYPE
	return 'I';
}

char* check_R_inst(int byteStream[])
{	
	/*
	 *Since the opcode is always 000000 for
	 *R type instructions the instruction type
	 *must be derived from the function code 
	 *given in the last 6 bits of the instruction
	*/

	char* inst;

	//CHECK INSTRUCTION TREE
	
}

char* check_I_inst(int byteStream[])
{
	char* inst;

	//CHECK INSTRUCTION TREE

}

char* check_J_inst(int byteStream[])
{
	/*
	 *There are only two types of J type
	 *instruction and they differ by only 
	 *1 bit so that is all that will be checked
	*/

	char* inst;

	//DETERMINE TYPE
	(byteStream[5] == 0) ? (inst = "J") : (inst = "JAL");

	return inst;
}