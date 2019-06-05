#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int n;
ll a[150002];
map <ll,int> m;
	
void read()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
}

void change(ll i,int j)
{
	if(m[i])
	{
		change(2*i,j);
		m.erase(i);
	}
	else m[i]=j;
}

void solve()
{

	for(int i=1;i<=n;i++)
	{
		change(a[i],i);	
	}
	map <ll,int>::iterator it=m.begin(); 
	
	vector <ll> b[m.size()];
	for(int i=0;i<m.size();i++)
	{
		b[i].pb(it->second);
		b[i].pb(it++->first);
	}
	
	sort(b,b+m.size());
	cout<<m.size()<<"\n";
	for(int i=0;i<m.size();i++)cout<<b[i][1]<<" ";
	
}
int main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	read();
	solve();
}


