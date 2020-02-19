#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 200000
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>
#define double long double

using namespace std;
	

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int n;
    cin>>n;

    vector <int> a(n + 2), p(n + 2, 0), nex(n + 1);
    vector <double> ans(n + 1);

    stack <pair<int, int>> s;

    for(int i = 1; i <= n; i++){
    	cin>>a[i];
    	p[i] = a[i] + p[i - 1];
    }


    for(int i = n; i >= 1; i--){
    	while( !s.empty() and s.top().F > a[i])
    		s.pop();

    	if(s.empty()){
    		nex[i] = n + 1;
    	}
    	else{
    		nex[i] = s.top().S;
    	}

    	s.push({a[i], i});
    }

    int i = 1;
    while(i <= n){
    	double min_avg = 1.0*a[i];
    	int ind = i;

    	int j = i;

    	while(nex[j] <= n){
    		int sum = p[nex[j]] - p[i - 1];

    		if(1.0*sum/(nex[j] - i + 1) <= min_avg){
    			min_avg = 1.0*sum/(1.0*nex[j] - i + 1);
    			ind = nex[j];
    		}

    		j = nex[j];
    	}

    	for(int k = i; k <= ind; k++){
    		ans[k] = min_avg;
    	}

    	i = ind + 1;
    }

    cout<<fixed<<setprecision(20);

    for(int i = 1; i <= n; i++) cout<<ans[i]<<" ";
}