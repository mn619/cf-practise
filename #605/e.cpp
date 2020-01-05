#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

void solv(){
	string s;
	cin>>s;
	int l = 0, u = 0, r = 0, d = 0;
	for(auto x: s){
		if(x == 'L')l++;
		if(x == 'U')u++;
		if(x == 'D')d++;
		if(x == 'R')r++;
	}
	int k1 = min(l, r), k2 =  min(u, d);
	vector<char> v = {'R', 'D', 'L', 'U'};
	if(k1 != 0 and k2 != 0){
		int ans = 2*k1 + 2*k2;
		cout<<ans<<'\n';
		fr(i, 1, k1 + 1) cout<<v[0];
		fr(i, 1, k2 + 1) cout<<v[1];
		fr(i, 1, k1 + 1) cout<<v[2];
		fr(i, 1, k2 + 1) cout<<v[3];
		
		cout<<'\n';
	}
	else if(k1 != 0)
		cout<<"2\nLR\n";
	else if(k2 != 0) 
		cout<<"2\nUD\n";
	else
		cout<<"0\n";
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int q;
 	cin>>q;
 	while(q--) solv();	
}