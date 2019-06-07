#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int k, cnt[10];
string n;


signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>k>>n;
 	int l = n.size();

 	int sm = 0;
 	fr(i, 0, l){
 		sm += n[i] - '0';
 		cnt[n[i] - '0']++;
 	}

 	int req = k - sm;
 	int ans = 0;

 	fr(i ,0, 10){
 		fr(j, 0, cnt[i]){
 			if(req <= 0 ) break;
 			req -= 9 - i;
 			ans++;
 		}	
 		if(req <= 0) break;
 	}
 	
 	cout<<ans;

}