#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "NQueens.h"

#define num_of_Queens 5 


int main(int argc, char* argv[]) 
{
    int i              = 0;
    int NumberOfQueens = 0; 
    int SolutionCount  = 0;
    int* Columns;
	int test_case;
   /*
   if ( argc < 2 )
    {
        printf("Usage: %s <Number Of Queens>", argv[0]);
        return 1;
    }
	*/
	//freopen("input.txt", "r", stdin);

	//setbuf(stdout, NULL);

	scanf("%d", &test_case);
	//for (int t = 0; t < test_case; t++) {
		int n; scanf(" %d", &n);

		SolutionCount = 0; // ÃÊ±âÈ­ 
		NumberOfQueens = n;

		Columns = (int*)calloc(NumberOfQueens, sizeof(int));

		for (i = 0; i<NumberOfQueens; i++)
		{
			Columns[0] = i;
			FindSolutionForQueen(Columns, 0, NumberOfQueens, &SolutionCount);
		}
		//printf("#%d %d\n", t+1, SolutionCount);

		free(Columns);
	//}

    return 0;
}
