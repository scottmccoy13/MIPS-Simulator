#include <stdio.h>
#include "mips_sim.h"

int main(void)
{
	//DECLARATIONS
	int c;
	int i;
	int LINE_BUFFER[32]; //lowest index is the leftmost digit
	FILE *fp; //pointer to input file
	

	//INITIALIZATIONS
	for(i = 0; i < 32; ++i)
	{
		LINE_BUFFER[i] = 0;
	}

	fp = fopen("input.txt", "r");

	//MAIN LOOP
	//read input from file
	i = 0;
	if(fp)
	{
		while((c = getc(fp)) != EOF)
		{
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
					printf("ERROR IN FILE READ\n");
				}
				i += 1;
			}
			else
			{
				//if we are here then we have reached a new line
				print_buf(LINE_BUFFER);
				i = 0;
				LINE_BUFFER[i] = c;
			}
		}
		print_buf(LINE_BUFFER);
		fclose(fp);
	}



	return 0;
}