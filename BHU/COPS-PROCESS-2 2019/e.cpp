#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 1000000000000
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int q;
set <int> s;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	srand(time(0));
	
	cin>>q;

	while(q--){
		int a, b;
		cin>>a>>b;
		if(a == 1){
			s.insert(b);
		}
		else{
			int l = b, r = inf;

			int ans = inf + 1;
			while(b <= r){
				int mid = (l + r)/2;
				if((*(s.lower_bound(mid)) > mid )|| s.lower_bound(mid) == s.end()){
					ans = mid;
				}
				r = mid - 1;
			}
			r = ans;

			if(r - l + 1 <= 100){
				fr(i, l, r + 1){
					if((*(s.lower_bound(i)) > i )|| s.lower_bound(i) == s.end()){
						ans = i;
						break;
					}
				}
			}
			else{
				fr(i, 1, 101){
					r = ans;
					int len = r - l + 1;
					int randpt = l + ((rand()*rand())%len + len*5)%len;
					//cout<<l<<" "<<randpt<<' '<<r<<'\n';
					if(*s.lower_bound(randpt) > randpt || (s.lower_bound(randpt) == s.end())){
						ans = randpt;
					}
				}
			}
			cout<<ans<<'\n';
		}
	} 	
}