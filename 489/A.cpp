#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;
int n;

signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	set <int> s;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		if(a!=0)s.insert(a);
	}
	
	cout<<s.size();
}



