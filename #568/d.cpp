#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n;
vector<int> b[200011];



int check(int d){
	bool found = 0;
 	int ans;
 	bool ok = 1;
	fr(i, 2, n + 1){
		if(b[i][0] - b[i - 1][0] != d){
			if(found) {
				ok = 0;
				break;
			}
			if(b[i + 1][0] - b[i - 1][0] != d){
				ok = 0;
				break;
			}
			else{
		 		found = 1;
		 		ans = b[i][1];
		 		i++;
		 	}
		}
	}
	if(ok and found)
 		return ans;
 	else return 0;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	fr(i, 1, n + 1){
 		int x;
 		cin>>x;
 		b[i].pb(x);
 		b[i].pb(i);
 	}	
 	if(n <= 3) return  cout<<1, 0;


 	sort(b + 1, b + n + 1);

 	set<int> s;
 	fr(i, 3, n + 1){
 		s.insert(b[i][0] - b[i - 1][0]);
 	}
 	if(s.size() == 1) return cout<<b[1][1], 0;

 	s.clear();
 	fr(i, 2, n){
 		s.insert(b[i][0] - b[i - 1][0]);
 	}
 	if(s.size() == 1) return cout<<b[n][1], 0;


 	s.clear();
 	fr(i, 2, n + 1){
 		s.insert(b[i][0] - b[i - 1][0]);
 	}


 	if(s.size() > 3) return cout<<-1, 0;


 	for(auto d:s){
 		if(check(d) != 0){
 			return cout<<check(d), 0;
 		}
 	}
 	cout<<-1;
}