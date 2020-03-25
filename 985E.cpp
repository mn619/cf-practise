#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, k, d;

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>k>>d;
    if(k == 1){
        return cout<<"YES\n", 0;
    }

    vector <int> a(n + 1), s(n + 1);
    vector <bool> ok(n + 1);

    ok[0] = 1;

    for(int i = 1; i <= n; i++){
        if(i < k) s[i] = 1;
        cin>>a[i];
    }
    sort(a.begin(), a.end());

    for(int i = k; i <= n; i++){
        int l = 1, r = i - k + 1, ans = -1;

        while(l <= r){
            int mid = (l + r)>>1;

            if(a[i] - a[mid] <= d){ 
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        if(ans != -1) {
            if(s[ans - 1] != s[i - k + 1]) ok[i] = 1;  
        }
        s[i] = s[i - 1] + ok[i - 1];
    }

    if(ok[n]) cout<<"YES\n";
    else cout<<"NO\n";

}