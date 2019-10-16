#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Max(x,y) (x)>(y)?(x):(y)
#define Min(x,y) (x)<(y)?(x):(y)

typedef struct Node retNum;
struct Node {
	int min;
	int max;
};

/* A[n+1], A[0]-> num of array */
int findMax(int A[]);
int findMin(int A[]);
void initArray(int A[]); 
retNum minmax(int A[], int i, int j);
int cmpfunc (const void * a, const void * b);

int main(void)
{
	int i, n;
	retNum value;
	int min, max;
	
	printf("Please input num of array: ");
	scanf("%d", &n);
	int *A = (int*)malloc( sizeof(int)*(n+1) );
	A[0] = n;
	initArray( A );
	
	/* traditional */
	min = findMin( A );
	max = findMax( A );
	printf("\ntraditional test:\n");
	printf("min = %d, max = %d\n", min, max);	
	
	/* recursively T(n)=1.5n-1 
	printf("\nrecursively test:\n");
	value = minmax( A, 1, A[0]);
	printf("min = %d, max = %d\n", value.min, value.max);*/

    qsort(A, n+1, sizeof(int), cmpfunc);
    printf("\n排序之后的列表：\n");
    for ( i = 1 ; i <= n; i++ ) {
    	printf("%d ", A[i]);
    }
    printf("\n");
	free(A);
	
	return 0;
} 

int findMax(int A[])
{
	int i, max = A[1];
	for ( i = 2; i <= A[0]; i++) {
		if ( max < A[i] ) {
			max = A[i];
		}
	}
	return max;
}

int findMin( int A[])
{
	int i, min = A[1];
	for ( i = 2; i <= A[0]; i++) {
		if ( min > A[i] ) {
			min = A[i];
		}
	}
	return min;
}

void initArray(int A[])
{   /* randomly init */
	int i;
	srand( time(NULL) );         
	for ( i = 1; i<=A[0]; i++ ) {
		A[i] = rand()/100;
		printf("%d ", A[i]);
	}
	printf("\ninitialized!\n");
}

retNum minmax(int A[], int i, int j)
{
	//static int cnt = 0;
	retNum min_max, m, M;
	int k; /* k as half */
	
	if ( j-i+1 == 1 ) {
		min_max.min = A[i];
		min_max.max = A[i];
	} else if ( j-i+1 == 2 ) {
		if ( A[i] > A[j] ) {
			min_max.min = A[j];
			min_max.max = A[i];
		} else {
			min_max.min = A[i];
			min_max.max = A[j];			
		}
	} else {
		k = (j-i+1) / 2;   /* care for j-j+1  */ 
		m= minmax( A, i, k); 
		M = minmax( A, k+1, j); /* return [m1, M1] */
		min_max.min = Min( m.min, M.min);
		min_max.max = Max( m.max, M.max);
	}
	//printf("done %d\n", ++cnt);
	
	return min_max;	
}

int cmpfunc (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}
