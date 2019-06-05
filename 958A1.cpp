#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	int n;
	cin>>n;
	
	char a[n][n],b[n][n];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>b[i][j];
		}
	}
	
	
	bool v[8]={1,1,1,1,1,1,1,1};
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(v[0])if(a[i][j]!=b[j][n-1-i])v[0]=0;
			if(v[1])if(a[i][j]!=b[n-i-1][n-j-1])v[1]=0;
			if(v[2])if(a[i][j]!=b[n-j-1][i])v[2]=0;
			if(v[3])if(a[i][j]!=b[n-1-i][j])v[3]=0;
			if(v[4])if(a[i][j]!=b[i][n-j-1])v[4]=0;
			if(v[5])if(a[i][j]!=b[j][i])v[5]=0;
			if(v[6])if(a[i][j]!=b[n-1-j][n-1-i])v[6]=0;
			if(v[7])if(a[i][j]!=b[i][j])v[7]=0;
			if(v[0]==v[1] && v[1]==v[2] && v[2]==v[3] && v[3]==v[4] && v[4]==v[5] && v[5]==v[6]&& v[6]==v[7] && v[7]==0)
			{
				cout<<"No\n"<<endl;
				return 0;
			}
		}
	}
	
	
	
	cout<<"Yes\n";
	return 0;
}

