#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n;
string k;

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>k;

    int len = k.size();
    vector <int> dig(len, 0),val(len, 0);

    for(int i = len - 1; i >= 0; i--){
        dig[i] = i, val[i] = k[i] - '0';
        for(int j = 0, p = 1, s = 0; j <= i; j++){
            if(s >= n or  p >= n) break;
            s += (k[i - j] - '0')*p;
            p *= 10;
            if(s < n and (k[i - j] != '0')){
               dig[i] = i - j, val[i] = s;
            }
        }
    }

    int ans = 0;
    for(int i = len - 1, p = 1; i >= 0;){
        ans += val[i]*p;
        p *= n;
        i = dig[i] - 1;
    }

    cout<<ans<<'\n';
}