#include <stdio.h>
#define NUMREGISTERS

//UTILITY FUNCTIONS
void print_buf(int buf[]);
char check_type(int byteStream);

//MAIN DATA STRUCTURE
struct MipsSim {
	int REGISTER[NUMREGISTERS];
};