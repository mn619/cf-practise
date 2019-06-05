#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
int a[2001], b[2001];
vector <pair<int, int>> s1, s2; 

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n, m, x;
 	cin>>n>>m;

 	fr(i, 1, n + 1){
 		cin>>a[i];
 	}

 	fr(i, 1, m + 1) cin>>b[i];
 	cin>>x;

 	fr(i, 1, n + 1){
 		int sm = 0;
 		fr(j, i, n + 1){
 			sm += a[j];
 			s1.pb({sm, j - i + 1});
 		}
 	}

 	fr(i, 1, m + 1){
 		int sm = 0;
 		fr(j, i, m + 1){
 			sm += b[j];
 			s2.pb({sm, j - i + 1});
 		}
 	}


 	sort(s1.begin(),s1.end());
 	sort(s2.begin(), s2.end());

 	int mxlen[s2.size()] = {s2[0].second};

 	fr(i, 1, s2.size()){
 		mxlen[i] = max(mxlen[i - 1], s2[i].second);
 	}
 	int ans = 0;

 	for(auto seg: s1){

 		int l = 0, r = s2.size() - 1;
 		while(l <= r){
 			int mid = (l + r)/2;
 			if(s2[mid].first*seg.first <= x){
 				ans = max(ans, seg.second*mxlen[mid]);
 				l = mid + 1;
 			}
 			else r = mid - 1;
 		}
 	}

 	cout<<ans;
}