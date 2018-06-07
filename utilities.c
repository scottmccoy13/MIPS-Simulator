#include <stdio.h>
#include <stdlib.h>
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

struct node* newNode(char* data)
{
	struct node *my_node = (struct node*) malloc(sizeof(struct node));

	my_node->data = data;
	my_node->right = NULL;
	my_node->left = NULL;

	return(my_node);
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

	fp = fopen("input/r_function_codes.txt", "r");
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
					function_code[i] = 0;
				}
				else if(c == 49)
				{
					function_code[i] = 1;
				}
				else
				{
					if(c != 58 || i != 6) //colon encoding
						printf("ERROR IN FILE READ: char recieved: %c\n", c);
				}
				++i;
			}
			else
			{
				j = 0;
				//extract data from line
				printf("Function code: ");
				while((c = getc(fp)) != ';')
				{
					printf("%c", c);
					function_name[j] = c;
					++j;
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

				i = 0;
			}
		}
		printf("R tree has been constructed");
	}
}

void build_I_tree()
{
	;
}
