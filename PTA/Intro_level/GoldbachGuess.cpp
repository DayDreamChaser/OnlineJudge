/* 实现一个判断素数的简单函数，并利用该函数验证哥德巴赫猜想：
  任何一个不小于6的偶数均可表示为两个奇素数之和。
  素数就是只能被1和自身整除的正整数。 */
  
#include <stdio.h>
#include <math.h>

int prime( int p );
void Goldbach( int n );

int main()
{
    int m, n, i, cnt;

    scanf("%d %d", &m, &n);
    if ( prime(m) != 0 ) printf("%d is a prime number\n", m);
    if ( m < 6 ) m = 6;
    if ( m%2 ) m++; /* let m be an even figure */
    cnt = 0;
    for( i=m; i<=n; i+=2 ) {
        Goldbach(i);
        cnt++;
        if ( cnt%5 ) printf(", ");
        else printf("\n");
    }

    return 0;
}

int prime( int p )
{
    int flag = 0;
    int i, cnt = 0;
    for ( i = 1; i<=p; i++ ) {
        if ( p % i == 0  ) {
            cnt++;  /* 整除 */ 
        }
    }
    if (  cnt == 2 ) {
        flag = 1; /* is prime  */ 
    }
    
    return flag;
}

void Goldbach( int n )
{	
	int i, p, q; 
	int min_p = n; /* init */ 
	const int STR = 3; 
	/* 不小于6的偶数可以分解为两个奇素数 */
	if ( n >= 6 && n%2 == 0 ) {
		/* 暴力拆解 */
		for ( i = STR; i < n; i++ ) {
			/* 分解值p q都为素数 */ 
			if ( prime(i)!=0 && prime(n-i)!=0  ) {
				p = i;
				q = n-i;
				if ( p > q ) {
					p = q; /* let p be a minor one */
					q = i;
				}
				if ( min_p > p ) 
					min_p = p;
			}		
		}
		printf("%d=%d+%d", n, min_p, n-min_p);
	}  	
}
