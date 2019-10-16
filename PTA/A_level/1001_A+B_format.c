#include <stdio.h>
#include <stdlib.h>

void output( int sum );

int main( void )
{
    int a, b, sum;
    sum = 0;

    scanf("%d %d", &a, &b);
    sum = a + b;
    if ( sum < 0 ) {
        printf("-");
        sum = abs(sum); 
    }    
    output( sum );

    return 0;
}

void output( int sum )
{	
	/* when sum is less than 1000 */
	static int flag = 0;
	
    if ( (sum / 1000) == 0 ) {
    	if ( flag == 1 ) {
    		/* complementary for more than 1000 */
    		if ( sum < 10 ) {
		    	printf("00");
		    } else if ( sum < 100 ) {
    			printf("0");
    		} 
    	}
    	printf("%d", sum);

    } else {
        output( sum / 1000 );
        printf(",");
        flag = 1; /* large than 1000 */
        output( sum % 1000);
    }
}