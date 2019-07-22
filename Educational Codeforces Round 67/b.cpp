#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int cnt[maxn + 1][26], n;
string s;


int solve(string t){
	int l = 1, r = n, ans = n, cntT[26]  = {0};
	fr(i, 0, t.size()){
		cntT[t[i] - 'a']++;
	}

	while(l <= r){
		int mid = (l + r)/2;
		bool ok = 1;
		fr(j, 0, 26){
			if(cnt[mid][j] < cntT[j]){
				ok = 0;
				break;
			}
		}

		if(ok){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}


signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	cin>>s;
 	reverse(s.begin(), s.end());
 	s += '%';
 	reverse(s.begin(), s.end());

 	fr(i, 1, n + 1){
 		fr(j, 0, 26) cnt[i][j] = cnt[i - 1][j];
 		cnt[i][s[i]  - 'a']++;
 	}
	
	int m;
	cin>>m;

	fr(i, 1, m + 1){
		string t;
		cin>>t;
		cout<<solve(t)<<'\n';
	}	 	
}