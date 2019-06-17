#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
int n, m;
set <int> in;
vector<pair<int, int>> s[100001];
bool ok[100001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;

 	fr(i, 1, m + 1){
 		int l;
 		cin>>l;

 		fr(j, 1, l + 1){
 			int x;
 			cin>>x;
 			s[j].pb({x, i});
 		}
 	}


 	fr(i, 1, 100001){
 		int len = s[i].size();
 		fr(j, 0, len - 1){
 			if(s[i][j].second < s[i][j + 1].second - 1 || ok[s[i][j].second]) continue;
 			if(s[i][j].first < s[i][j + 1].first) ok[s[i][j].second] = 1;
 			else if(s[i][j].first > s[i][j + 1].first){
 				in.insert(s[i][j].first)
 			}
 		}
 	}

}