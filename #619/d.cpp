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
int n, m, k;
vector <pair<int, string>> ans;

string to_str(int n){
	string ans = "";
	while(n){
		ans += (char)('0' + n%10);
		n /= 10;
	}
	reverse(all(ans));
	ans += " ";
	return ans;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>m>>k;

    if(k > 4*n*m - 2*n - 2*m) return cout<<"NO\n", 0;

    string s0 = "";

    for(int i = 1; i < m - 1; i++){
    	s0 += 'R';
    	s0 += 'U';
    	s0 += 'D';
    }
    s0 += 'R';
    s0 += 'U';

    string s1 = "";
    while(k){
    	if(k <= n - 1){
    		ans.pb({k, 'R'});
    		k = 0;
    		break;
    	}

    	ans.pb({1, 'D'});
    	k--;

    	if(k == 0) break;

    	if(k <= n - 1){
    		ans.pb({k, 'L'});
    		k = 0;
    		break;
    	}

    	if(k <= s0.size()){
    		string temp = "";
    		for(int i = 0; i < k; i++){
    			temp += s0[i];
    		}
    		ans.pb({1, temp});
    		k = 0;
    		break;
    	}
    	if(k <= n - 1){
    		ans.pb({k, 'L'});
    		k = 0;
    		break;
    	}

    	ans.pb({})

    }


    
}