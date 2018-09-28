#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
	//Basic parsing from files

	char line[2000];
	int row1, col1, row2, col2;

	int numThreads = atoi(argv[3]);

	FILE *input1 = fopen(argv[1], "r");
	FILE *input2 = fopen(argv[2], "r");

	fgets(line, 2000, input1);
	char *token;
	token = strtok(line, " ");

	row1 = atoi(token); //code to save tokens
	token = strtok(NULL, " ");
	col1 = atoi(token);

	fgets(line, 2000, input2);
	token = strtok(line, " ");

	row2 = atoi(token);
	token = strtok(NULL, " ");
	col2 = atoi(token);

	double matrix1[row1][col1];
	double matrix2[row2][col2];

	int a, b;
	for(a = 0; a < row1; a++){
		fgets(line, 2000, input1);
		token = strtok(line, " ");
		b = 0;
		while(token != NULL){
			matrix1[a][b] = atof(token);
			b++;
			token = strtok(NULL, " ");
		}
	}

	for(a = 0; a < row2; a++){
		fgets(line, 2000, input2);
		token = strtok(line, " ");
		b = 0;
		while(token != NULL){
			matrix2[a][b] = atof(token);
			b++;
			token = strtok(NULL, " ");
		}
	}

//	code to check if matrices parsed correctly (they did)
	printf("Matrix 1\n");

	for(a = 0; a < row1; a++){
		for(b = 0; b < col1; b++){
			printf("%f ", matrix1[a][b]);
		}
		printf("\n");
	}

	printf("Matrix 2\n");

	for(a = 0; a < row2; a++){
		for(b = 0; b < col2; b++){
			printf("%f ", matrix2[a][b]);
		}
		printf("\n");
	}


	//sequential matrix multiplication

	double matrixResult[row1][col2];
	int x, y, product;
	for(x = 0; x < row1; x++){
		for(y = 0; y < col2; y++){
			product = 0;
			for(a = 0; a < col1; a++){
				product = product + (matrix1[x][a] * matrix2[a][y]);
			}
			matrixResult[x][y] = product;
		}
	}

	printf("Matrix result\n");

	for(a = 0; a < row1; a++){
		for(b = 0; b < col2; b++){
			printf("%f ", matrixResult[a][b]);
		}
		printf("\n");
	}




	fclose(input1);
	fclose(input2);
}