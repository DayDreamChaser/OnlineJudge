/*																	 
  模拟简单运算器,计算器只能进行加减乘除运算，运算数和结果都是整数，
  运算符优先级相同，按从左到右的顺序计算。输入在一行中给出一个四则
  运算算式，没有空格，且至少有一个操作数。遇等号”=”说明输入结束。
 															 	  */
#include <stdio.h>

#define ERROR -91234567

int calc( char A, int B, int C );

int main(void)
{
    int result, num1, num2;
    char oper;
	scanf("%d%c", &num1, &oper);
	/* 输入样例: 1+2*10-10/2= */

	while ( oper!= '=' ) {
		scanf("%d", &num2);
		result = calc( oper, num1, num2 );
		if ( result == ERROR ) {
			break; /* 分母为0或异常操作符 */
		}
		num1 = result;
		scanf("%c", &oper);
	}
	
	if ( result == ERROR ) {
		printf("ERROR\n");		
	} else {
    	printf("%d\n", result);		
	}
	
    return 0;
}

int calc( char A, int B, int C )
{
	int num;
	int flag = 0; /* Legal Operation */
	switch (A) {
		case '+': num = B + C; flag++; break;
		case '-': num = B - C; flag++; break;
		case '*': num = B * C; flag++; break;
		case '/': if ( C != 0 ) {
					  /* 除法分母为0 */	
 	  				  num = B / C; flag++;
  				  }
		          break;
		default : break; /* 异常操作符 */		 
	}
	if ( flag==1 ) {
		//printf("Done\n");
		return num;	
	} else {		
		return ERROR;		
	}
}