#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, x1, x2, a;
string s;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>n>>s;

 	fr(i, 0, n){
 		if(i < n/2){
 			if(s[i] == '?') x1++;
 			else a += (s[i] - '0');
 		}
 		else{
 			if(s[i] == '?') x2++;
 			else a -= (s[i] - '0');
 		}
 	}

 	int t = max(x1, x2) - min(x1, x2);
 	if(a == 0){
 		if(t != 0) {return cout<<"Monocarp", 0;}
 		else return cout<<"Bicarp", 0;
 	}
 	else if(a > 0 and x1 > x2){
 		cout<<"Monocarp\n";
 		return 0;
 	}
 	else if(a < 0 and x1 < x2){
 		cout<<"Monocarp\n";
 		return 0;
 	}
 	if(a < 0 ) a *= -1;
 	if(a == 9*t/2) return cout<<"Bicarp\n", 0;
 	else cout<<"Monocarp";
}