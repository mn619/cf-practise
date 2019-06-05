#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007

using namespace std;
int n,k;
string s;
signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>k>>s;
	int i;
	int arr[n]={0};
	int cnt[26]={0};
	
	vector <pair<char,int> > v[n];
	
	fr(i,0,n)
	{
		v[i].pb(mp(s[i],i));
	}
	sort(v,v+n);
	
	fr(i,0,min(n,k))arr[v[i][0].second]=1;
	fr(i,0,n)if(arr[i]==0)cout<<s[i];
}



