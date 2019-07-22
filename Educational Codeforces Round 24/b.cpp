#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int l[101], d[101], a[101], n, m;


bool check(){
	set <int> s;
	fr(i, 1, n + 1) a[i] = 0, s.insert(i);
	map <int, int> mp, inv;

	fr(i, 1, m){
		a[l[i]] = (l[i + 1] - l[i] + n)%n;
		if(a[l[i]] == 0) a[l[i]] = n;
		if(mp.count(a[l[i]])){
			if(mp[a[l[i]]] != l[i]) return 0;
		}
		if(inv.count(l[i])){
			if(inv[l[i]] != a[l[i]]) return 0;
		}

		mp[a[l[i]]] = l[i];
		inv[l[i]] = a[l[i]];

		s.erase(a[l[i]]);
	}

	fr(i, 1, n + 1){
		if(a[i] == 0){
			a[i] = *s.begin();
			s.erase(a[i]);
		}
	}

	return 1;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>n>>m;
 	

 	fr(i, 1, m + 1){
 		cin>>l[i];
 	}
 	bool ok = 0;


 	ok = check();

 	if(ok){
 		set <int> s;
 	 	fr(i, 1, n + 1){
 	 		s.insert(a[i]);
 	 	}
 	 	assert(s.size() == n);
 	 	fr(i, 1, n + 1) cout<<a[i]<<" ";
 	}
	else cout<<-1;
}