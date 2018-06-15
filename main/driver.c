#include <stdio.h>
#include "mips_sim.h"
#define  BUFFERSIZE 32

int main(void)
{
	//DECLARATIONS
	int c;  //char read from file
	int i;  //counter
	char t; //type of instruction in the linebuffer (R/I/J)
	char* instruction; //the instruction contained in linebuffer
	int LINE_BUFFER[BUFFERSIZE]; //lowest index is the leftmost digit
	FILE *fp; //pointer to input file

	//INITIALIZATIONS
	for(i = 0; i < BUFFERSIZE; ++i)
	{
		LINE_BUFFER[i] = 0;
		REGISTER[i] = 0;
	}

	fp = fopen("../input/input.txt", "r");

	build_R_tree();
	//build_I_tree();

	//MAIN LOOP
	//read input from file
	i = 0;
	if(fp)
	{
		while((c = getc(fp)) != EOF)
		{
			//POPULATE BUFFER
			if(i < 32)
			{
				//char 0 encoding
				if(c == 48)
				{
					LINE_BUFFER[i] = 0;
				}
				else if(c == 49)
				{
					LINE_BUFFER[i] = 1;
				}
				else
				{
					if(c != '\n')
						printf("ERROR IN FILE READ: char recieved: %c\n", c);
				}
				++i;
			}
			else
			{
				//if we are here then we have reached a new line
				printf("Line recieved: ");
				print_buf(LINE_BUFFER);
				
				//GET INSTRUCTION TYPE
				t = check_type(LINE_BUFFER);
				printf("Type: %c\n", t);


				switch(t)
				{
					case 'R':
						instruction = check_R_inst(LINE_BUFFER);
						printf("Instruction recieved: %s\n\n", instruction);
						break;
					case 'I':
						instruction = check_I_inst(LINE_BUFFER);
						printf("Instruction recieved: %s\n\n", instruction);
						break;
					case 'J':
						instruction = check_J_inst(LINE_BUFFER);
						printf("Instruction recieved: %s\n\n", instruction);
						break;
				}


				//RESET COUNTER AND CONTINUE
				//you may notice that we are dropping a character
				//from the line by reseting the counter and continuting without
				//doing anything with the char recieved in the while statement.
				//this is intentional as this char should just be '\n'
				i = 0;
			}

		}
		fclose(fp);
	}



	return 0;
}