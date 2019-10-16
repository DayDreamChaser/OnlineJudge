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
                flag_A = 0; // ��'A'�ַ�, flag_AΪ0 
                break;
            }
        }
        for ( i = 0; i <lens; i++ ) {
            if ( str[i] != 'P' &&
				 str[i] != 'T' &&
				 str[i] != 'A' 
			   ) {  // ��'P' 'T' 'A'֮��������ַ� 
                flag = 1;
                break;
            }
            if ( str[i] == 'P' ) {
                left = i;   // �ҵ�'P'��λ�� 
            } else if ( str[i] == 'T' ) {
                right = i;  // �ҵ�'T'��λ�� 
            }
        }
        // �ж��ַ�, �������PAT 
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
        // �����"PTA"֮���ַ��� û��'A' 
			printf("NO\n");
		} 
    }    
    return 0;    
}