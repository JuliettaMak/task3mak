#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define STRLEN 2
#define STRLEN_WITH_F 3

void reduce(char *,int , int ind, int jj, int num, char nonterminal, FILE*);
int input_str_check(char*, FILE*);

void main()
{
	FILE* ff = fopen("task3.log", "a");
	printf("Enter a chain of terminals\n");
	char *str1;
	str1 = (char*)malloc(20);
	scanf("%s", str1);

	const time_t timer = time(NULL);
	fprintf(ff, "%s\n", ctime(&timer));

	fprintf(ff,"Input string: %s \n",str1);
	int check = input_str_check(str1, ff);
	
	if (check == 0)
	{
		fprintf(ff, "----------TABLE----------\n");
		fprintf(ff, "step\t current_string\n");
		strcat(str1, "F");
		fprintf(ff, "%d\t %s\n", 0, str1);

		for (int jj = 1; jj < 3; jj++)

		{
			int ii = 0;
			while (1)
			{
				int loop_break = 0;
				char symb = *(str1 + ii);
				switch (symb)
				{
				case '2':
					if (*(str1 + ii - 1) == 'B')
					{
						reduce(str1, STRLEN_WITH_F, ii - 1, jj, 2, 'S', ff);
						loop_break = 1;
					}
					break;
				case '0':
					reduce(str1, STRLEN_WITH_F, ii, jj, 1, 'B', ff);
					loop_break = 1;
					break;
				case '1':
					reduce(str1, STRLEN_WITH_F, ii, jj, 1, 'B', ff);
					loop_break = 1;
					break;

				case 'F':
					loop_break = 1;
				default:
					break;
				}
				if (loop_break == 1) break;
				else ii++;
			}
		}

		if (!(strcmp(str1, "SF")))  fprintf(ff, "SUCCESS  \t %s\n", str1); 
		else fprintf(ff, "FAILURE: the string doesn't fit the grammar. \t %s\n", str1);
	}
}


void reduce(char * inp, int str_len, int ind, int jj, int num, char nonterminal, FILE* filename)
{
	if (num == 1)
	{
		char tmp = inp[ind];
		*(inp + ind) = nonterminal;
		fprintf(filename, "%d \t ", jj);
		fputs(inp, filename);
		fprintf(filename, "\t\t Rule B: %c has been reduced to %c \n", tmp, nonterminal);
	}
	if (num == 2)
	{
		int new_str_len = STRLEN_WITH_F - num + 1;
		char *tmp2;
		tmp2 = (char*)malloc(num*sizeof(char));

		for (int ii = 0; ii < num; ii++)
		{
			*(tmp2 + ii) = inp[ind + ii];
		}
					
		*(inp + ind) = 'S';
		for (int ii = ind+1; ii <STRLEN_WITH_F; ii++)
		{
			*(inp + ii) = inp[ii+1];
		}

		fprintf(filename, "%d \t ", jj);
		fputs(inp, filename);
		fprintf(filename, "\t\t Rule S: ");
		for (int ii = 0; ii < num; ii++)
		{
			fputc(tmp2[ii], filename);
		}
		fprintf(filename, " has been reduced to %c \n", nonterminal);
	}
}


int input_str_check(char *str1, FILE* filename)
{
	int res = 0;
	int length_str1 = strlen(str1);
	if (length_str1 != STRLEN)
	{
		fprintf(filename, "FAILURE: the string %s doesn't fit the grammar. \t A string should contain 2 symbols. \n", str1);
		res = -1;
	}
	
	for (int ii = 0; ii < STRLEN; ii++)
	{
		char symb_curr = *(str1+ii);
		if (!(symb_curr == '0' || symb_curr == '1' || symb_curr == '2'))
		{
			fprintf(filename, "FAILURE: the terminal %c doesn't belong to the grammar", symb_curr);
			res = -1;
		}
	}
	return res;
}

