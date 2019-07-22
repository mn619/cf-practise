#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;
	

int n, cnt[maxn];
string s;

bool check(int k){
	string x = "";
	fr(i, 0, n) x += '*';
	cout<<k<<'\n';

	bool ok = 1;
	fr(i, 0, n){
		if(x[i] == '*'){
			x[i] = '1';
			int t = n/k;
			int las = i;
			cout<<i<<" ";
			fr(j, 1, t + 1){
				int ind = (i + j*k)%n;
				cout<<ind<<' ';
				if(s[ind] == '1'){
					if(x[las] == '1') x[j] = '0';
					else if(x[las] == '0') x[j] = '1';
				}
				else x[ind] = x[las];
				las = ind;
			}
			cout<<x<<' '<<las<<"\n";
			if(s[las] == '1'){
				if(x[i] == x[las]) return 0;
			}
			else if(x[i] != x[las]) return 0;
		}
	}
	return 1;
}


signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>s;
 	int ans = 0;
 	fr(i, 1, n + 1){
 		cnt[__gcd(i, n)]++;
 	}

 	fr(i, 1, n + 1){
 		if(n%i == 0){
 			if(check(i)){
 				cout<<"ok"<<i<<"\n";
 				ans += cnt[i];
 			}
 		}
 	}
 	cout<<ans;
 	
}