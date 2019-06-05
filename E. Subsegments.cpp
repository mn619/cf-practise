#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, k, a[100001];
set <int> s;
map <int ,int> cnt;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>k;
 	fr(i, 1, n + 1) cin>>a[i];

 	fr(i, 1, n + 1){
		cnt[a[i]]++;
		if(cnt[a[i]] == 1) s.insert(-a[i]);
		else if(cnt[a[i]] > 1) s.erase(-a[i]);
		if(i > k){
			cnt[a[i - k]]--;
			if(cnt[a[i - k]] == 1) s.insert(-a[i - k]);
			else if(cnt[a[i - k]] == 0) s.erase(-a[i - k]);		
		}

		if(i >= k){
			if(s.empty()) cout<<"Nothing\n";
			else cout<<-*(s.begin())<<'\n';
		}
 	}
}