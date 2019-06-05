#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, p[300001], inv[300001], a[300001];
vector <pair<int ,int>> ans;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	fr(i, 1, n + 1){
 		cin>>p[i];
 		a[i] = p[i];
 		inv[p[i]] = i;
 	}

 	fr(i, 1, n + 1){
 		//if(inv[i] == i and p[i] != i) {cout<<i<<"\n"; fr(j, 1, n + 1) cout<<p[j]<<" "<<inv[j]<<'\n'; return 0; continue;}
 		if(p[i] == i) continue;
 		if(2*abs(inv[i] - i) >= n){
 			ans.pb({i, inv[i]});
 		}
 		else{
 			if(i <= n/2){
 				if(inv[i] <= n/2){
 					ans.pb({inv[i], n});
 					ans.pb({i, n});
 					ans.pb({inv[i], n});
 				}
 				else{
 					ans.pb({inv[i], 1});
 					ans.pb({1, n});
 					ans.pb({i, n});
 					ans.pb({1, n});
 					ans.pb({inv[i], 1});
 				}
 			}
 			else{
 				if(inv[i] <= n/2){
 					ans.pb({inv[i], n});
 					ans.pb({1, n});
 					ans.pb({i, 1});
 					ans.pb({1, n});
 					ans.pb({inv[i], n});
 				}
 				else{
 					ans.pb({inv[i], 1});
 					ans.pb({i, 1});
 					ans.pb({inv[i], 1});
 				}
 			}
 		}

 		int temp = inv[i];
 		inv[i] = i;
 		inv[p[i]] = temp;
 		swap(p[i], p[temp]);

 	}

 	cout<<ans.size()<<'\n';
 	for(auto x: ans){
 		cout<<x.first<<" "<<x.second<<"\n";
 		swap(a[x.first], a[x.second]);
 	}

 	//fr(i, 1, n + 1) cout<<a[i]<<" ";
}