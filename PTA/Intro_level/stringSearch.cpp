#include <stdio.h>
#define MAXS 30

char *search(char *s, char *t);
void ReadString( char s[] ); 

int main()
{
	/* The C Programming Language / ram */ 
    char s[MAXS], t[MAXS], *pos;

    ReadString(s);
    ReadString(t);
    pos = search(s, t);
    if ( pos != NULL )
        printf("%d\n", pos - s);
    else
        printf("-1\n");

    return 0;
}

char *search(char *s, char *t)
{
	char *tst_s = s;
	char *tst_t = t;
	while ( *tst_t != '\0' ) {
		while (*tst_t == *tst_s  && *tst_s != '\0') {
			tst_t++;
			tst_s++;
		}
		if ( *tst_t != '\0' ) {
			tst_t = t; // refresh
			tst_s = ++s; // move ahead  one step
		}
		if ( *s == '\0' ) {
			s = NULL;
			break;
		}		
	}
	
	return s;
} 

void ReadString( char s[] )
{
	printf("Reading: ");
	gets(s);
}