#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int l[n],r[n],ans[n];
		
		for(int i=0;i<n;i++)
		{
			cin>>l[i]>>r[i];
		}
		
		int c=0;
	
		for(int i=1;c<n;i++)
		{
			
			if(l[c]<=i && r[c]>=i) {ans[c]=i; c++; continue;}
			else if(l[c]<=i && r[c]<i) {ans[c]=0;i--; c++;}
		}
		
		for(int i=0;i<n;i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
	}	
	
}

