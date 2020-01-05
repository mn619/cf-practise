#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;


int n, a[maxn], b[maxn];
map <int ,int> m;
bool in[maxn];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i, 1, n + 1){
 		cin>>a[i];
 		m[a[i]] = i;
 	}
 	fr(i, 1, n + 1){
 		cin>>b[i];
 		b[i] = m[b[i]];
 	}

 	int cur = 1, ans = 0;
 	fr(i, 1, n + 1){
 		in[b[i]] = 1;
 		if(b[i] != cur){
 			ans++;
 		}
 		while(in[cur]) cur++;
 	}
 	cout<<ans<<'\n';



}