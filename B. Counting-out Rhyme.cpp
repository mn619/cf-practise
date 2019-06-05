#include<bits/stdc++.h>
using namespace std;
#define file freopen("/home/aman/Desktop/testing/in", "r", stdin); freopen("/home/aman/Desktop/testing/out", "w", stdout);

int main()
{
	#ifndef ONLINE_JUDGE
	file
	#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, k;
	cin>>n>>k;
	int a[n+ 1];
	std::vector<int> v;
	for(int i = 0; i<n;i++) v.push_back(i + 1);

	for(int i = 1; i<=n; i++)
	{
		cin>>a[i];
	}

	int l = 0;
	for(int i = 1; i<=k; i++)
	{
		int s = a[i]%v.size();
		l = (l + s)%v.size();

		cout<<v[l]<<" ";
		v.erase(v.begin() + l);
		l %= v.size();

	}
}