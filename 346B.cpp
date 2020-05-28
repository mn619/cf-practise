#include<bits/stdc++.h>
#define int long long
#define inf 1000000000000000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

vector <vector<int>> kmp(string s){
    int n = s.size();
    vector <int> kmp(n);
    vector <vector<int>> nxt(n, vector  <int>(26));

    for(int i = 1; i < n; i++){
        int j = kmp[i - 1];
        while(j and s[j] != s[i])
            j = kmp[j - 1];
        if(s[j] == s[i])
            j++;
        kmp[i] = j;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            int k = i;
            while(k > 0 and s[k] != 'A' + j)
                k = kmp[k - 1];
            if(s[k] == 'A' + j)
                k++;
            nxt[i][j] = k;
        }
    }
    return nxt;
}

string s, t, v;
int dp[101][101][101];
pair <pair<int, int>, int> ptr[101][101][101];


signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>s>>t>>v;

    auto nxt = kmp(v);

    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++)
            for(int k = 0; k < 100; k++) dp[i][j][k] = -inf;
        
    dp[0][0][0] = 0;

    for(int i = 0; i < (int)s.size(); i++){
        for(int j = 0; j < (int)t.size(); j++){
            for(int k = 0; k < (int)v.size(); k++){
                //s[i], t[i];
                if(s[i] == t[j]){
                    if(dp[i + 1][j + 1][nxt[k][s[i] - 'A']] < dp[i][j][k] + 1){
                        ptr[i + 1][j + 1][nxt[k][s[i] - 'A']] = {{i, j}, k};
                    }
                    dp[i + 1][j + 1][nxt[k][s[i] - 'A']] = max(dp[i + 1][j + 1][nxt[k][s[i] - 'A']], dp[i][j][k] + 1);
                }
                if(dp[i + 1][j][k] < dp[i][j][k]){
                    ptr[i + 1][j][k] = {{i, j}, k};
                }

                if(dp[i][j + 1][k] < dp[i][j][k]){
                    ptr[i][j + 1][k] = {{i, j}, k};
                }

                dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
                dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
            }
        }
    }

    int maxlen = 0, x, y, z;
    for(int i = 1; i <= (int)s.size(); i++)
        for(int j = 1; j <= (int)t.size(); j++)
            for(int k = 0; k < (int)v.size(); k++) {
                if(maxlen < dp[i][j][k]){
                    maxlen = dp[i][j][k];
                    x = i, y = j, z = k;
                }
        }

    // return 0;
    
    if(maxlen == 0) return cout<<"0\n", 0;
    string ans = "";

    while(x and y){
        if(ptr[x][y][z].first.first == x - 1 and ptr[x][y][z].first.second == y - 1){
            z = ptr[x][y][z].second;
            x = x - 1, y = y - 1;
            assert(s[x] == t[y]);
            ans += s[x];
        }
        else{
            int a = ptr[x][y][z].first.first, b = ptr[x][y][z].first.second, c = ptr[x][y][z].second; 
            x = a, y = b, z = c;
        }
    }

    reverse(ans.begin(), ans.end());
    assert(ans.size() == maxlen);
    cout<<ans<<'\n';
}