#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

priority_queue <int> pq;

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int n, k;
    cin>>n;
    int temp;
    cin>>k;
    cin>>temp;
    k += temp;

    int a[n + 1];
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }

    for(int i = 1; i <= n; i++){
        int b;
        cin>>b;
        pq.push(abs(a[i] - b));
    }

    while(k != 0){
        int temp = pq.top();
        pq.pop();
        if(temp == 0)
            pq.push(1);
        else
            pq.push(temp - 1);
        k--;
    }

    int ans = 0;

    while(!pq.empty()){
        int x = pq.top();
        ans += x*x;
        pq.pop();
    }
    cout<<ans<<'\n';
}