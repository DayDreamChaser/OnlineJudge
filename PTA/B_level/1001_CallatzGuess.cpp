#include <stdio.h>

int Callatz(int n); 

int main(int argc, char *argv[])
{
	int n;
	scanf("%d", &n);
	printf("%d\n", Callatz(n));
	 
    return 0;
}

int Callatz(int n)
{
	int cnt = 0;
	while ( n != 1 ) {
		if ( n%2 == 0 ) {
			n = n / 2;
		} else if ( n%2 == 1 ){
			n = (3*n + 1) / 2;
		}
		//printf("%d ", n);
		cnt++;
	}
	return cnt;
}