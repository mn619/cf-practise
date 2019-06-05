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
	int p = 1;

	int cnt = 0;
	int n1 = n;
	for(int i = 2; i <= n; i++)
	{
		while(n1%i == 0) cnt++, n1/=i;
	}

	if(cnt < k) return cout<<-1,0;
	n1 = n;
	for(int i = 2; i <= n; i++)
	{
			while(n1%i == 0)
			{
				if(k == 1) break;
				cout<<i<<" ";
				p*=i;
				n1/=i;
				k--;
			}

		if(k == 1) break;
	}

	cout<<n/p<<'\n';

}