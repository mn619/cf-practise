#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

void solve(map <int,int> count, map <int,int> m, int n)
{
	map <int,int>::iterator it=m.begin();
	
	for(int i=0;i<n;i++)
	{
		if(it->second==count[it->first]-1)
		{
			cout<<it->first<<"\n"; break;
		}
		it++;
	}
}

int main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	
	map <int,int> m;
	map <int,int> l;
	
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		m[k]=0;
		if(l[k]) l[k]++;
		else l[k]=1;
	}
	
	
	for(int i=0;i<n-1;i++)
	{
		int k;
		cin>>k;
		m[k]++;
	}
	
	solve(l,m,n);
	
	map <int,int> ::iterator it=l.begin();
	
	for(int i=0;i<n;i++){
		l[it->first]=0; it++;
	}
	
	for(int i=0;i<n-2;i++)
	{
		int k;
		cin>>k;
		if(l[k])l[k]++;
		else l[k]=1;
	}
	
	solve(m,l,n);
	
	
}


