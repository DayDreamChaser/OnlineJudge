/*  给定平面坐标轴点，判断最大矩形min，max端点 */
#include <stdio.h>

typedef struct Pos_node Pos;
struct Pos_node {
	int x;
	int y;
};

int main(void)
{
	int num, i;
	scanf("%d", &num);
	
	Pos A[num];
	for ( i=0; i<num; i++ ) {
		scanf("%d", &A[i].x);
		scanf("%d", &A[i].y);
	}	
	
	int min_x, min_y;
	int max_x, max_y;
	min_x = min_y = 0; /* init as 0 */
	max_y = max_x = 0;
	for ( i=1; i<num; i++) {
		if ( A[min_x].x > A[i].x  )
			min_x = i;
		if ( A[min_y].x > A[i].y  )
			min_y = i;
		if ( A[max_x].x < A[i].x  )
			max_x = i;
		if ( A[max_y].y < A[i].y  )
			max_y = i;
	}	
	printf("%d %d %d %d\n", A[min_x].x, A[min_y].y, A[max_x].x, A[max_y].y );
} 
