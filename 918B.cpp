#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	string name[n+1],ip[n+1];
	
	for(int i=1;i<=n;i++)
	{
		cin>>name[i]>>ip[i];
	}
	string comand[m+1],ip2[m+1];
	for(int i=1;i<=m;i++)
	{
		cin>>comand[i]>>ip2[i];
	}
	
	for(int i=1;i<=m;i++)
	{
		string x=ip2[i],name2="kjb";
		x=x.substr(0,x.length()-1);
		for(int j=1;j<=n;j++)
		{
			if(ip[j]==x){name2=name[j]; break;}
		}
		cout<<comand[i]<<" "<<ip2[i]<<" #"<<name2<<endl;
		
	}
}

