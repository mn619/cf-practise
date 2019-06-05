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

 	int n;
 	cin>>n;
 	int f[n + 1];
 	set <int> s, s1;

 	fr(i, 1, n + 1){
 		cin>>f[i];
 		if(f[i] == i){
 			s.insert(i);
 		}
 		s1.insert(f[i]);
 	}
 	if(s != s1) return  cout<<-1 , 0;
 	int m = s.size();
 	cout<<m<<'\n';
 	map <int, int> h, hinv;

 	int cur = 0;

 	fr(i, 1, n + 1){
 		if(s.find(i) != s.end()){
 			cur++;
 			h[cur] = i;
 			hinv[i]= cur;
 		}
 	}

 	fr(i, 1, n + 1){
 		cout<<hinv[f[i]]<<" ";
 	}
 	cout<<'\n';
 	fr(i, 1, m + 1){
 		cout<<h[i]<<" ";
 	}




}