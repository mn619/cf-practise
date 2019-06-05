#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int l;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>l;
 	int maxn = 1;
 	fr(i, 1, 33) maxn *= 2;
 	maxn--;


 	int ans = 0, p = 0;
 	stack <pair<int, int>> fs;

 	fr(i, 1, l + 1){
 		string cm;
 		cin>>cm;
 		if(cm == "for"){
 			int t;
 			cin>>t;
 			fs.push({t, 0});
 			if(ans + p*t > maxn || ans + p*t < 0) return cout<<"OVERFLOW!!!\n", 0;
 		}
 		else if(cm == "add"){
 			if(fs.empty()){
 				ans++;
 			}
 			else{
	 			pair <int ,int> p = fs.top();
	 			fs.pop();
	 			p.second++;
	 			fs.push(p);
 			}
 		}
 		else{
 			p = (p + fs.top().second)*fs.top().first;
 			fs.pop();
 		}
 		if(fs.empty()){ans += p; p = 0;}
 		if(ans + p > maxn || ans + p < 0) return cout<<"OVERFLOW!!!\n", 0;
 	}
 	if(ans > maxn) return cout<<"OVERFLOW!!!\n", 0;
 	cout<<ans<<'\n';
}