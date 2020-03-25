#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;


signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int n;
    map<int, int> cnt;

    cin>>n;
    for(int i = 1; i <= n; i++){
        int l, r;
        cin>>l>>r;
        cnt[l]++;
        cnt[r + 1]--;
    }

    int sm = 0;
    for(auto x: cnt){
        sm += x.second;
        if(sm > 2) return cout<<"NO\n", 0;
    }
    cout<<"YES\n";
}