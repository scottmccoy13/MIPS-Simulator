#include <stdio.h>
#define NUMREGISTERS 32

//UTILITY FUNCTIONS
void print_buf(int buf[]);
void build_R_tree();
void build_I_tree();

//
char check_type(int byteStream[]);
char* check_R_inst(int byteStream[]);
char* check_I_inst(int byteStream[]);
char* check_J_inst(int byteStream[]);

//DATA STRUCTURES
int REGISTER[NUMREGISTERS];
struct node {
	char* data;
	struct node *left;
	struct node *right;
};

struct node *r_tree;
struct node *i_tree;