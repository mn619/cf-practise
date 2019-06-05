#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

string next(string x){
	for(int i = x.size() - 1; i >= 0; i--){
		if(x[i] != 'z'){
			x[i]++;
			
			fr(j, i + 1, x.size())	x[j] = 'a';
			return x;
		}
	}

	x += 'a';
	fr(i, 0, x.size()) x[i] = 'a';
	return x;
}

signed main()
{
	
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	
 	string t = "a";

 	int n;
 	cin>>n;
 	set <string> s;
 	while(n--){
 		string x;
 		cin>>x;

 		fr(i, 0, x.size()){
 			fr(j, i, x.size()){
 				string t = "";
 				fr(k, i, j + 1){
 					t += x[k];
 				}
 				s.insert(t);
 			}
 		}
 	}

 	while(s.find(t) != s.end()){
 		t = next(t);
 	}
 	cout<<t;
}