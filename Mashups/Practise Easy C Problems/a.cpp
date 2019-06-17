#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
int n, m;
int p[101];
map <string, int> mp;
vector<int> cnt;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;
 	fr(i, 1, n + 1) cin>>p[i];
 	sort(p + 1, p + n + 1);

 	fr(i, 1, m + 1){
 		string x;
 		cin>>x;
 		mp[x]++;
 	}

 	for(auto x: mp){
 		cnt.pb(x.second);
 	}

 	sort(cnt.begin(), cnt.end());
 	int l = cnt.size();

 	int mn = 0, mx = 0;

 	fr(i, 0, l){
 		mn += cnt[i]*p[l - i];
 	}	

 	reverse(p + 1, p + n + 1);
 	reverse(cnt.begin(), cnt.end());

 	fr(i, 0, l){
 		mx += p[i + 1]*cnt[i];
 	}


 	cout<<mn<<" "<<mx; 

 	
}