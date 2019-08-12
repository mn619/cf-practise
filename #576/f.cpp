#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, cnt = 0;
int c[51][51];


int sum(int p, int q, int r, int s){
	p--;
	q--;
	return c[r][s] - c[p][s] - c[r][q] + c[p][q];
}

int check(int l){

	int in = 0, ans = 0;
	fr(i, l, n + 1){
		fr(j, l, n + 1){
			in += sum(i - l + 1, j - l + 1, i, j);
			ans += l;
			if(in >= cnt) return ans;
		}
	}

	return ans;
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	fr(i, 1, n + 1){
 		fr(j, 1, n + 1){
 			char x;
 			cin>>x;
 			c[i][j] = c[i][j - 1];
 			if(x == '#'){
 				cnt++;
 				c[i][j]++;
 			}
 		}
 	}

 	if(cnt == 0) return cout<<0,0;
 	fr(i, 1, n + 1){
 		fr(j, 1, n + 1){
 			c[i][j] += c[i - 1][j];
 		}
 	}
 	int ans = n;

 	fr(i, 1, n + 1){
 		cout<<check(i)<<"\n";
 		
 		ans = min(ans, check(i));
 	}
 	cout<<ans;
}