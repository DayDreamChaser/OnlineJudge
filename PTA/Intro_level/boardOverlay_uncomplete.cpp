/* Board Overlay 棋盘覆盖 */
/* 2K*2K 棋盘，初始化一点，使用最少的L骨牌覆盖 */ 

#include <stdio.h>

#define MAX 3
typedef struct posNode Pos; 
struct posNode {
	int x, y;
};
enum FORM { up, down, right, left }; /* L形状 */

int boardOverlay( int B[][], int size,  Pos s);
Pos* fillL( int B[][], int size, Pos p, FORM T);
int judgePos( int B[][], int size, int k, Pos s);

int main(void)
{
	Pos s; /* 0 <= x,y <= 2k-1  */
	int i, j;
	int size, k;
	scanf("%d %d %d", &k, &s.x, &s.y);
	size = 2 * k;
	
	int B[size][size];
	for ( i=0; i<size; i++ ) {
		for ( j=0; j<size; j++ ) {
			B[i][j] = 0; /* init as 0, not occpy */
		}
	}
	B[s.x][s.y] = 1; /*  init pos */
	boardOverlay( B, size, s);
	
	return 0;
} 

int boardOverlay( int B[][], int size, Pos s)
{
	int k;
	Pos *Spec; /* store 3 special point */
	if ( size==1 ) {
		return 0;
	} else {
		k = size/2;
		enum FORM T = judgePos( B, size, k, s);
		Spec = fillL( B, size, s, T);
		boardOverlay( B, k, s);
		boardOverlay( B, k, Spec[0]);
		boardOverlay( B, k, Spec[1]);
		boardOverlay( B, k, Spec[2]);		
	}
}

Pos* fillL( int B[][], int size, Pos s, FORM T)
{
	
}

LType judgePos( int B[][], int size, int k, Pos s)
{
	
}