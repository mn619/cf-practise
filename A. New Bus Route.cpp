#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define file freopen("/home/aman/Desktop/testing/in", "r", stdin); freopen("/home/aman/Desktop/testing/out", "w", stdout);

int main()
{
	#ifndef ONLINE_JUDGE
	file
	#endif

	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	ll a[n + 1];
	ll cnt = 0, val = (ll)2*10000*100005;

	for(int i = 1; i<=n; i++)
	{
		cin>>a[i];
	}

	sort(a + 1, a+ n+ 1);

	for(int i = 2; i<=n; i++)
	{
		if(a[i] - a[i- 1] == val)
		{
			cnt++;
		}
		else if(a[i] - a[i- 1] < val)
		{
			cnt = 1, val =a[i] - a[i - 1];
		}
	}

	cout<<val<<" "<<cnt;

}