#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, a[1000001], p[1000001];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n;
    set <int> s;
    int sm = 0;
    for(int i = 1; i <= n; i++){
    	if(i <= (n + 1)/2)
    	cin>>a[i];
   		else if(i == (n + 1)/2 + 1)
   		{
   			cin>>a[i];
   		}
   		else a[i] = a[i - 1];

   		sm += a[i];

   		p[i] = p[i - 1] + a[i];
   		s.insert(i);
    }

    if(sm > 0){
    	cout<<n<<'\n';
    	return 0;
    }

    if(a[n] <= 0) reverse(a + 1, a + n + 1);

    for(int i = 1; i <= n; i++){
    	vector <int> to_remove;
    	for(auto d: s){
    		if(d > i) break;
    		if(p[i] - p[i - d] <= 0) to_remove.push_back(d);
    	}

    	for(auto t: to_remove)
    		s.erase(t);
    }


    if(!s.empty()){
    	int ans = *s.begin();
    	cout<<ans<<'\n';
    }
    else cout<<"-1\n";


}