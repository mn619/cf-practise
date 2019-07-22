#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int m[10], s[10], p[10];

void update(char a, char b){
	if(b == 'm'){
 		m[a - '0']++;
 	}
 	else if(b == 's'){
 		s[a - '0']++;
 	}
 	else if(b == 'p'){
 		p[a - '0']++;
 	}
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	fr(i, 1, 4){
 		char a, b;
 		cin>>a>>b;
 		update(a, b);
 	}

 	fr(i, 1, 10){
 		if(m[i] == 3 || s[i] == 3 || p[i] == 3) return cout<<0, 0;
 	}

 	fr(i, 1, 8){
 		if(m[i] != 0 and m[i + 1] != 0 and m[i + 2] != 0) return cout<<0, 0;
 		if(s[i] != 0 and s[i + 1] != 0 and s[i + 2] != 0) return cout<<0, 0;
 		if(p[i] != 0 and p[i + 1] != 0 and p[i + 2] != 0) return cout<<0, 0;
 	}


 	fr(i, 1, 10){
 		if(m[i] == 2 || s[i] == 2 || p[i] == 2) return cout<<1, 0;
 	}

 	fr(i, 1, 9){
 		if(m[i] != 0 and m[i + 1] != 0) return cout<<1, 0;
 		if(s[i] != 0 and s[i + 1] != 0) return cout<<1, 0;
 		if(p[i] != 0 and p[i + 1] != 0) return cout<<1, 0;
 	}

 	
 	fr(i, 1, 8){
 		if(m[i] != 0 and m[i + 2] != 0) return cout<<1, 0;
 		if(s[i] != 0 and s[i + 2] != 0) return cout<<1, 0;
 		if(p[i] != 0 and p[i + 2] != 0) return cout<<1, 0;
 	}
 	
 	cout<<2;
}