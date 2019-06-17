#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
const int N = 6;
int a, b, c, d, n, m;

int power(int a, int b, int m)
{
    int ans = 1;
    a %= m;
    while(b){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

struct Mat{
	int a[N + 1][N + 1];

	Mat operator *(const Mat &b)
	{
		Mat res;
		fr(i,1,m + 1)
		{
			fr(j,1,m + 1)
			{	
				res.a[i][j] = 0;
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

void cal(int x) //Calculate the Matrix elements
{
	m = 3;
	fr(i, 1, N + 1){
		fr(j, 1, N + 1){
			M.a[i][j] = 0;
		}
	}
	if(x)
	fr(i, 1, m + 1){
		M.a[1][i] = 1;
	}
	else{
		m = 5;
		M.a[1][1] = 3;
		M.a[1][2] = -2;
		M.a[1][4] = -1;
		M.a[1][5] = 1;

	}

	fr(i,2,m + 1) M.a[i][i - 1] = 1;
}

signed main()
{
	FILEIO
 	FLASH
 	cin>>n>>a>>b>>c>>d;

 	if(n <= 3){
 		if(n == 1) return cout<<a, 0;
 		if(n == 2) return cout<<b, 0;
 		if(n == 3) return cout<<c, 0;
 	}

 	cal(1);
	int powa = expo(M, n - 3).a[1][3];
	int powb = expo(M, n - 3).a[1][2];
	int powc = expo(M, n - 3).a[1][1];

	cal(0);
	int powcc;

	if(n <= 5){
		if(n <= 3) powcc = 0;
		else if(n == 4) powcc = 2;
		else powcc = 6;
	}
	else{
		Mat exp = expo(M, n - 5);
		powcc = exp.a[1][1]*6 + exp.a[1][2]*2;
	}

	int ans = power(d, powcc, mod);
	ans *= power(a, powa, mod);
	ans %= mod;
	ans *= power(b, powb, mod);
	ans %= mod;
	ans *= power(c, powc, mod);
	ans %= mod;
	

	//cout<<powcc<<" "<<powa<<" "<<powb<<" "<<powc<<"\n";

	cout<<ans;	
}