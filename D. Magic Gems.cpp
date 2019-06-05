/*
*
*	Matrix Exponentiation 
*	Solves - https://codeforces.com/contest/1117/problem/D
*
*/
#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007

using namespace std;
const int N = 101;
int n, m;

struct Mat{
	int a[N][N];
	Mat operator *(const Mat &b)
	{
		Mat res;
		fr(i,1,m + 1)
		{
			fr(j,1,m + 1)
			{
				fr(k,1,m + 1)
				{
					res.a[i][j] = (res.a[i][j] + a[i][k]*b.a[k][j])%mod;
				}
			}
		}
		return res;
	}
};

Mat expo(Mat A, int b)
{
	if(b == 1) return A;
	if(b&1) return expo(A*A, b/2)*A;
	return expo(A*A, b/2);
}

Mat M;

void cal() // Calculate the Matrix elements
{
	fr(i,1,m + 1) if(i == 1 || i == m) M.a[1][i] = 1; // for most problems change only this line
	fr(i,2,m + 1) M.a[i][i - 1] = 1;
}

signed main()
{
 	FLASH
 	cin>>n>>m;
 	cal();
 	if(n <= m) return cout<<1, 0;
 	cout<<(expo(M, n).a[1][1])%mod;
}