#include <stdio.h>

typedef struct fact_node Fraction;
struct fact_node {
	int up;
	int down;
	char s;
};

void test2( double mix_a, double mix_b)
{   /*  ?????? */ 
	if ( mix_a > mix_b ) {
		printf(">");	
	} else if ( mix_a < mix_b ) {
		printf("<");
	} else if ( mix_a = mix_b ) {
		printf("=");
	}
}

int main(void)
{
	Fraction a, b;
	scanf("%d", &a.up);
	scanf("%c", &a.s);
	scanf("%d", &a.down);
	
	scanf("%d", &b.up);
	scanf("%c", &b.s);
	scanf("%d", &b.down);
	
	/*int mix_a, mix_b;
	mix_a = a.up * b.down;
	mix_b = a.down * b.up;	*/
	double mix_a, mix_b;
	mix_a = (double)(a.up / a.down);
	mix_b = (double)(b.up / b.down);
	
	printf("%d%c%d ", a.up, a.s, a.down);
	test2(mix_a, mix_b);
	printf(" %d%c%d", b.up, b.s, b.down);
		
	return 0;
}