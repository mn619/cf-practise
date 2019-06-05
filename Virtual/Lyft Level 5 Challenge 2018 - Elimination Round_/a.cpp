#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n;
int ax, ay, bx, by, cx, cy;
bool in[1001][1001];


void dfs(int x, int y){
	if(x == ax || y == ay || in[x][y] || abs(x - ax) == abs(y - ay)) return;
	in[x][y] = 1;
	if(x - 1 >= 1) dfs(x - 1, y);
	if(y - 1 >= 1) dfs(x, y - 1);
	if(x + 1 <= n) dfs(x + 1, y);
	if(y + 1 <= n) dfs(x, y + 1);
	if(x - 1 >= 1 and y - 1 >= 1) dfs(x - 1, y  - 1);
	if(x + 1 <= n and y - 1 >= 1) dfs(x + 1, y - 1);
	if(x - 1 >= 1 and y + 1 <= n) dfs(x - 1, y + 1);
	if(x + 1 <= n and y + 1 <= n) dfs(x + 1, y + 1);
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>ax>>ay>>bx>>by>>cx>>cy;
 	dfs(bx, by);


 	if(in[cx][cy]) cout<<"YES";
 	else cout<<"NO";

}