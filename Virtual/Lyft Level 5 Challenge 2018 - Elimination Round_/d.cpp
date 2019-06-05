#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, a[501];
map <int ,int> cnt;


vector <int> primes;
void computePrimes()
{
	int N = 1000000;
	bool b[N + 1] = {0};

	for(int i = 2; i <= N; i++)
	{
		if(b[i] == 0)
		{
			primes.pb(i);
			for(int j = i*i; j<= N; j+=i)
				b[j] = 1;
		}
	}
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i, 1, n + 1) cin>>a[i];

 	computePrimes();
 	fr(i, 1, n + 1){
 		for(auto p: primes){
 			
 		}
 	}

}	