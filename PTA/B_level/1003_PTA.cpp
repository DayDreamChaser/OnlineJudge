#include<stdio.h>
#include<string.h>

#define MAX 100 

int main(void)
{
    int n, flag, flag_A; // flag of "PTA" and "A"
    int left, right;  // char pos
    char str[MAX];
    scanf("%d",&n);   // n times

    while ( n-- ) {
        scanf("%s",str);
        
        int i, lens;  // initial 
        flag = 0;    
        flag_A = 1;
        left = right = 0;
        lens = strlen(str);
        
        for ( i = 0; i < lens; i++ ) {
            if ( str[i] == 'A' ) {
                flag_A = 0; // 有'A'字符, flag_A为0 
                break;
            }
        }
        for ( i = 0; i <lens; i++ ) {
            if ( str[i] != 'P' &&
				 str[i] != 'T' &&
				 str[i] != 'A' 
			   ) {  // 有'P' 'T' 'A'之外的其他字符 
                flag = 1;
                break;
            }
            if ( str[i] == 'P' ) {
                left = i;   // 找到'P'的位置 
            } else if ( str[i] == 'T' ) {
                right = i;  // 找到'T'的位置 
            }
        }
        // 判断字符, 必须包含PAT 
        if ( flag == 0 && flag_A == 0 ) {
            if (left == 0 && right == lens-1 ) {
       			// str == "PAT"
                printf("YES\n");
            } else if ( left*(right-left-1)== (lens-1-right) ) {
                if ( left != 0 ) {
                    printf("YES\n");
                } else {
                    printf("NO\n");
                }     
            } else {
                printf("NO\n");
            }
        }
        if ( flag == 1 || flag_A == 1 ) {
        // 如果有"PTA"之外字符， 没有'A' 
			printf("NO\n");
		} 
    }    
    return 0;    
}