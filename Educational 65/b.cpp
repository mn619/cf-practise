#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007

using namespace std;

signed main()
{
	
 	

 	int a[] = {4, 8, 15, 16, 23, 42};
 	map <int, set<int>> m;

 	fr(i, 0, 6){
 		fr(j, i + 1, 6){
 			m[a[i]*a[j]].insert(a[i]);
 			m[a[i]*a[j]].insert(a[j]);
 		}
 	}


 	int x1, x2, x3, x4;

 	cout<<"? 1 2\n";
 	cin>>x1;
 	cout<<"? 2 3\n";
 	cin>>x2;
	
	cout<<"? 4 5\n";
 	cin>>x3;
 	cout<<"? 5 6\n";
 	cin>>x4;

 	int ans[7];

 	for(auto y1: m[x1]){
 		for(auto y2: m[x2]){
 			if(y1 == y2){
 				ans[2] = y1;
 			}
 		}
 	}

 	for(auto y1: m[x3]){
 		for(auto y2: m[x4]){
 			if(y1 == y2){
 				ans[5] = y1;
 			}
 		}
 	}


 	int sm = 0;
 	for(auto y: m[x1]){
 		sm += y;
 	}
 	ans[1] = sm - ans[2];

 	sm = 0;
 	for(auto y: m[x2]){
 		sm += y;
 	}
 	ans[3] = sm - ans[2];

 	sm = 0;
 	for(auto y: m[x3]){
 		sm += y;
 	}
 	ans[4] = sm - ans[5];

 	sm = 0;
 	for(auto y: m[x4]){
 		sm += y;
 	}
 	ans[6] = sm - ans[5];


 	cout<<"! ";
 	fr(i, 1, 7) cout<<ans[i]<<" ";
}