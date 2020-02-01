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
int cnts[26], cntt[26];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int q;
    cin>>q;

    while(q--){
    	fr(i, 0, 26) cnts[i] = cntt[i] = 0;
    	int n;
    	cin>>n;
    	string s, t;
    	cin>>s>>t;
    	fr(i, 0, n)cnts[s[i] - 'a']++, cntt[t[i] - 'a']++;

    	bool ok = 1;
    	fr(i, 0, 26){
    		if(cnts[i] != cntt[i]) ok = 0;
    	}
    	if(!ok) cout<<"-1\n";
    	else{
    		int ans = -1;
    		for(int l = 0; l < n; l++){
    			fr(i, 0, l + 1){
    				vector <int> rem(26, 0), req(26, 0);
    				int j = n - 1 + i - l;
    				assert(i + (n - 1 - j) == l);

    				int pts = 0, ptt = i;
    				while(ptt <= j and pts < n){
    					if(s[pts] == t[ptt]){
    						pts++;
    						ptt++;
    					}
    					else{
    						rem[s[pts] - 'a']++;
    						pts++;
    					}
    				}
    				while(pts < n) rem[s[pts++] - 'a']++;

    				fr(k, 0, i)	req[t[k] - 'a']++;
    				fr(k, j + 1, n) req[t[k] - 'a']++; 
    					
    				bool ok = 1;
    				fr(k, 0, 26) if(rem[k] != req[k]){
    					ok = 0;
    					break;
    				}

    				if(ok){
    					ans = l;
    					break;
    				}
    			}
    				if(ans != -1) break;
    		}
    		cout<<ans<<'\n';
    	}
    }
}