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

    string s;
    cin>>s;

    string t = s;
    sort(all(t));

    do{
    	vector <int> cnt1(26, 0), cnt2(26, 0);
    	
    	bool found = 1;
    	for(int i = 0; i < (int)t.size() - 1; i++){
    		cnt1[t[i] - 'a']++;
    		cnt2[s[i] - 'a']++;

    		bool ok = 0;
    		fr(j, 0, 26){
    			if(cnt1[j] != cnt2[j]) ok = 1;
    		}

    		if(!ok) found = 0;
    		// assert(ok);
    	}
    	
		if(found){
			cout<<t<<'\n';
		}
    }
    while(next_permutation(all(t)));
}