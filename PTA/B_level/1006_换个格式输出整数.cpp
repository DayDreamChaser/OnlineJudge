#include <stdio.h>

void outPutNum( int num );
void printChar( int n, char c );

int main(int argc, char *argv[])
{
	int num;
	scanf("%d", &num);
	outPutNum( num );
	
    return 0;
}

void outPutNum( int num )
{
	int i, hundred, ten, single;

    hundred = num / 100;
    ten =  (num % 100) / 10;
	single = num % 10; 
	printChar( hundred, 'B' );
	printChar( ten, 'S' );
	printChar( single, 'G' );	
}

void printChar( int n, char c )
{  
	int i;
	if ( c == 'G' ) {
		/* 个位输出数字 */
		for ( i = 1; i <= n; i++ ) {
			printf("%d", i);
		}
	} else {
		for ( i = 1; i <= n; i++ ) {
			printf("%c", c);
		}	
	} 
}