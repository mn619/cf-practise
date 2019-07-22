#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 1000000

using namespace std;

int n;

int p[1000001];
void sieve(){

	fr(i, 2, maxn + 1){
		if(p[i] == 0){
			for(int j = i*i; j <= maxn; j+=i) p[j] = 1;
		}
	}


}


void solve(){

 	
	int cnt[n + 1] = {0};

 	if(p[n]){
 		
 	}
 	else{
 		int add = 0;
 		fr(i, 1, n/2 + 1){
 			if(p[n + i]){
 				add = i;
 				break;
 			}
 		}

 		cout<<n<<" "<<add<<" "<<n + add<<'\n';
 		if(add == 0){
 			cout<<n<<" "<<add<<" 1\n";
 		}


 		/*
 		cout<<n + add<<'\n';
 		fr(i, 1, n) cout<<i<<" "<<i + 1<<'\n';
 		cout<<1<<" "<<n<<'\n';
		*/

		fr(i, 1, n) cnt[i]++, cnt[i + 1]++;
		cnt[1]++;
		cnt[n]++;

 		for(int i = 1; i + 3 <= n; i+=4){
 			if(add == 0) break;
 			//cout<<i<<" "<<i + 2<<'\n';
 			cnt[i]++;
 			cnt[i + 2]++;
 			add--;
 			if(add == 0) break;
 			//cout<<i + 1<<" "<<i + 3<<'\n';
 			cnt[i + 1]++;
 			cnt[i + 3]++;
 			add--;
 		}

 		
 		if(add != 0) cout<<n<<" "<<add<<" 2\n";

 		fr(i, 1, n + 1){
 			assert(p[cnt[i]]);
 		}
 		//assert(add == 0);
 	}
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	sieve();
 	fr(i, 1, maxn + 1) p[i] = !p[i];

 	int t = 1000;
 	n = 3;
 	while(n <= 1000){
 		solve();
 		n++;
 	}
}