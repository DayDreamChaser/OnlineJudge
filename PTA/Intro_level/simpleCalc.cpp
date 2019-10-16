/*																	 
  ģ���������,������ֻ�ܽ��мӼ��˳����㣬�������ͽ������������
  ��������ȼ���ͬ���������ҵ�˳����㡣������һ���и���һ������
  ������ʽ��û�пո���������һ�������������Ⱥš�=��˵�����������
 															 	  */
#include <stdio.h>

#define ERROR -91234567

int calc( char A, int B, int C );

int main(void)
{
    int result, num1, num2;
    char oper;
	scanf("%d%c", &num1, &oper);
	/* ��������: 1+2*10-10/2= */

	while ( oper!= '=' ) {
		scanf("%d", &num2);
		result = calc( oper, num1, num2 );
		if ( result == ERROR ) {
			break; /* ��ĸΪ0���쳣������ */
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
					  /* ������ĸΪ0 */	
 	  				  num = B / C; flag++;
  				  }
		          break;
		default : break; /* �쳣������ */		 
	}
	if ( flag==1 ) {
		//printf("Done\n");
		return num;	
	} else {		
		return ERROR;		
	}
}