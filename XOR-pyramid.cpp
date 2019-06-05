#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int n,q;
ll a[5001];
ll ans[5001][5001]={{0}};

void read()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
}


void solve()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==j)ans[i][j]=a[i];
			else ans[i][j]=(ans[i-1][j-1]^ans[i-1][j])^(ans[i][j-1]);
		}
	}
	
	cin>>q;
	
	for(int i=1;i<=q;i++)
	{
		int l,r;
		cin>>l>>r;
		cout<<ans[l][r]<<"\n";
	}
	
}
int main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 	cout<<(2^(3) )<< endl;
	read();
	solve();
}


