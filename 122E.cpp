#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 200000
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int n, k;
    cin>>n>>k;

    auto lucky_check = [&](int x){
    	while(x){
    		if(x%10 != 4 and x%10 != 7) return false;
    		x /= 10;
    	}
    	return true;
    };

    vector <int> lucky_nos;
  	
  	for(int mask = 1; mask < (1<<10); mask++){
  		int num1 = 0,  num2 = 0;

  		bool ok = 0;
  		for(int i = 0; i < 10; i++){
  			num1 *= 10;
  			num2 *= 10;
  			if(mask>>i&1)
  				ok = 1;
  			if(ok)
  				num1 += ((mask>>i)&1)? 7 : 4, num2 += ((mask>>i)&1)? 4 : 7;
  		}
  		lucky_nos.pb(num1);
  		lucky_nos.pb(num2);
  	}

  	sort(all(lucky_nos));

  	map <int, int> m;
  	int fac[14] = {1};
  	for(int i = 1; i <= 13; i++) fac[i] = (fac[i - 1]*i);

  	k--;
  	for(int i = n - 13; i <= n; i++){
  		int temp = (k/fac[n - i]);
  		k -= temp*fac[n - i];
  		for(int j = 13; j >= 0; j--){
  			if(temp == 0 and !m.count(n - j)){
  				m[n - j] = i;
  				break;
  			}
  			if(!m.count(n - j)) temp--;
  		}
  	}

  	for(auto x: m){
  		if(x.F <= 0 and x.S != x.F)
	  		return cout<<"-1\n", 0;
  	}

  	int ans = 0;
  	for(auto x: lucky_nos){
  		if(x > n) break;

  		if(n - x <= 13){
  			int pos = m[x];
  			ans += lucky_check(pos);
  		}
  		else ans++;
  	}

  	cout<<ans<<'\n';
}