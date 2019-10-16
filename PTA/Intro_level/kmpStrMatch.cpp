#include <stdio.h>
#include <string.h>

#define MAX 20
#define MIN 5
int next[MIN];

int KMP( const char *t, const char *p);  // ���׺ ��ǰ׺ 
void getNext(const char *p, int *next);

int main(int argc, char *argv[])
{
	int i, n;
	char *t = "Hello world";
	char *p = "world";
	getNext( p, next);
	
	for ( i=0; i< MIN; i++ ) {
		printf("%d ", next[i]);
        if ( i == MIN -1 ) printf("\n");
	}
	
	n = KMP(t, p);
	printf("%dth\n", n);
	
    return 0;
}

int KMP( const char *t, const char *p) 
{
	int i = 0; /* test string */
	int j = 0; /* pattern string */

	while ( i < strlen(t) && j < strlen(p) ) {
		// ��jΪ-1ʱ��Ҫ�ƶ�����i����ȻjҲҪ��0
		if ( j == -1 || t[i] == p[j] ) { 
			i++;
			j++;
		} else {	
 			j = next[j];
    	}
	} /* while */
	
    if ( j == strlen(p) ) {
    	return i - j;	
    } else {
    	return -1;    	
    } 
}

void getNext(const char *p, int *next)
{
	next[0] = -1;
	int i = 0, j = -1;

	while ( i < strlen(p) )
	{
		if ( j == -1 || p[i] == p[j] )
		{
			if ( p[++j] == p[++i] ) { // �������ַ����ʱҪ����
				next[i] = next[j];
            } else {
				next[i] = j;
            }
		} else {
			j = next[j];
		} 
	}
}
