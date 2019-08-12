#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, q, a[maxn + 1], upd[maxn + 1];

vector <pair<int, int>> v;
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	fr(i, 1, n + 1) cin>>a[i];

 	cin>>q;

 	int las = 0, mx = 0;


 	fr(i, 1, q + 1){
 		int t;
 		cin>>t;
 		if(t == 1){
 			int p, x;
 			cin>>p>>x;

 			a[p] = x;
 			upd[p] = i;
 		}
 		else{
 			int x;
 			cin>>x;

 			v.pb({i, x});
 		}
 	}

 	int len = v.size();
 	for(int i = len - 2; i >= 0; i--){
 		v[i].second = max(v[i].second, v[i + 1].second);
 	}

 	fr(i, 1, n + 1){
 		int u = upd[i];
 		int l = 0, r = len - 1;
 		int ans = -1;
 		//cout<<upd[i]<<" ";
 		while(l <= r){
 			int mid = (l + r)/2;
 			if(v[mid].first >= upd[i]){
 				r = mid - 1;
 				ans = mid;
 			}
 			else l = mid + 1;
 		}
 		
 		if(ans == -1) cout<<a[i]<<' ';
 		else
 		cout<<max(v[ans].second, a[i])<<" ";
 	}


 	
}