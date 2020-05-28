#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

void solv(){
	string s;
	cin>>s;
	int n = s.size();

	int l = 3, r = n, ans = 0;
	while(l <= r){
		int mid = (l + r)>>1;
		vector <int> cnt(3, 0);
		bool ok = 0;
		for(int i = 0; i < n; i++){
			cnt[s[i] - '1']++;
			if(i >= mid)cnt[s[i - mid] - '1']--;

			if(cnt[0] != 0 and cnt[1] != 0 and cnt[2] != 0){
				ok = 1;
				break;
			}
		}

		if(ok){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}

	cout<<ans<<'\n';
}
signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

 	int t;
 	cin>>t;
 	while(t--) solv();   
}