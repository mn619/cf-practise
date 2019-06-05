#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

string t, p;
int a[200001], n, inv[200001];


bool check(int x){

	int len = 0;
	fr(i, 0, n){
		if(len == p.size()) return true;
		if(p[len] == t[i] and inv[i + 1] > x) len++;
	}

	return (len == p.size());
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>t>>p;
 	n = t.size();

 	fr(i, 1, n + 1) {cin>>a[i]; inv[a[i]] = i;}

 	int l = 0, r = n;
 	int ans = 0;
 	while(l <= r){
 		int mid = (l + r)/2;
 		if(check(mid)){
 			ans = mid;
 			l = mid + 1;
 		}
 		else r = mid - 1;
 	}

 	cout<<ans;

}