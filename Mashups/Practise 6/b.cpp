#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, s;

map <int, int> B, S;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>s;

 	fr(i, 1, n + 1){
 		char c;
 		int p, q;
 		cin>>c>>p>>q;
 		if(c == 'B'){
 			B[-p] += q;
 		}	
 		else{
 			S[p] += q;
 		}
 	}

 	vector<pair<int, int>> ansS, ansB;
 	int t = s;
 	for(auto x: S){
 		t--;
 		ansS.pb({x.first, x.second});
 		if(t == 0) break;
 	}

 	t = s;
 	for(auto x: B){
 		t--;
 		ansB.pb({-x.first, x.second});
 		if(t == 0) break;
 	}


 	reverse(ansS.begin(), ansS.end());

 	for(auto x: ansS){
 		cout<<"S "<<x.first<<" "<<x.second<<'\n';
 	}

 	for(auto x: ansB){
 		cout<<"B "<<x.first<<" "<<x.second<<'\n';
 	}
}