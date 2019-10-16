#include <stdio.h>
int main(int argc, char *argv[])
{
	int i, num;
	int A, B, C;
	
	scanf("%d", &num);
	for ( i = 0; i < num; i++ ) {
		scanf("%d %d %d", &A, &B, & C);
		printf("Case #%d: ", i+1); 
		if ( A + B > C ) {
			printf("true\n");
		} else {
			printf("false\n");
		}
	
	}  
    return 0;
}