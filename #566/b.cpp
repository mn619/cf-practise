#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int h, w, cnt = 0;
set <int> x, y;
bool vis[511][511];
char c[511][511];

void dfs(int i, int j){

	cnt++;

	vis[i][j] = 1;
	
	if(!vis[i + 1][j] and c[i + 1][j] == '*') {dfs(i + 1, j); y.insert(j);}
	if((!vis[i - 1][j]) and c[i - 1][j] == '*') {dfs(i - 1, j); y.insert(j);}
	if(!vis[i][j + 1] and c[i][j + 1] == '*') {dfs(i, j + 1); x.insert(i);}
	if(!vis[i][j - 1] and c[i][j - 1] == '*') {dfs(i, j - 1); x.insert(i);}
}


signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>h>>w;

 	int cnt0 = 0;
 	int nodex, nodey;

 	fr(i, 1, h + 1){
 		fr(j, 1, w + 1){
 			cin>>c[i][j];
 			if(c[i][j] == '*'){
 				cnt0++;
 			}

 		}
 	}

 	nodex = 0, nodey = 0;

 	fr(i, 1, h + 1){	
 		fr(j, 1, w  + 1){
 			if(c[i - 1][j] == '*' and c[i + 1][j] == '*' and c[i][j - 1] == '*' and c[i][j + 1] == '*'){
 				nodex = i, nodey = j;
 			}
 		}
 	}

 	if(cnt0 == 0 || nodex == 0 || nodey == 0) return cout<<"NO", 0;
 	dfs(nodex, nodey);
 	if(cnt != cnt0 || x.size() !=  1 || y.size() != 1) return cout<<"NO", 0;

 	cout<<"YES\n";

}