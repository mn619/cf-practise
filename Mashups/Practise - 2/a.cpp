#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n, k;
 	cin>>n>>k;
 	set <int> s;
 	bool ok = 1;
 	k = min(k ,(int)100000);
 	if(k >= n) return cout<<"no", 0;
 	fr(i, 1, k + 1){
 		if(s.find(n%i) != s.end()){
 			ok = 0;
 			cout<<i<<" "<<n%i<<'\n';
 			break;
 		}
 		else s.insert(n%i);
 	}

 	if(ok) cout<<"yes";
 	else cout<<"no";
}