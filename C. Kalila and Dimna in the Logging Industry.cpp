#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;
int n;
int a[100001], b[100001];
int dp[100001];

/* code to test, taken from https://github.com/ADJA/algos/blob/master/DP/ConvexHullTrick.cpp */
vector <long long> mvals, bvals;
int cur = 0;
bool bad(long long m1, long long b1, long long m2, long long b2, long long m3, long long b3) {
    return 1.0 * (b1 - b3) * (m2 - m1) < 1.0 * (b1 - b2) * (m3 - m1);
}

void add(long long m, long long b) {
    while ( (int) mvals.size() >= 2 && bad(mvals[mvals.size() - 2], bvals[bvals.size() - 2], mvals[mvals.size() - 1], bvals[bvals.size() - 1], m, b)) {
        mvals.pop_back(); bvals.pop_back();
    }
    mvals.push_back(m); bvals.push_back(b);
}

void setCur(long long x) {
    if (cur > (int) mvals.size() - 1)
        cur = (int) mvals.size() - 1;
    while (cur < (int) mvals.size() - 1 && 1.0 * mvals[cur + 1] * x + bvals[cur + 1] <= 1.0 * mvals[cur] * x + bvals[cur])
        cur++;
}
/* __ */

signed main() {
    scanf("%d", &n);
    int i;
    fr(i,1,n + 1)cin>>a[i];
    fr(i,1,n + 1)cin>>b[i];

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            dp[i] = 0;
        }
        else {
            setCur(a[i]);
            dp[i] = mvals[cur] * a[i] + bvals[cur]; 
        }
        add(b[i], dp[i]);
    }

    cout << dp[n];

    return 0;
}
