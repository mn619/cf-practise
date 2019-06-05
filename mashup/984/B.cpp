#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;
bool f(char a[][102], int i,int j,int n,int m)
{
	int k=0;
	if(a[i-1][j-1]=='*')k++;
	if(a[i-1][j]=='*')k++;
	if(a[i-1][j+1]=='*')k++;
	if(a[i][j-1]=='*')k++;
	if(a[i][j+1]=='*')k++;
	if(a[i+1][j-1]=='*')k++;
	if(a[i+1][j]=='*')k++;
	if(a[i+1][j+1]=='*')k++;
	
	if(a[i][j]-'1'+1==k)return true;
	return false;
}

bool g(char a[][102],int i,int j,int n,int m)
{
	if(a[i-1][j-1]=='*'||a[i-1][j]=='*'||a[i-1][j+1]=='*'||a[i][j-1]=='*'||a[i][j+1]=='*'||a[i+1][j-1]=='*'||a[i+1][j]=='*'||a[i+1][j+1]=='*')return false;
	return true;
}
int main()
{
	int n,m;
	cin>>n>>m;
	
	char a[102][102];
	for(int i=0;i<n;i++)
	{
		a[0][i]='.';
		a[i][0]='.';
		a[n+1][i]='.';
		a[i][m+1]='.';
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	string ans="YES";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!='*'&&a[i][j]!='.')
			{
				bool b=f(a,i,j,n,m);
				if(!b){ans="NO";break;}
			//	cout<<i<<"\t"<<j<<"\t"<<b<<endl;
			}
			if(a[i][j]=='.')
			{
				bool b=g(a,i,j,n,m);
				if(!b){ans="NO";break;}
			}
		}
	}
	cout<<ans;
}

