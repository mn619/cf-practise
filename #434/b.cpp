#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 100000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m, k[101], f[101];
bool out[101];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>n>>m;
	fr(i, 1, m + 1){
		cin>>k[i]>>f[i];
		if(k[i] == n) return cout<<f[i], 0;
	}

	fr(i, 1, 101){
		fr(j, 1, m + 1){
			if((k[j]/i + (k[j]%i != 0)) != f[j]){
				out[i] = 1;
			}
		}
	}

	int ansmin = 101, ansmax = 0;

	fr(i, 1, 101){
		if(!out[i]){
			int flor = n/i + (n%i != 0);
			ansmin = min(ansmin, flor);
			ansmax = max(ansmax, flor);
		}
	}

	if(ansmin != ansmax) return cout<<-1, 0;
	cout<<ansmin;
}
