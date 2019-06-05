#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);

using namespace std;
bool c[5201][5201];
int n;
int hex(char x)
{
	if(abs(x - '0') < 9) return x - '0';
	return 10 + x - 'A';
}
void compute(int i, int j, char x)
{
	int t = hex(x);
	//cout<<t<<'\n';
	int cnt = 1;
	while(cnt <= 4)
	{
		c[i][(j)*4 - cnt + 1] = t%2;
		t/=2;
		cnt++;
	}
}

bool check(int l)
{
	int t = n/l;
	bool ret = 1;
	for(int i = 1; i <= n; i += l)
	{
		for(int j = 1; j <= n; j += l)
		{
			bool ok = 1;
			fr(k,i,i + l)
			{
				fr(m, j, j + l)
				{
					if(c[k][m] != c[i][j]) { return 0;}
				}
			}
		}
	}

	return 1;
}
signed main()
{
	FILEIO
 	FLASH

	cin>>n;
	fr(i,1,n + 1)
	{
		fr(j,1,n/4 + 1)
		{
			char x;
			cin>>x;
			compute(i,j,x);
		}
	}


	int ans = 0;
	for(int i = n;i >=1;i--)
	{
		if(n%i == 0)
		{
			if(check(i)) {ans = i; break;}
		}
	}
	cout<<ans<<'\n';
}