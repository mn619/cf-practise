#include<bits/stdc++.h>
using namespace std;
#define file freopen("/home/aman/Desktop/testing/in", "r", stdin); freopen("/home/aman/Desktop/testing/out", "w", stdout);

int main()
{
	#ifndef ONLINE_JUDGE
	file
	#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, inf = 10000000;
	cin>>n;
	int a[n + 1], p[n + 2], s[n + 2];
	for(int i = 1; i<=n; i++) cin>>a[i];
	p[0] = -inf;
	s[n + 1] = inf;

	for(int i = 1; i<=n; i++)
	{
		if(a[i] == 0) p[i] = i;
		else p[i] = p[i - 1];
	}

	for(int i = n; i>=1; i--)
	{
		if(a[i] == 0)s[i] = i;
		else s[i] = s[i + 1];
	}


	for(int i = 1; i <=n; i++)
	{
		cout<<min(i - p[i], s[i] - i)<<" ";
	}
}