#include <stdio.h>
#include <stdlib.h>

void printf_str( char * s, int str, int end )
{
    int i;
    for ( i = str; i <= end; i++  ) {
        printf("%c", s[i]);
    }
}

int main(void)
{
    char *total = (char*)malloc( sizeof(char)*11 );
    scanf("%s", total); /* 03-15-2017  */
    printf_str( total, 6 ,9); /* ¡°mm-dd-yyyy¡±*/ 
    printf("-");
    printf_str( total, 0 ,1);
    printf("-");
    printf_str( total, 3 ,4);
    printf("\n"); /* 2017-03-15 */
    free(total);
    
    return 0;	
}