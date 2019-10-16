#include<iostream>
#include<string>
using namespace std;
struct Student
{
	string name, sno;
	int  score;
};
int main(void)
{
	int n, max1 = -1, min1 = 101, maxnum, minnum;
	Student s[1000];
	cin >> n;
	for ( int i = 0; i <n; i++ )
	{
		cin >> s[i].name >> s[i].sno >> s[i].score;
		if ( s[i].score > max1 )
		{
			max1 = s[i].score;
			maxnum = i;
		}
		if ( s[i].score < min1 )
		{ 
			min1 = s[i].score;
			minnum = i;
		}
	}
	cout << s[maxnum].name << " " << s[maxnum].sno << endl;
	cout<< s[minnum].name << " " << s[minnum].sno;
	return 0;
}
