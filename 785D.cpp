#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define maxn 200000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;
int power(int a, int b, int m)
{
    int ans = 1;
    a %= m;
    while(b){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

string s;
int pre[maxn + 1], suf[maxn + 2], fac[maxn + 1];

int C(int n, int r){
    if(r < 0 or r > n) return 0;
    int ans = fac[n];
    ans *= power((fac[r]*fac[n - r])%mod, mod - 2, mod);
    ans %= mod;
    return ans;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    fac[0] = 1;
    for(int i = 1; i <= maxn; i++)
        fac[i] = (i*fac[i - 1])%mod;

    cin>>s;
    int n = (int) s.size();

    for(int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + (s[i - 1] == '(');

    for(int i = n; i >= 1; i--)
        suf[i] = suf[i + 1] + (s[i - 1] == ')');
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(s[i - 1] == '(') continue;        
        int l = pre[i], r = suf[i + 1];
        ans += C(l + r, r + 1);
        ans %= mod;
    }
    cout<<ans<<'\n';
}