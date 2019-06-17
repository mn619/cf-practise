#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m, a[36], ans = 0;
vector <int> s1, s2;

vector<int>  getsm(vector<int> v){
	int  l = v.size();
	vector <int> res;
	set <int> s;
	fr(i, 0, (1<<l)){
		int t = i, sm = 0,cnt = 0;
		while(t){
			if(t&1) sm += v[cnt];
			cnt++;
			t /= 2;
			sm %= m;
		}
		sm %= m;
		s.insert(sm);
		ans = max(ans, sm);
	}

	for(auto x: s) res.pb(x);
	return res;
}


signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>n>>m;
	int sm = 0;

	fr(i, 1, n + 1){ cin>>a[i]; sm += a[i]; a[i]%=m; }
	if(sm < m) return cout<<sm, 0;

	vector<int> v1, v2;
	v1.pb(0), v2.pb(0);

	fr(i, 1, min((int) 18, n) + 1){
		v1.pb(a[i]);
	}

	fr(i, 19, n + 1){
		v2.pb(a[i]);
	}

	s1 = getsm(v1), s2 = getsm(v2);

	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	int l1 = s1.size();
	int p2 = l1 - 1, p1 = 0;

	while(p1 < l1 - 1 and s1[p1 + 1] > s1[p1]) p1++;

	for(auto x: s2){
		while(p1 > 0 and (s1[p1] + x) > m) p1--;
		while(p2 > 0 and (s1[p2] + x) > m) p2--;

		ans = max(ans, max((x + s1[p1])%m, (x + s1[p2])%m));
	}

	cout<<ans;

}