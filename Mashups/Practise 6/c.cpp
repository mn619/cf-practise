#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

string s;
int m, ans[10001], l[301], r[301], k[301];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH


 	cin>>s>>m;
 	int n = s.size();


 	fr(i, 1, n + 1){
 		ans[i] = i;
 	}


 	fr(i, 1, m + 1){
 		cin>>l[i]>>r[i]>>k[i];
 	}

 	map <int ,char> mp;
 	fr(i, 1, n + 1){
 		fr(j, 1, m + 1){
 			if(l[j] <= ans[i] and ans[i] <= r[j]){
 				ans[i] = l[j] + (ans[i] - l[j] + k[j])%(r[j] - l[j] + 1);
 			} 
 		}

 		mp[ans[i]] = s[i - 1];
 	}

 	for(auto x: mp){
 		cout<<x.second;
 	}

}