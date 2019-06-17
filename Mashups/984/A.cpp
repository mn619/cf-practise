#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	int n;
	cin>>n;
	ll a[n+1];
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n%2)cout<<a[(n+1)/2];
	else  cout<<a[n/2];
}

