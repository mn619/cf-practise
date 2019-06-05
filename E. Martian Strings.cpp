#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

string s, rev;
int m, ans = 0;
int pre[1001], suf[1001];

vector <int> Z(string a){
	int n = a.size();
	vector <int> z(n);
	z[0] = 0;

	int l = -1,  r = -1;

	for(int i = 1; i < n; i++){
		if(i <= r) z[i] = min(r - i + 1, z[i - l]);
		while(i + z[i] < n and a[z[i]] == a[i + z[i]])
			z[i]++;

		if(i + z[i] - 1> r){
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

bool check(string p){
 	int l = p.size();

	string revp = s;
	revp += '|';
	revp += p;
	reverse(revp.begin(), revp.end());

	p += '|';
 	p += s;

 	vector <int> zp = Z(p), zrevp = Z(revp);

 	fr(i, 0, l + 1) {pre[i] = inf; suf[i] = 0;}

 	fr(i, 0, s.size()){
 		pre[zp[i + l + 1]] = min(pre[zp[i + l + 1]], i);
 		suf[zrevp[i + l + 1]] = max(suf[zrevp[i + l + 1]], (int)s.size() - i - 1);
 	}

 	for(int i = l - 1; i >=1; i--){
 		pre[i] = min(pre[i + 1], pre[i]);
 		suf[i] = max(suf[i + 1], suf[i]);
 	}

 	fr(i, 1, l){
 		if(suf[l - i] - pre[i] + 1 >= l) return true;
 	}
 	return false;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

  	cin>>s>>m;
  	
 	rev = s;
 	reverse(rev.begin(), rev.end());

 	while(m--){
 		string p;
 		cin>>p;
 		ans += check(p);
 	}
 	cout<<ans;
}