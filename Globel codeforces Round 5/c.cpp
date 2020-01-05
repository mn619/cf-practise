#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000
#define pii pair<int, int> 
using namespace std;

int n;

map <pair<int, pii>, int> m;
map <int, int> cntx;
map <pii, int> cnty;
map <pair<int, pii>, int> cntz;
map <int, set<int>> y, z;
set<int> x;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	//FLASH

 	cin>>n;
 	fr(i, 1, n + 1){
 		int a, b, c;;
 		cin>>a>>b>>c;
 		m[{a,{b, c} }] = i;
 		cntx[a]++;
 		cnty[{a, b}]++;
 		cntz[{a, {b, c}}]++;
 		x.insert(a);
 		y[a].insert(b);
 		z[b].insert(c);
 	}

 	while(!x.empty()){
 		int x0 = *(x.begin());
 		int x1, y0, y1, z0, z1;
 		if(cntx[x0] > 1){
 			x1 = x0;
 		}
 		else{
 			auto it = x.begin();
 			it++;
 			x1 = *it;
 		}

 		if(x0 == x1){
 			y0 = *(y[x0].begin());
 			if(cnty[{x0, y0}] > 1){
 				y1 = y0;
 			}
 			else{
 				auto it = y[x0].begin();
 				it++;
 				y1 = *it;
 			}
 		}
 		else{
 			y0 = *(y[x0].begin());
 			y1 = *(y[x1].begin());
 		}

 		if(y0 == y1){
 			z0 = *(z[y0].begin());
 			if(cntz[z0] > 1){
 				z1 = z0;
 			}
 			else{
 				auto it = z[y0].begin();
 				it++;
 				z1 = *it;
 			}
 		}
 		else{
 			z0 = *(z[y0].begin());
 			z1 = *(z[y1].begin());
 		}


 		cout<<x0<<" "<<y0<<" "<<z0<<' '<<x1<<" "<<y1<<" "<<z1<<' '<<cnty[y0]<<'\n';

 		cntx[x0]--;
 		cntx[x1]--;
 		cnty[y0]--;
 		cnty[y1]--;
 		cntz[z0]--;
 		cntz[z1]--;

 		if(cntx[x0] == 0){
 			x.erase(x0);
 		}
 		if(cntx[x1] == 0){
 			x.erase(x1);
 		}
		if(cnty[y0] == 0){
 			y.erase(y0);
 		}
 		if(cnty[y1] == 0){
 			y.erase(y1);
 		}

 		if(cntz[z0] == 0){
 			z.erase(z0);
 		}
 		if(cntz[z1] == 0){
 			z.erase(z1);
 		}

 		cout<<m[{x0, {y0, z0}}]<<" "<<m[{x1, {y1, z1}}]<<'\n';
 	}
 	
}