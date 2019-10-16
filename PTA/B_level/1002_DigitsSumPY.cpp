/*  将数字每一位加起来得到和Sum，然后将sum的每一位用拼音输出 */ 
#include <stdio.h>

#define MAX 10
#define MAX_LEN 100
char * pingYing[MAX] = { "ling", "yi", "er", 
	"san","si", "wu", "liu", "qi", "ba", "jiu"
};

unsigned int cntNumberSum( char *s );	
unsigned int cntDigitSum( unsigned long n );
void printPY( unsigned int sum );

int main(int argc, char *argv[])
{
	unsigned int sum;
	unsigned int sta;
    //unsigned long n;
	char numStr[MAX_LEN];
	scanf("%s",numStr);
	//scanf("%lu",&n);
	
	sum = cntNumberSum( numStr);
	//sum = cntDigitSum( n );
	sta = sum;
	printf("%d\n", sum);
	printPY( sum );
	
    return 0;
}

unsigned int cntNumberSum( char *s )
{
	unsigned int sum = 0;
	while ( *s != '\0' ) {
		sum += *s - '0';
		s++;
	}
	return sum;
}
	
unsigned int cntDigitSum( unsigned long n )
{
	int cnt = 0;
	unsigned int sum = 0;
	while ( n != 0) {
		 sum += n % 10;
		 n = n / 10;
		 /* start print test */
		 printf("%d: ", ++cnt);
		 printf("%lu ", n);
 		 printf(" sum=%u\n", sum);
 		 /* end test*/
	}
	printf("\n%u ", sum);
	return sum;	
}

void printPY( unsigned int sum  )
{   // sta equal to unchanged sum 
	static int sta = sum;
	if ( sum != 0 ) {
		printPY( sum/10 ); // 先递归打印高位 
		printf("%s", pingYing[ sum%10 ]);
		if ( sum != sta ) {
			printf(" ");
		}
	}
}
