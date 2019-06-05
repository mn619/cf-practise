#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
#define maxn 1000000

string s;
int suf[maxn + 1];
int a, b;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>s>>a>>b;

	int p = 1, n = s.size();
	for(int i = n - 1; i >= 0; i--){
		suf[i] = (suf[i + 1] + p*(s[i] - '0'))%b;		
		p *= 10;
		p %= b;
 	}
 	p = 10;
 	int pre = 0;
 	int ind = -1;
 	for(int i = 0; i < n - 1; i++){
 		pre = pre*10 + (s[i] - '0');
 		p *= 10;
 		pre %= a;
 		p %= a;
 		if(pre == 0 and suf[i + 1]%b == 0){
 			ind = i;
 			break;
 		}
 	}
 	
 	while(s[ind + 1] == '0') ind++;

 	if(ind == -1){
 		cout<<"NO";
 	}
 	else{
 		string lef = "",  ri = "";
 		fr(i, 0, ind + 1) lef += s[i];
 		fr(i, ind + 1, n) ri += s[i];
		bool ok1 = 0, ok2 = 0;

		fr(i,0,lef.size()){
			if(lef[i] != '0') ok1 = 1;
		}	
		fr(i, 0, ri.size()){
			if(ri[i] != '0') ok2 = 1;
		}

		if(ok1 and ok2){
			cout<<"YES\n"<<lef<<'\n'<<ri<<'\n';
		}
		else cout<<"NO\n";
 	}

}