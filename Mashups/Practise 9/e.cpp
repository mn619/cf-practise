#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, k;
int a[500001];
map <int, int> cnt;
set <int> s;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>k;
 	int l = 1;
 	int ans = 0, ansl = 0;

 	fr(i, 1, n + 1){
 		cin>>a[i];
 		cnt[a[i]]++;

 		s.insert(a[i]);
 		while(s.size() > k){
 			cnt[a[l]]--;
 			if(cnt[a[l]] <= 0) s.erase(a[l]);
 			l++;
 		}

 		if(ans < i - l + 1){
 			ansl = l;
 		}
 		ans = max(i - l + 1, ans);
 	}
 	cout<<ansl<<" "<<ans + ansl - 1;


}