#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int mx = 0, mn = 33;

	for(int i = 1; i <= n; i++){
		int a;
		cin>>a;

		mx = max(mx, a);
		mn = min(mn, a);
	}

	cout<<mx - mn;
}