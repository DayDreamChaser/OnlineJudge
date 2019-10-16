/* input: "2009/03/02"  out: 61 */
/* 计算任意日期yyyy/mm/dd 在当年的天数  */

#include <stdio.h>

int getNum( const char* DATE, int sta, int end)
{
    int i, num = 0;
    for ( i = sta; i<=end; i++ ) {
    	/*  becareful */
        num = num*10 + (DATE[i] - '0');
    }
    printf("%d\n", num);
    return num;
}

int main(void)
{
    int i, total = 0;
	char DATE[] = "2009/03/02"; 
    int month[13] = {12, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, mon, day;

	/* char A;
	   scanf("%d%c%d%c%d", &year, &A, &mon, &A, &day); */
    scanf("%s", DATE);
    year = getNum( DATE, 0, 3);
    mon = getNum( DATE, 5, 6);
    day = getNum( DATE, 8, 9);
    
    if ( ( year%4==0  && year%100!=0 )  || year%400==0 ) {
        month[2] = 29; /* 闰年 */
    }
    for ( i=1; i < mon; i++ ) {
        total += month[i];
    }
    total += day;
    printf("%d\n", total);
    
    return 0;
}