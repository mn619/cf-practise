#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define maxn 100000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

vector <bool> kmp(string t, string s){
    string a = t;
    a += '#';
    a += s;


    int l = a.size();
    vector <int> kmp(l, 0);
    for(int i = 1; i < l; i++){
        int j = kmp[i - 1];
        while(j > 0 and a[j] != a[i])
            j = kmp[j - 1];
        if(a[j] == a[i]) j++;
        kmp[i] = j;
    }

    vector <bool> ans(s.size(), 0);
    for(int i = (int) 0; i < (int) s.size(); i++){
        if(kmp[i + (int)t.size() + 1] == (int)t.size())
            ans[i] = 1;
    }

    return ans;
}
string s, t;
int n, m, dp[maxn + 1], sm[2][maxn + 1];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

	cin>>s>>t;
    n = s.size(), m = t.size();

    auto k = kmp(t, s);

    for(int i = 1; i <= n; i++){
        if(k[i - 1]){
            dp[i] = i - m + 1 + sm[1][i - m];
        }
        else{
            dp[i] = i? dp[i - 1]: 0;
        }
        sm[0][i] = dp[i] + sm[0][i - 1];
        sm[1][i] = sm[0][i] + sm[1][i - 1];
        dp[i] %= mod;
        sm[0][i] %= mod;
        sm[1][i] %= mod;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) ans += dp[i], ans %= mod;
    cout<<ans<<'\n';
}
