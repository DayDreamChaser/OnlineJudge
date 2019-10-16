#include <stdio.h>

int isPrime( int N )
{   /* 穷举法判断素数 */
	if ( N <= 1 ) {
		return 0;		
	} else {
		int flag = 1;
		for ( i = 2; i < N; i++ ) {
			if ( (N % i) == 0 ) {
				flag = 0;
                break;
			}
		}
		return flag;			
	}			
} 

int isPrimeSqrt( int num )
{   /* 开方法判断素数 */ 
    int flag = 1;
    int N = sqrt(num);
    int i;
    for ( i = 2; i <= N; i++ ){
        if (num % i == 0) {
            flag = 0;
        } 
    }
    return flag;
}

int generatePrime( int primes[], int N )
{
	int i, j;
	for ( j = 0, i = 1; i <= N; i++ ) {
		if ( isPrimeSqrt(i) ) {
			primes[j++] = i;
		}
	}
	return j; /* prime index */
}

int main(int argc, char *argv[])
{
	int i, N, border;
	int differ, cntPrimePair;
	border = differ = cntPrimePair = 0;
	scanf("%d", &N);
	
	int primes[N]; /* 存放素数 */ 
	for ( i = 0; i < N; i++ ) {
		primes[i] = 0;
	}
	border = generatePrime( primes, N );
	
	for ( i = 0; i < (border-1); i++ ) {
    	differ = primes[i+1] - primes[i];
    	//printf("differ %d\n", differ);
    	if ( differ == 2 ) {
        	cntPrimePair += 1;	    	
	    }
	}	
	printf("%d\n", cntPrimePair);
	 
    return 0;
}