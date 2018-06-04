#include <stdio.h>
#include "mips_sim.h"

#define PERMS 0666 //RW for owner, group, and others

void print_buf(int buf[])
{
	int i;

	for(i = 0; i < 32; ++i)
	{
		printf("%i", buf[i]);
	}
}
