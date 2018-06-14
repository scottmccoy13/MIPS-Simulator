#include <stdio.h>
#define NUMREGISTERS 32
typedef void (*fptr)(int x[]);

//UTILITY FUNCTIONS
void print_buf(int buf[]);
void build_R_tree();
void build_I_tree();
struct node* newNode(void);

//TYPE CHECKING FUNCTIONS
char check_type(int byteStream[]);
char* check_R_inst(int byteStream[]);
char* check_I_inst(int byteStream[]);
char* check_J_inst(int byteStream[]);
fptr selectInstruction(char* input);

//DATA STRUCTURES
int REGISTER[NUMREGISTERS];
struct node {
	void (*fptr)(int x[]);
	struct node *left;
	struct node *right;
};

struct node *r_tree_root;
struct node *i_tree_root;

//INSTRUCTION FUNCTIONS	

void ADD(int x[]);
void ADDU(int x[]);