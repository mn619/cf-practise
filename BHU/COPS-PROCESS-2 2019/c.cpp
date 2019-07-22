#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 100000
using namespace std;

int k, cnt[maxn][26];
string s;
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>k>>s;
 	int n = s.size();
 	reverse(s.begin(), s.end());
 	s += '$';
 	reverse(s.begin(), s.end());
 	
 	if(k >= n) return cout<<n, 0;

 	fr(i, 1, n + 1){
 		fr(j, 0, 26){
 			cnt[i][j] = cnt[i - 1][j];
 		}
 		cnt[i][s[i] - 'a']++;
 	}

 	int ans = 0;
 	fr(j, 0, 26){
 		int ans1 = 0;

 		fr(i, 1, n + 1){
 			int l = i, r = n;
 			while(l <= r){
 				int mid = (l + r)/2;
 				int len = mid - i + 1;

 				int req = len - (cnt[mid][j] - cnt[i - 1][j]);
 				if(req <= k){
 					ans1 = max(ans1, len);
 					l = mid + 1;
 				}
 				else{
 					r = mid - 1;
 				}
 			}
 		}
 		ans = max(ans, ans1);
 	}

 	cout<<ans;
}