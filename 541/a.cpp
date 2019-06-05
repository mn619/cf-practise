#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

signed main(){
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	
 	int h1, w1, h2, w2;
 	cin>>w1>>h1>>w2>>h2;
 	if(w1 == w2)
 	{
 		cout<<(h1 + h2)*2 + w1*2 + 4;
 	}
 	else 
 	{
 		cout<<(h1 + h2 +1) + w2 + 1 + h2 + w1 - w2 + h1 + 1+ w1 + 1;
 	}
}