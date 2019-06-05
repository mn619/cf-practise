#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;


bool check(string s){
	int n = s.size();
	int cnt = 0;
	fr(i, 0, n){
		if(s[i] == '(') cnt++;
		else cnt--;
		if(cnt < 0) return 0;
	}
	return (cnt == 0);
}

signed main()
{

 	FLASH

 	int n;
 	cin>>n;
 	string s;
 	cin>>s;

 	queue <int> q;
 	if(s[0] == ')' || s[n - 1] == '(') return cout<<":(", 0;
 	string ans = s;

 	fr(i, 1, n - 1){
 		if(s[i] == '(') q.push(i);
 		if(s[i] == ')')
 		{
 			if(q.empty()) return cout<<":(", 0;
			else {ans[q.front()] = '('; q.pop();}
		}
 		if(s[i] == '?'){
 			q.push(i);
 		}
 	}

 	bool b = 0;
 	ans[n - 1] = ')';

 	fr(i, 0, n - 1){
 		if(ans[i] == '?'){
 			if(!b) ans[i] = '(';
 			else ans[i] = ')';
 			b = !b;
 		}
 	}

 	if(check(ans)) cout<<ans;
 	else cout<<":(";
}