#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m, p;

const int N = 101;
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
	fr(i,1,m + 1) if(i == 1 || i == m) M.a[1][i] = p*(i == m) + 1*(i == 1);
	fr(i,2,m + 1) M.a[i][i - 1] = 1;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m>>p;
 	if(n < m){
 		return cout<<1<<'\n', 0;
 	}

 	cal();
 	n -= m - 1;
 	Mat t = expo(M, n);
 	int ans = 0;

 	fr(i, 1, m + 1){
 		ans += t.a[1][i];
 		ans %= mod;
 	}

 	cout<<ans;
}