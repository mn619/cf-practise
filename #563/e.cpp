#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n = 7;
int a[1000];

int g(){
	int g = a[0];
	set <int> s;
	s.insert(a[0]);
	fr(i, 1, n){
		g = __gcd(g, a[i]);
		s.insert(g);
	}
	return s.size();
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH


	fr(i, 0, n) a[i] = i + 1;
	int cnt = 0, mx = 0;
	do{
		//fr(i, 0, n) cout<<a[i]<<' ';
		//cout<<'\n';
		int t = g();
		if(t > mx){
			mx = t;
			cnt = 1;
		}
		else if(t == mx) cnt++;		
	}
	while(next_permutation(a, a + n));


	fr(i, 0, n) a[i] = i + 1;
	do{
		int t = g();
		if(t == mx){
			fr(i, 0, n) cout<<a[i]<<' ';
			cout<<'\n';
		}		
	}
	while(next_permutation(a, a + n));


	cout<<cnt<<"\n";
}