#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 1000000
using namespace std;

int k, n;
string s;
int pre[maxn], nex[maxn];


signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>k>>s;
 	n = s.size();
 	int ans = 0;
 	
 	if(k == 0){
 		int cnt = 0;
 		fr(i, 0, n){
 			if(s[i] == '1'){
 				ans += cnt*(cnt + 1)/2;
 				cnt = 0;
 			}
 			else cnt++;
 		}
 		ans += cnt*(cnt + 1)/2;
 		cout<<ans;
 		return 0;
 	}
 
 	

 	fr(i, 0, n){
 		if(s[i] == '1') pre[i]++;
 		pre[i] += pre[i - 1];
 	}

 	int las = n;
 	for(int i = n - 1; i >= 0; i--){
 		if(s[i] == '1'){
 			las = i;
 		}
 		nex[i] = las;
 	}
 	int l = 0;

 	fr(i, 0, n){
 		if(pre[i] == k){
 			ans += nex[0] + 1;
 		}
 		else if(pre[i] > k){
 			if(s[i] == '1'){
 				l = nex[l] + 1;
 			}
 			ans += nex[l] - l + 1;
 		}
 		cout<<ans<<"\n";
 	}

 	cout<<ans;
}	