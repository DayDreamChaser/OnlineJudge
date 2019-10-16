#include <stdio.h>

int Euclid( int m ,int n )
{
    int r;
    while ( n != 0 ) {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int main(void)
{
    int A, B;
    int max, min;
    scanf("%d %d", &A, &B);
    
    max =  Euclid( A, B);
    min = (A * B) / max;
    printf("%d %d\n", max, min);
    
    return 0;
}