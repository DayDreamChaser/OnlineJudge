#include <stdio.h>

int main(void)
{
	int guess_num, i=0; /* i as count */
	int rand_num, N;
    scanf("%d %d", &rand_num, &N);
	    
	while ( ++i ) {
		scanf("%d", &guess_num);
		if ( i < N && guess_num < 0 ) {
			printf("Game Over!");			
			break; 
		} else if ( i > N ) {
			/* guess over N times */
			printf("Game Over!");
			break; 
		}
		
		if (  guess_num > rand_num ) {
			printf("Too big\n");
		} else if ( guess_num < rand_num ) {
			printf("Too small\n");			
		} else {
			/* got it */
			if ( i == 1) {
				printf("Bingo!\n"); 				
			} else if (  i>=2 && i<=3 ) {
				printf("Lucky You!\n"); 					
			} else if ( i>3 && i<=N ) {
				printf("Good Guess!\n"); 
			}
			break; 
		}
	}

    return 0;
}