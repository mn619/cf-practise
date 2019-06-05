#include <iostream>
using namespace std;
#define int long long 

int n, a[100001] = {0}, dp[100001] = {0};

signed main() {

	cin>>n;
	for(int i = 1; i<=n ;i++)
	{
		int x;
		cin>>x;
		a[x]++;
	}
	
	dp[1] = a[1];
	
	for(int i = 2; i<=100000; i++)
	{
		dp[i] = max(i*a[i] + dp[i - 2], dp[i - 1]);
	}
	
	cout<<dp[100000]<<'\n';
	return 0;
}