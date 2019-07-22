#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, b[maxn + 1];
map <int, int> cnt;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>n;
	fr(i, 1, n + 1){
		cin>>b[i];
		cnt[b[i]]++;
	} 		

	sort(b + 1, b + n + 1);
	if(b[1] != b[n])
		cout<<b[n] - b[1]<<" "<<cnt[b[n]]*cnt[b[1]];
	else cout<<0<<" "<<cnt[b[1]]*(cnt[b[n]] - 1)/2;
}