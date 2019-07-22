#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int a1, a2, b1, b2;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>a1>>b1>>a2>>b2;

 	int l = max(abs(a2 - a1), abs(b2 - b1));

 	if(a1 != a2 and b1 != b2){
 		if(abs(a2 - a1) != abs(b2 - b1)) return cout<<-1, 0;
 		cout<<a2<<" "<<b1<<" "<<a1<<" "<<b2;
 	}
 	else if(b1 == b2){
 		cout<<a1<<" "<<b1 + l<<" "<<a2<<" "<<b2 + l<<"\n";
 	}
 	else if(a1 == a2){
 		cout<<a1 + l<<" "<<b1<<" "<<a2 + l<<" "<<b2;
 	}

}