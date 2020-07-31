#include <iostream>
using namespace std;

int count(char *JCB, char hand_chr)
{
	int length = 3;
	for ( int i = 0; i < length; i++) {
		if (JCB[i] == hand_chr) {
			return i;
		}
	}
}


int findMax(int *suc)
{   // linear search 
	int max = suc[0];	
	for (int i = 1; i < 3; i++) {
		if (max < suc[i]) {
			max = suc[i];	
		}
	}
	return max;
}


char findMinChr(char *max_chrs, int max_cnt)
{   // find min_chr in max_chrs
	if (max_cnt == 0) {
		return 'B';
	} else {
		char min_chr = max_chrs[0];
		for (int i = 1; i < max_cnt	; i++) {
			if (min_chr > max_chrs[i]) {
				min_chr = max_chrs[i];	
			}
		}	
		return min_chr;		
	}
}


int main(int argc, char *argv[])
{
	int N, max_A, max_B, max_cnt= 0;
	char max_chrs[3];
	char max_chr_A, max_chr_B = ' ';
	
	int cnt_A[3] = {0, 0, 0};
	int cnt_B[3] = {0, 0, 0};
	int suc_A[3] = {0, 0, 0};
	int suc_B[3] = {0, 0, 0};
	
	char JCB[3] = {'J', 'C', 'B'};
	char A, B = ' ';
 	cin >> N; //cout << N << "\n";
	
	// C J B
	for (int i = 0; i < N; i++) {
 		cin >> A >> B; //cout << A << " " << B << "\n";	
		if (A == B) {
			cnt_A[1] += 1;
			cnt_B[1] += 1;				
		} else if ((A == 'C' && B == 'J') ||
			       (A == 'J' && B == 'B') ||
 	               (A == 'B' && B == 'C')) {
			cnt_A[0] += 1;
			cnt_B[2] += 1;	
			suc_A[count(JCB, A)] += 1; // succeed count
				
		} else if ((A == 'C' && B == 'B') || 
		           (A == 'J' && B == 'C') ||
 	               (A == 'B' && B == 'J')) {
			cnt_A[2] += 1;
			cnt_B[0] += 1;	
			suc_B[count(JCB, B)] += 1;					
		} 
	}
	
	cout << cnt_A[0] << " " << cnt_A[1] << " " << cnt_A[2] << "\n";
	cout << cnt_B[0] << " " << cnt_B[1] << " " << cnt_B[2] << "\n";
	
	max_A = findMax(suc_A);
	max_B = findMax(suc_B);		
	// ÓÐÖØ¸´´úÂë	
	for (int i, j = 0; i < 3; i++) {
		if (suc_A[i] == max_A) {
			max_chrs[j] = JCB[i];
			j++;
			max_cnt++;
		}
	}
	max_chr_A = findMinChr(max_chrs, max_cnt);

	max_cnt = 0;
	for (int i, j = 0; i < 3; i++) {
		if (suc_B[i] == max_B) {
			max_chrs[j] = JCB[i];
			j++;
			max_cnt++;
		}
	}
	max_chr_B = findMinChr(max_chrs, max_cnt);	
	
	cout << max_chr_A << " " << max_chr_B;
	return 0;
}

