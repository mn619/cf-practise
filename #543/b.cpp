#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, a[1001];

map <int, set<int>> s;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	int ans = 0;

 	cin>>n;
 	fr(i, 1, n + 1){
 		cin>>a[i];
 		fr(j, 1, i){
 			if(s[a[i] + a[j]].count(a[i]) || s[a[i] + a[j]].count(a[j])){
 				continue;
 			}
 			s[a[i] + a[j]].insert(a[i]);
 			s[a[i] + a[j]].insert(a[j]);
 			ans = max(ans, (int)s[a[i] + a[j]].size());
 		}
 	}

 	cout<<ans/2;
}