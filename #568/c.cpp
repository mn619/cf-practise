#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m, t[200001], cnt[101];
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;

 	fr(i, 1, n + 1){
 		cin>>t[i];
 	}

 	fr(i, 1, n + 1){
 		int sum = t[i], in = 0;

 		fr(j, 1, 101){
 			if(sum + j > m) break;
 			int take = min((m - sum)/j, cnt[j]);
 			in += take;
 			sum += take*j;
 		}
 		cnt[t[i]]++;
 		cout<<i - 1 - in<<" ";
 	}

}