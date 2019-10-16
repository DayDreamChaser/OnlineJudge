#include <stdio.h>

void printMove( int A[], int arraySize )
{
	int j;
	for ( j = 0; j < arraySize; j++ ) {
		printf("%d", A[j]);
		if ( j < (arraySize - 1) ) {
			printf(" ");
		}
	}
}

void move( int A[], int left, int right)
{
    while ( left < right ) {
        int temp = A[left];
        A[left] = A[right];
        A[right] = temp;

        left++;
        right--;
    }
}

void move_A( int A[], int left, int right )
{
	int i, mid, tmp;
	
	mid = ( right - left + 1) / 2;
	for ( i = 0; i < mid; i++ ) {
		tmp = A[i + left];
		A[i + left] = A[right - i];
		A[right - i] = tmp; 
	}		
}

int main(int argc, char *argv[])
{
	int i, j;
	int arraySize, moveStep;
	scanf("%d %d", &arraySize, &moveStep);
	
	int A[arraySize];
	for ( i = 0; i < arraySize; i++ ) {
		scanf("%d", &A[i]);
	    //A[i] = i+1;
	} 
	
	/* three step */
	if ( moveStep > 0 ) {
		moveStep = moveStep % arraySize;
		move( A, 0, arraySize - 1 );
		printMove( A, arraySize ); printf("\n");		
		
		move( A, 0, moveStep - 1 );
		printMove( A, arraySize ); printf("\n");	
			
		move( A, moveStep, arraySize - 1 );
		printMove( A, arraySize ); printf("\n");		
	} else {
		printMove( A, arraySize ); //printf("\n");		
	}
	
    return 0;
}