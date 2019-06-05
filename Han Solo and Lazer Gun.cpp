#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define f(p,n) for(int i=p;i<n;i++)
#define mp make_pair

using namespace std;
int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
	
}
signed main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,a,b;
	
	cin>>n>>a>>b;
	
	int x[n],y[n];
	map <pair <int,int>,int > m;
	
	f(0,n)
	{
		cin>>x[i]>>y[i];
		int g=gcd(y[i]-b,x[i]-a);
		
		x[i]=(x[i]-a)/g;
		y[i]=(y[i]-b)/g;
		
		m[mp (x[i],y[i])]=1;
	}
	
	cout<<m.size();
}


