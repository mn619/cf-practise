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

set <int> t[26];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int cas;
    cin>>cas;

    while(cas--){
    	for(int i = 0; i < 26; i++)t[i].clear();
    	string s;
    	cin>>s;
    	int n = s.size();
    	if(n == 1){
    		cout<<"YES\n";
    		for(char c = 'a'; c <= 'z'; c++)cout<<c;
    		cout<<'\n';
    		continue;
    	}

    	for(int i = 0; i < n - 1; i++){
    		t[s[i] - 'a'].insert(s[i + 1] - 'a');
    		t[s[i + 1] - 'a'].insert(s[i] - 'a');
    	}

    	int cnt = 0, ok = 1;
    	for(int i = 0; i < 26; i++){
    		if(t[i].size() == 1) cnt++;
    		if(t[i].size() > 2) ok = 0;
    	}

    	if(!ok or cnt != 2){
    		cout<<"NO\n";
    	}
    	else{
    		cout<<"YES\n";
    		string ans = "";
    		vector <bool> used(26, 0);

    		int start = -1;
    		for(int i = 0; i < 26; i++){
    			if(t[i].size() == 1){
    				start = i;
    				break;
    			}
    		}
    		
    		while(true){
    			ans += (char)(start + 'a');
    			used[start] = 1;
    			int next = -1;
    			for(auto x: t[start]){
    				if(!used[x]){
    					next = x;
    					break;
    				}
    			}

    			if(next == -1) break;
    			else start = next;
    		}

    		for(int i = 0; i < 26; i++) if(!used[i]) ans += (char)(i + 'a');
    		assert(ans.size() == 26);

    		cout<<ans<<'\n';

    		set <char> temp;
    		for(int i = 0; i < 26; i++) temp.insert(ans[i]);
    		assert(temp.size() == 26);    		
    	}
    }
}

