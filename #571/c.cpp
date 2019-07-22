#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 1000000

using namespace std;


string a,b;
int pre[maxn + 1];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>a>>b;
 	int z = 0, o = 0;
 	fr(i, 0, b.size()){
 		if(b[i] == '0') z++;
 		else o++;
 	}

 	fr(i, 0, a.size()){
 		if(a[i] == '1'){
 			pre[i]++;
 		}
 		if(i > 0) pre[i] += pre[i - 1];
 	}

 	int k = b.size();
 	int ans = 0;

 	fr(i, k - 1, a.size()){
 		if(i == k - 1){
 			if((pre[i]&1) == (o&1)) ans++;
 		}
 		else{
 			if(((pre[i] - pre[i - k])&1) == (o&1)) ans++;
 		}
 	}

 	cout<<ans;

}