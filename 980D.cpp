#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, a[5001], val[5001];
vector <int> p;
vector <int> ans(5001);
map <int, int> m;
bitset <5000> b;

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    vector <bool> in(4001, 1);
    for(int i = 2; i <= 4000; i++){
    	if(in[i]){
    		p.push_back(i);
    		for(int j = i*i; j <= 4000; j += i)
    			in[j] = 0;
    	}
    }

    cin>>n;
    int cur = 0;

    for(int i = 1; i <= n; i++){
    	cin>>a[i];
    	// a[i] = ((int)rand()*rand())%100000000;
    	// cout<<a[i]<<" ";
    	int temp = abs(a[i]);
    	if(a[i] == 0){
    		continue;
    	}
		a[i] /= temp;
    	for(auto x: p){
    		bool cnt = 0;
    		while(temp%x == 0){
    			cnt ^= 1;
    			temp /= x;
    		}
    		a[i] *= cnt?x: 1;
    	}
    	a[i] *= temp;
    	// cout<<a[i]<<" ";
    	if(!m.count(a[i])){
    		m[a[i]] = cur++;
    	}
    	val[i] = m[a[i]];
    }


    // cout<<'\n';
    // return 0;

    for(int i = 1; i <= n; i++){
    	int cnt = 0;
    	for(int j = i; j <= n; j++){
    		if(a[j] == 0){					//The fuck
    			ans[max((int)1, cnt)]++;
    			continue;
    		}
    		int ind = val[j];
    		if(!b[ind])
    			cnt++;
    		b[ind] = 1;
    		ans[cnt]++;
    	}
    	for(int j = 0; j < n; j++) b[j] = 0;
    }

    for(int i = 1; i <= n; i++) cout<<ans[i]<<" ";
}