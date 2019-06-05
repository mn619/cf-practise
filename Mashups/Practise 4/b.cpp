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

 	int k;
 	string q;
 	cin>>k>>q;

 	set <char> s;
 	vector <string> v;
 	string x = "";
 	x += q[0];
 	
 	s.insert(q[0]);

 	fr(i, 1, q.size()){
 		if(s.find(q[i]) == s.end()){
 			v.pb(x);
 			x = "";
 			s.insert(q[i]);
 		}
 		x += q[i];
 	}

 	v.pb(x);


 	if(k > v.size()) cout<<"NO";
 	else{
 		cout<<"YES\n";
 		fr(i, 0, k - 1) cout<<v[i]<<"\n";
 		fr(i, k-1, v.size()) cout<<v[i];
 	}

}