#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
// #define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, k, a[501];
vector <bool> b(501);
set<int> s;

void solv1(){
	int cnt = 0, pos, apos;

	while(n - s.size() >= k){
		cnt = 0;
		cout<<"? ";
		fr(i, 1, n + 1){
			if(b[i] == 0) cout<<i<<" ";
			cnt++;
			if(cnt == k) break;
		}
		cout<<'\n';
		cin>>pos>>apos;
		a[pos] = apos;
		b[pos] = 1;
		s.insert(pos);
	}
	vector <int> v;
	cout<<"? ";
	for(auto x: s) {cout<<x<<" "; v.pb(x);}
	cin>>pos>>apos;
	sort(v.begin(), v.end());
	fr(i, 0, v.size()){
		if(v[i] == pos) cout<<"! "<<i + 1<<'\n';
	}
}


signed main()
{
	#ifndef ONLINE_JUDGE
	// FILEIO
	#endif
 	FLASH

	cin>>n>>k;

 	solv(); 
		
}