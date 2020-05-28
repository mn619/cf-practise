#include<bits/stdc++.h>
#define maxn 200000
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, sm[maxn + 1], dp[maxn + 1];
pair <pair<int, int>, int> p[maxn + 1];

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    return a.first.first + a.first.second < b.first.first + b.first.second;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>p[i].first.first>>p[i].first.second;
    

    sort(p + 1, p + n + 1, comp);
    for(int i = 1; i <= n; i++)
        p[i].second = i, sm[i] = p[i].first.first + p[i].first.second;
    
    sort(p + 1, p + n + 1);
    int ans = 0;

    for(int i = 1; i <= n; i++){
        int d = p[i].first.first - p[i].first.second;
        int s = p[i].first.first + p[i].first.second;

        int l = 1, r = n, ind = 0;
        while(l <= r){
            int mid = (l + r)>>1;
            if(sm[mid] <= d){
                ind = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        int val = 1;
        while(ind){
            val = max(dp[ind] + 1, val);
            ind -= ind&-ind;
        }

        ind = p[i].second;

        while(ind <= n){
            dp[ind] = max(dp[ind], val);
            ind += ind&-ind;
        }

        ans = max(ans, val);
    }
    cout<<ans<<'\n';
}