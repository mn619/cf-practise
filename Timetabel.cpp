#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;
int n,m,k;
char c[500][500];

vector <int> v[500];

void solve()
{
	int dp[n][k+1]={{0}};
	int xx=1;
	
	for(int i=0;;i++)
	{
		if(i==0){dp[0][xx]=dp[0][xx-1];}
		else dp[0][xx]=v[0][i]+dp[0][i-1];
		xx++;
	}	
	cout<<"gs;dkgs";
	//x->v[i]size-x;
	for(int i=1;i<n;i++)
	{
		
		for(int j=1;j<=k;j++)
		{
			int max=0;
			int size=v[i].size();
			for(int k=0;k<=min(j,size-1);k++)
			{
				int y=v[i][k]+dp[i][j-k];
				if(max<y){max=y;}
			}
			cout<<max<<"\t"<<j<<"\n";
			dp[i][j]=max;
		}
	}
	
	cout<<"\n\n";
	
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=k;j++)cout<<dp[i][j]<<"\t";
		cout<<"\n";
	}
	cout<<dp[n-1][k]<<"\n";
	
}
int main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	char c[n][m];
	
	for(int i=0;i<n;i++)
	{
		int k=0;
		v[i].pb(0);
		for(int j=0;j<m;j++)
		{
			cin>>c[i][j];
			int z=0;
			if(c[i][j]=='1')
			{
				if(v[i].size()==0)v[i].pb(j+1);
				else v[i].pb(j-k);
				k=j;
				z++;
				cout<<v[i][z-1]<<"\t";
			}
		}
		cout<<" done \n"<<v[0][0]<<" "<<v[0][1]<<" sdgs\n";
		
		sort(v[i].begin(),v[i].end());
		
		int arr[v[i].size()];
		
		for(int j=0;j<v[i].size();j++)
		{
			arr[j]=v[i][v[i].size()-1-j];
		}

		for(int j=0;j<v[i].size();j++)
		{
			v[i][j]=arr[j];
		}
		
	}
	
	cout<<v[1].size()<<"sg\n";
	for(int i=0;i<v[0].size();i++) cout<<v[0][i]<<"\t"<<i<<"\n";
	
	cout<<"\ndgsdgs\n";
	solve();
}


