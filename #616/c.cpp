#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 400000
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

int c[maxn];

bool comp(int a, int b){

}
signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH


 	int n, k;

 	cin>>n>>k;

 	vector <int> v[n + 1];
 	string s;
 	cin>>s;

 	fr(i, 1, k + 1){
 		int c;
 		cin>>c;
 		vector <int> temp;
 		fr(j, 1, c + 1){
 			int x;
 			cin>>x;
 			temp.pb(x);
 			v[x].pb(i);
 		}

 		sort(all(temp));
 		int l = 0, r = (int)temp.size() - 1;

 		int ans = 0
 		

 	}

 	int ans = 0;

 	set <int> in;

 	fr(i, 1, n + 1){
 		bool b = (s[i - 1] == '1');
 		for(auto x: v[i]){
 			if(in.count(x)){
 				b ^= 1;
 			}
 		}

 		if(b){
 			cout<<ans<<'\n';
 		}
 		else{
 			for(auto x: v[i]){
 				if(!in.count(x)){
 					in.insert(x);
 					b = 1;
 					ans++;
 					break;
 				}
 			}

 			cout<<ans<<'\n';
 		}
 	}

}