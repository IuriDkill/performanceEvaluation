#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <omp.h>
#include <malloc.h>

#include "src/matrix.h"

int main(int argc, char **argv){
	char *awnser[] = { "bad", "ok" };
	
	int i, j, n, is_ok;
	double elapsed, start, end;
	
	if(argc != 2){
		exit(EXIT_FAILURE);
	}

	n = atoi(argv[1]);
	
	n = n % 8 == 0 ? n : n + (8 - n % 8);
	
	double *A = malloc(n * n * sizeof(double));
	assert(A != NULL);
	
	double *B = malloc(n * n * sizeof(double));
	assert(B != NULL);
	
	double *C = malloc(n * n * sizeof(double));
	assert(C != NULL);
	
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++){
			A[i * n + j] = 1; /* Do not */
			B[i * n + j] = 1; /* change */
			C[i * n + j] = 0; /* it */
		}
	
	start = omp_get_wtime();
	matrix_mult(A, B, C, n);
	end = omp_get_wtime();
	
	elapsed = end - start;

	is_ok = 1;	
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(C[i * n + j] != (double) n){
				is_ok = 0;
				i = n;
				j = n;
			}


	printf("%.3f\n", elapsed);
	
	free(A);
	free(B);
	free(C);

	return 0;
}