#include <stdio.h>

#define MIN 6
#define MAX 1000

int main(int argc, char *argv[])
{
	int A[MIN], Result[MIN]; /* store a1 to a5 */
	int N[MAX];	
	int i, j, k, num; /* k as index in A1 */
	int evenSum, mixSum, cnt, maxNum, sumForAve;
	float x = 0.0;
	
	for ( i = 0; i < MIN; i++ ) {
		A[i] = 0; /* flag */
	}
	
	/* x as index in A4 */	
 	k = evenSum = mixSum = 0;
	cnt = sumForAve = maxNum = 0;
	scanf("%d", &num);
	for ( i = 0; i < num; i++ ) {
		scanf("%d", &N[i]); /* init */
	}
	for ( j = 0; j < num; j++ ) {
		if ( (N[j]%5)==0 && (N[j]%2)==0 ) {
			/* case in A1 */
			evenSum += N[j];
			A[1] = 1;
		}
		if ( (N[j]%5) == 1 ) {
		    /* case in A2 */
			k++;
			A[2] = 1;
			if ( k%2 == 1 ) {
				mixSum += N[j];
			} else {
				mixSum -= N[j];
			}
		}
		if ( (N[j]%5) == 2 ) {
		    /* case in A3 */
			cnt++;		
			A[3] = 1;
		}
		if ( (N[j]%5) == 3 ) {
		    /* case in A3 */
			sumForAve += N[j];
			x += 1.0;
			A[4] = 1;		
		}
		if ( (N[j]%5) == 4 ) {
			if ( N[j] > maxNum ) {
				maxNum = N[j];
			}
			A[5] = 1;
		}
	}
	
	Result[1] = evenSum;
	Result[2] = mixSum;
	Result[3] = cnt;
	Result[4] = sumForAve;
	Result[5] = maxNum;
	for ( j = 1; j < MIN; j++ ) {
		if ( A[j] == 0 ) {
			/* not exist */
			printf("N");
		} else if ( j == 4 ) {
			printf("%.1f", Result[j]/x);
		} else {
			printf("%d", Result[j]);
		}
		if ( j < (MIN - 1) ) {
			printf(" ");
		}
	}
		
    return 0;
}