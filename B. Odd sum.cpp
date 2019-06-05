#include<bits/stdc++.h>
using namespace std;
#define file freopen("/home/aman/Desktop/testing/in", "r", stdin); freopen("/home/aman/Desktop/testing/out", "w", stdout);

int main()
{
	#ifndef ONLINE_JUDGE
	file
	#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int n, inf = 100000;
	cin>>n;
	int a[n + 1];
	int odd = -inf*100, eve = -inf*100;
	for(int i = 1; i<=n; i++)
	{
		cin>>a[i];
	}

	for(int i = 1; i<=n;i++)
	{
		int o = odd, e = eve;
		if(a[i]&1)
		{
			odd = max(max(o,a[i]), e + a[i]), eve = max(eve, o + a[i]);
		}
		else
		{
			eve = max(max(e,a[i]), eve + a[i]), odd = max(o, a[i] + o);
		}
	}
	cout<<odd<<'\n';

}