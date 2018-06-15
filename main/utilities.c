#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mips_sim.h"
#define FCODESIZE 6
#define FNAMESIZE 10

void print_buf(int buf[])
{
	int i;

	for(i = 0; i < 32; ++i)
	{
		printf("%i", buf[i]);
	}
	printf("\n");
}

struct node* newNode(void)
{
	struct node *my_node = (struct node*) malloc(sizeof(struct node));

	my_node->fptr = NULL;
	my_node->right = NULL;
	my_node->left = NULL;

	return my_node;
}

void build_R_tree()
{
	/*
	*The purpose of this tree is to make
	*look up operations for the instructions 
	*faster at the cost of the overhead to create 
	*the tree
	*/

	FILE *fp; //pointer to input file
	struct node *curr;
	char function_name[FNAMESIZE];
	int function_code[FCODESIZE];
	int c;
	int i;
	int j;

	r_tree_root = newNode();
	fp = fopen("../input/r_function_codes.txt", "r");
	i = 0;
	
	for(j = 0; j < FCODESIZE; j++)
	{
		function_code[j] = 0;
	}
	
	function_name[0] = '\0';
	

	if(fp)
	{
		while((c = getc(fp)) != EOF)
		{
			if(i < 6)
			{
				//extract function code from line
				if(c == 48)
				{
					printf("%c", c);
					function_code[i] = 0;
					++i;
				}
				else if(c == 49)
				{
					printf("%c", c);
					function_code[i] = 1;
					++i;
				}
			}
			else
			{
				printf("\n");
				j = 0;
				function_name[0] = '\0';
				//extract data from line
				printf("Function name: ");
				while((c = getc(fp)) != ';')
				{
					if(c != ':')
					{
						printf("%c", c);
						function_name[j] = c;
						++j;
					}
				}
				function_name[j] = '\0';
				printf("\n");

				//insert into tree
				curr = r_tree_root;
				for(j = 0; j < 6; ++j)
				{
					if(function_code[j] == 0)
					{
						if(j == 5)
						{
							curr->left = newNode();
							curr = curr->left;
							curr->fptr = selectInstruction(function_name);
						}
						else
						{
							curr->left = newNode();
							curr = curr->left;
						}
					}
					else if(function_code[j] == 1)
					{
						if(j == 5)
						{
							curr->right = newNode();
							curr = curr->right;
							curr->fptr = selectInstruction(function_name);
						}
						else
						{
							curr->right = newNode();
							curr = curr->right;
						}
					}
					else
					{
						printf("ERROR IN R TREE CREATION\n");
					}
				}
				//reset memory for function_name
				for(j = 0; j < 6; ++j)
				{
					function_name[0] = '\0';	
				}
				i = 0;
			}
		}
		printf("R tree has been constructed\n\n");
	}
}

/*
void build_I_tree()
{
	FILE *fp; //pointer to input file
	struct node *curr;
	char function_name[FNAMESIZE];
	int function_code[FCODESIZE];
	int c;
	int i;
	int j;

	i_tree_root = newNode("NULL");
	fp = fopen("input/i_function_codes.txt", "r");
	i = 0;
	
	for(j = 0; j < FCODESIZE; j++)
	{
		function_code[j] = 0;
	}
	for(j = 0; j < FNAMESIZE; j++)
	{
		function_name[j] = ';';
	}

	if(fp)
	{
		while((c = getc(fp)) != EOF)
		{
			if(i < 6)
			{
				//extract function code from line
				if(c == 48)
				{
					printf("%c", c);
					function_code[i] = 0;
					++i;
				}
				else if(c == 49)
				{
					printf("%c", c);
					function_code[i] = 1;
					++i;
				}
			}
			else
			{
				printf("\n");
				j = 0;
				//extract data from line
				printf("Function name: ");
				while((c = getc(fp)) != ';')
				{
					if(c != ':')
					{
						printf("%c", c);
						function_name[j] = c;
						++j;
					}
				}
				printf("\n");

				//insert into tree
				curr = r_tree_root;
				for(j = 0; j < 6; ++j)
				{
					if(function_code[j] == 0)
					{
						if(j == 5)
						{
							curr->left = newNode(function_name);
						}
						else
						{
							curr->left = newNode("NULL");
							curr = curr->left;
						}
					}
					else if(function_code[j] == 1)
					{
						if(j == 5)
						{
							curr->right = newNode(function_name);
						}
						else
						{
							curr->right = newNode("NULL");
							curr = curr->right;
						}
					}
					else
					{
						printf("ERROR IN R TREE CREATION\n");
					}
				}
				//reset memory for function_name
				function_name[0] = '\0';
				i = 0;
			}
		}
		printf("R tree has been constructed\n\n");
	}
}
*/