#include <stdio.h>
#include "mips_sim.h"

void print_buf(int buf[])
{
	int i;

	for(i = 0; i < 32; ++i)
	{
		printf("%i", buf[i]);
	}
	printf("\n");
}

struct node* newNode(char* data)
{
	struct node *node = (struct node*) malloc(sizeof(struct node));

	node->data = data;
	node->right = NULL;
	node->left = NULL;

	return node;
}

void build_R_tree()
{
	/*
	*The purpose of this tree is to make
	*look up operations for the instructions 
	*faster at the cost of the overhead to create 
	*the tree
	*/

	;
}

void build_I_tree()
{
	;
}

void 