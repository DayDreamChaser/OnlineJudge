#include <stdio.h>

#define MAX 101
int isKeyNum( int Test[], int N, int num );

int main(int argc, char *argv[])
{
	// Callatz, cut half of the num if it's a even or cut half of  3n+1 until it's 1 
	int i, N, flag;
	flag = 1;
	scanf("%d", &N);          // the number of test figures 
	 
	int Test[N], outPut[MAX]; // let a bucket count the unoverlayed numer 
	for ( i = 0; i < N; i++ ) {
		scanf("%d", &Test[i]);
	} 
	for ( i = 0; i < MAX; i++ ) {
		outPut[i] = 0;        // store key number
	} 

	// Ex: n=3 , 5->8->4->2->1 callatz sequence 
	// ���ǳ� 5��8��4��2 �Ǳ� 3�����ǡ�������
	// ���n���ܱ������е���������������(nû�г������������ĸ���������),���һ�������е�ĳ����nΪ���ؼ�����
	for ( i = 0; i < N; i++ ) {
		if ( isKeyNum( Test, N, Test[i] ) ) {
			outPut[ Test[i] ] += 1;
		}
	}
	
	// reverse order output
	for ( i = MAX-1; i >= 1; i-- ) {
		if ( outPut[i] != 0 ) {
			if ( flag == 1 ) {
				printf("%d", i);
				flag = 0;
			} else {
				printf(" %d", i);				
			}
		}			
	}
	 		
    return 0;
}

int isKeyNum( int Test[], int N, int num )
{
	int i, n, flag;
	
	// ����N-1���� 
	// numû�г�������N-1�����ĸ��������� 
	for ( i = 0; i < N; i++ ) {
		if ( Test[i] != num ) {
			n = Test[i]; // ����n��callatz 
			flag = 1;
			
			// callatz guess
			while ( n != 1 ) {
				if ( n%2 == 0 ) {
					n = n / 2;
				} else if ( n%2 == 1 ) {
					n = (3*n + 1) / 2;
				}
				if ( num == n ) {
					flag = 0; 	// overlayed��num������ 
					break;      // ����key 
				}
			}
			if ( flag == 0 ) {
				break;
			}
		}	
	}
	return flag;
}
