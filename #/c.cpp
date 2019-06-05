#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int  long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
int n, b;
int mod =  1000000007;


vector <int> primes;

void computePrimes()
{
	int N = 1000000;
	bool bb[N + 1] = {0};
	for(int i = 2; i <= N; i++)
	{
		if(bb[i] == 0)
		{
			primes.pb(i);
			for(int j = i*i; j<= N; j+=i)
				bb[j] = 1;
		}
	}
}

int calc(int p, int pwr)
{
	int temp = p, ans = 0;
	int n2 = n;
	while(n2)
	{
		ans += n2/temp;
		n2 /= p;
	}
	return (int)(ans/pwr);
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH



 	cin>>n;
 	b = mod;
 	cout<<(int)n/b<<'\n';
 	return 0;
 	computePrimes();


 	vector <int> p;
 	vector <int> pwr;

 	fr(i,0,primes.size())
 	{
 		if(b%primes[i] == 0)
 		{
 			int cnt = 0;
 		 	while(b%primes[i] == 0){b/= primes[i];cnt++;}
 		 	p.pb(primes[i]);
 		 	pwr.pb(cnt);
 		}
 	}
 	if(b != 1)
 	{
 		p.pb(b);
 		pwr.pb(1);
 	}

 	int ans = (int) 2e18;
 	cout<<(int)mod*mod<<'\n';
 	
 	fr(i,0,p.size())
 	{
 		int temp = calc(p[i], pwr[i]);
 		if(ans - temp > 0) ans = temp;
 	}

 	cout<<ans<<'\n';
}