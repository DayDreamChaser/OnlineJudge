#include <stdio.h>

void test1()
{
    const int MAX = 4; 
	int num[MAX];
    int i, sum = 0;
    float average;
    
    for ( i=0; i<MAX; i++ ) {
        scanf("%d", &num[i]);
        sum += num[i];
    }
    average = sum / 4.0;
    printf("Sum = %d; Average = %.1f\n", sum, average);
}

void test2()
{
    float fb;
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d + %d = %d\n", a, b, a+b );
    printf("%d - %d = %d\n", a, b, a-b);
    printf("%d * %d = %d\n", a, b, a*b);
    if ( a%b == 0  ) {
        printf("%d / %d = %d\n", a, b, a/b);      
    } else {
        fb = b;
        printf("%d / %d = %.2f\n", a, b, a/fb);  
    }
} 

void test3()
{
    int month, day, year;
    scanf("%d %d %d", &month, &day, &year);
    if ( month < 10 ) {
        printf("%d-0%d-%d\n", year, month, day);     
    } else {
        printf("%d-%d-%d\n", year, month, day);
    }
}

int main(void)
{
	test3();
    return 0;	
}
