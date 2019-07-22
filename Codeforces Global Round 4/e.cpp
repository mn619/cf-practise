#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 1000000

using namespace std;

string s;
bool in[maxn + 1];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>s;
 	int n = s.size();

 	int l = 0, r = n - 1;
 	
 	

 	while(l <= r){
 		if(s[l] == s[r]){
 			in[l] = in[r] = 1;
 			r--;
 			l++;
 		}
 		else if(s[l + 1] == s[r] and l + 1 <= r){
 			in[l + 1] = in[r] = 1;
 			l = l + 2;
 			r--;
 		}
 		else if(s[r - 1] == s[l] and l <= r - 1){
 			in[r - 1] = in[l] = 1;
 			r = r - 2;
 			l++;
 		}
 		else{
 			l++, r--;
 		}
 	}


 	fr(i, 0, n){
 		if(in[i]) cout<<s[i];
 	}

}