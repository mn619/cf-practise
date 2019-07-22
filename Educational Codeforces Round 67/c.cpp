#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, m, a[1011], t[1011], l[1011], r[1011];
vector <pair<int ,int>> s;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;
 	fr(i, 1, n + 1) a[i] = n - i + 1;
 	
 	fr(i, 1, m + 1){
 		cin>>t[i]>>l[i]>>r[i];
 		if(t[i] == 1) s.pb({l[i], r[i]});
 	}	

 	sort(s.begin(), s.end());
 	
 	int las = 0, r1 = 0;

 	for(auto x: s){
 		if(x.first > r1){
 			sort(a + las, a + r1 + 1);
 			las = x.first;
 			r1 = x.second;
 		}
 		else r1 = max(r1, x.second);
 	}
 	sort(a + las, a + r1 + 1);

 	fr(i, 1, m + 1){
		if(t[i] == 1){
			fr(j, l[i], r[i]){
				if(a[j] > a[j + 1]) return cout<<"NO\n",0;
			}
		}
		else{
			bool found = 0;
			fr(j, l[i], r[i]){
				if(a[j] > a[j + 1]){
					found = 1;
					break;
				}
			}
			if(!found) return cout<<"NO", 0;
		}
	}

 	cout<<"YES\n";	
	fr(i, 1, n + 1) cout<<a[i]<<" ";
}