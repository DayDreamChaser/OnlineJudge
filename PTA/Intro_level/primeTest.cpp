#include <stdio.h>

int prime( int p );
int PrimeSum( int m, int n );

int main()
{
    int m, n, p;  /* m->start n->end  */
    printf("Please input start and end point:\n\n");
    scanf("%d %d", &m, &n);
    printf("Sum of ( ");
    for( p=m; p<=n; p++ ) {
        if( prime(p) != 0 )
            printf("%d ", p);
    }
    printf(") = %d\n", PrimeSum(m, n));

    return 0;
}

int prime( int p )
{
    int flag = 0;
    int i, cnt = 0;
    for ( i = 1; i<=p; i++ ) {
        if ( (p % i) == 0  ) {
            cnt++;  /* Õû³ý */ 
        }
    }
    if (  cnt == 2 ) {
        flag = 1; /* is prime  */ 
    }
    
    return flag;
}

int PrimeSum( int m, int n )
{
    int i, sum = 0;
    for ( i = m; i <= n; i++  ) {
        if (  prime( i ) ) {
            sum += i; /*  acumulate  */
        }
    }
    return sum;
}