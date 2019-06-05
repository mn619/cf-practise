#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, x[20001], y[20001];

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}
map <pair<int, pair<int,int>>, int> m;

int dist(int i, int j)
{
	return (y[i] - y[j])*(y[i] - y[j]) + (x[i] - x[j])*(x[i] - x[j]);
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i,1,n + 1)
 	{
 		cin>>x[i]>>y[i];
 	}

 	fr(i,1,n + 1)
 	{
 		fr(j,1,i)
 		{
 			if(i == j) continue;

 			int p = (y[i] - y[j]), q = x[i] - x[j];
 			
 			if(p < 0 && q < 0) p*= -1, q *= -1;
 			else if(q < 0 && p > 0) p *= -1, q *= -1;

 			int t = gcd(p,q);
 			p /= t;
 			q /= t;
 			m[{dist(i,j), {p,q}}]++;
 		}
 	}

 	int ans = 0;

 	for(auto x: m)
 	{
 		//cout<<x.first.first<<" "<<x.first.second.first<<" "<<x.first.second.second<<" "<<x.second<<"\n";
 		ans += x.second*(x.second - 1)/2;
 	}

 	cout<<ans/2<<"\n";
}