#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define f(p,n) for(int i=p;i<n;i++)
#define mp make_pair
using namespace std;

signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,mm,k;
	cin>>n>>mm>>k;
	
	int x[k],y[k];
	map <pair <int,int> ,int > m;
	
	int count=0;
	bool b=0;
	
	for(int a=0;a<k;a++)
	{
		cin>>x[a]>>y[a];
		int i=x[a],j=y[a];
		count++;
		
		m[mp (i,j)]=1;
		
		if((m[mp(i-1,j)]&&m[mp(i-1,j-1)])&&m[mp(i,j-1)]) {b=1; break;}
		if((m[mp(i-1,j)]&&m[mp(i-1,j+1)])&&m[mp(i,j+1)]) {b=1; break;}
		if((m[mp(i,j+1)]&&m[mp(i+1,j+1)])&&m[mp(i+1,j)]) {b=1; break;}
		if((m[mp(i+1,j)]&&m[mp(i+1,j-1)])&&m[mp(i,j-1)]) {b=1; break;}
		
	}
	
	if(b==0) cout<<0<<"\n";
	else cout<<count<<"\n";
}


