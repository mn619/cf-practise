#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;


int n, k, dp[2][maxn];
char c[2][maxn];
vector<pair<int, int>> v[2][maxn];

signed main()
{
	//FILEIO
 	FLASH

 	cin>>n>>k;
 	
 	for(int i = 0; i <= 1; i++){
 		for(int j = 1; j <= n; j++){cin>>c[i][j]; dp[i][j] = inf;}
 	}

 	for(int j = 1; j <= n; j++){
 		for(int i = 0; i <= 1; i++){
 			if(c[i][j] == 'X') continue;

 			if(c[i][j - 1] == '-'){
 				v[i][j].push_back({i, j - 1});
 			}

 			if(c[i][j + 1] == '-'){
 				v[i][j].push_back({i, j + 1});
 			}

 			if(j + k <= n and c[!i][j + k] == '-'){
 				v[i][j].push_back({!i, j + k});
 			}
 		}
 	}

 	dp[0][1] = 0;

 	queue <pair<int, int>> pq;
 	pq.push({0, 1});

 	while(!pq.empty()){
 		int x = pq.front().first;
 		int y = pq.front().second;
 		pq.pop();
 		
 		if(dp[x][y] < y and y + k > n) return cout<<"YES", 0;

 		for(auto z: v[x][y]){
 			int x1 = z.first, y1 = z.second;
 			if(dp[x1][y1] > dp[x][y] + 1 and dp[x][y] + 1 < y1){
 				dp[x1][y1] = dp[x][y] + 1;
 			 	pq.push({x1, y1});
 			}
 		}
 	}

 	cout<<"NO";
}