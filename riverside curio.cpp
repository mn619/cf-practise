#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;


int main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	
	int marks[n],ans=0,m[n];
	
	cin>>m[0];
	
	marks[0]=1;
	
	for(int i=1;i<n;i++)
	{
	
		cin>>m[i];
		if(m[i]>=marks[i-1])
		{
			marks[i]=m[i]+1;
		}
		else marks[i]=marks[i-1];
	}
	for(int i=n-2;i>=0;i--)
	{
		if(marks[i] < marks[i+1]-1) marks[i]=marks[i+1]-1;
	}	
	
	for(int i=0;i<n;i++)ans+=marks[i]-1-m[i];
	
	cout<<ans<<"\n";
	
}


