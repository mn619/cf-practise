#include<bits/stdc++.h>
#define ll long long int
#define pb push_back



using namespace std;

int main()
{
	int n;
	cin>>n;
	ll a[n];
	map<ll,int> m;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++)
	{
		while(p.find(a[i])!=p.end())
		{
			p.erase(a[i]);
			a[i]*=2;
		}
	}
	
	
}

