/* ʵ��һ���ж������ļ򵥺����������øú�����֤��°ͺղ��룺
  �κ�һ����С��6��ż�����ɱ�ʾΪ����������֮�͡�
  ��������ֻ�ܱ�1�������������������� */
  
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
            cnt++;  /* ���� */ 
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
	/* ��С��6��ż�����Էֽ�Ϊ���������� */
	if ( n >= 6 && n%2 == 0 ) {
		/* ������� */
		for ( i = STR; i < n; i++ ) {
			/* �ֽ�ֵp q��Ϊ���� */ 
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
