#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, u[100001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	fr(i, 1, n + 1){
 		cin>>u[i];
 	}


 	map <int, int> c;
 	map<int, int> sz; 
 	int ans = 0;

 	fr(i, 1, n + 1){ 
 		if(c.count(u[i])){		
	 		if(sz.count(c[u[i]])){
	 			sz[c[u[i]]]--;
	 			if(sz[c[u[i]]] == 0){
	 				sz.erase(c[u[i]]);
	 			}
	 		}
 		}

 		c[u[i]]++;
 		sz[c[u[i]]]++;

 		if(sz.size() == 2){
 			auto it = sz.begin();
 			auto it2 = it;
 			it2++;

 			if(((*it2).first == 1 + (*it).first and (*it2).second == 1) || ((*it).first == 1 and (*it).second == 1)) ans = i;
 		}
 		else if(sz.size() == 1){
 			if((*sz.begin()).first == 1 || (*sz.begin()).second == 1) ans = i;
 		}

 		cout<<ans<<'\n';
 	}

 	cout<<ans;
}