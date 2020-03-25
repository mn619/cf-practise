#include<bits/stdc++.h>
#define int long long
#define inf 100000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;


string c, s, t;

vector<vector <int>> prefix_function(string s) {
    int n = (int)s.length();

    reverse(s.begin(), s.end());
    s += '%';
    reverse(s.begin(), s.end());
    
    vector <vector<int>> res(n + 1,  vector <int> (26));

    vector<int> pi(n + 1);
    for (int i = 2; i <= n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j + 1])
            j = pi[j];
        if (s[i] == s[j + 1])
            j++;
        pi[i] = j;
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j < 26; j++){
            int k = i;
            while(k > 0 && s[k + 1] != 'a' + j)
                k = pi[k];
            if(s[k + 1] == 'a' + j)
                k++;
            res[i][j] = k;
        }
    }
    return res;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>c>>s>>t;

    vector <vector <int>> ks = prefix_function(s), kt = prefix_function(t);

    int l = c.size(), m = s.size(), n = t.size();

    int dp[l + 1][m + 1][n + 1];

    for(int i = 0; i <= l; i++)
        for(int j = 0; j <= m; j++)
            for(int k = 0; k <= n; k++)
                dp[i][j][k] = -inf;

    dp[0][0][0] = 0;

    for(int i = 0; i < l; i++){
        for(int j = 0; j <= m; j++){
            for(int k = 0; k <= n; k++){
                if(c[i] != '*'){
                    int l1 = ks[j][c[i] - 'a'], l2 = kt[k][c[i] - 'a'];
                    dp[i + 1][l1][l2] = max(dp[i + 1][l1][l2], dp[i][j][k] + (l1 == m) - (l2 == n));
                }
                else
                for(int x = 0; x < 26; x++){
                    int l1 = ks[j][x], l2 = kt[k][x];
                    dp[i + 1][l1][l2] = max(dp[i + 1][l1][l2], dp[i][j][k] + (l1 == m) - (l2 == n));
                }
            }
        }
    }

    int ans = -inf;

    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n; j++) ans = max(ans, dp[l][i][j]);
    
    cout<<ans<<'\n';
}