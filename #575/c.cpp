#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;


void solv(){
	int n;
	cin>>n;
	vector <pair<int,int>> v[5];
	fr(i , 1, n + 1){
		int x, y, f[5];
		cin>>x>>y;
		fr(j, 1, 5){
			cin>>f[j];
			if(f[j] == 0) v[j].pb({x, y});
		}
	}


	int xmin = -100000, xmax = 100000, ymin = -100000, ymax = 100000;
	for(auto p: v[1]){
		xmin = max(xmin, p.first);
	}
	for(auto p: v[2]){
		ymax = min(ymax, p.second);
	}
	for(auto p: v[3]){
		xmax = min(xmax, p.first);
	}	
	for(auto p: v[4]){
		ymin = max(ymin, p.second);
	}


	if(xmin > xmax || ymin > ymax) cout<<"0\n";
	else cout<<1<<" "<<xmax<<" "<<ymax<<"\n";

}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int q;
 	cin>>q;

 	while(q--) solv();	
}