#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m, mx[200001];
vector <int> v[200001], ans;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>n>>m;
 	fr(i, 1, n + 1){
 		int a, b;
 		cin>>a>>b;
 		v[i].pb(a);
 		v[i].pb(b);
 		v[i].pb(i);
 	}

 	sort(v + 1, v + n + 1);
 	mx[1] = 1;
 	fr(i, 2, n + 1){
 		mx[i] = mx[i - 1];
 		if(v[i][1] > v[mx[i - 1]][1]) mx[i] = i;
 	}

 	if(v[1][0] > 1) return  cout<<"NO", 0;
 	
 	int pos = 1, lpos = 0;
 	while(pos <= m){
 		while(1){
 			if(lpos + 1 <= n and v[lpos + 1][0] <= pos) lpos++;
 			else break;
 		}
 		int ind = mx[lpos];
 		
 		if(v[ind][1] < pos) return cout<<"NO\n", 0;
 		else{
 			ans.pb(v[ind][2]);
 			pos = v[ind][1] + 1;
 		}
 	}

 	cout<<"YES\n";
 	cout<<ans.size()<<'\n';
 	for(auto x: ans)
 		cout<<x<<" ";	
}