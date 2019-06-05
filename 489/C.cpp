#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long int
#define mp make_pair
#define mod 1000000007

using namespace std;
int x,k;

int power(int a, int b)
{
	if (b==0)
	return 1;
	int temp = power(a,b/2)%mod;
	temp = (temp*temp)%mod;
	if (b&1)
	return (temp*(a%mod))%mod; 
	return temp%mod;
}

signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>x>>k;
	if(x==0)return cout<<0,0;
	x%=mod;
	cout<<(power(2,k)%mod*((2*x%mod+mod-1)%mod)+1)%mod;
}



