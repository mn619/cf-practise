#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
int n;
string s;
vector <int> pac, x;

bool check(int k){
	int pos = 0;
	int las = 0;
	for(auto p: pac){
		while(pos < (int)x.size()){
			if(x[las] < p){
				if(x[pos] < p){
					if(p - x[las] <= k)
						pos++;
					else break;
				}
				else if(x[pos] > p){
					if(min(2*(p - x[las]) + x[pos] - p, 2*(x[pos] - p) + p - x[las]) <= k){
						pos++;
					}
					else break;
				}
			}
			else{
				if(x[pos] - p <= k){
					pos++;
				}
				else break;
			}
		}

		if(pos == (int)x.size()) return true;
		las = pos;
	}
	return false;
}
8
signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>s;
    for(int i = 0; i < n; i++){
    	if(s[i] == 'P') pac.push_back(i);
    	if(s[i] == '*') x.push_back(i);
    }

    int l = 1, r = 2*n, ans = 0;
    while(l <= r){
    	int mid = (l + r)>>1;
    	if(check(mid))
    		r = mid - 1, ans = mid;
    	else l = mid + 1;
    }

    cout<<ans<<'\n';
}