#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, a[100001], b[100001], ans[100001];
vector <int> v[100001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i, 1, n +1 ){
 		cin>>a[i]>>b[i];
 		v[i].pb(a[i]);
 		v[i].pb(b[i]);

 	}
 	sort(v + 1, v + n + 1);

 	fr(i, 1, n + 1){
 		a[i] = v[i][0];
 		b[i] = v[i][1];
 	}

 	int res = n;

 	fr(i, 1, n + 1){

 		int l = 0, r = i;
 		int safe = 0;

 		while(l <= r){
 			int mid = (l + r)/2;
 			if(a[mid] < a[i] - b[i]){
 				safe = mid;
 				l = mid + 1;
 			}
 			else r = mid - 1;
 		}

 		ans[i] = ans[safe] + 1;
 		res = min(res, n - ans[i]);
 	}

 	cout<<res<<"\n";
}