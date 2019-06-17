#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
int l;
string n;


string find_(int ind){
	string x = "", y = "";


	int cary = 0;
	fr(i, 0, ind){
		x += n[i];
	}


	fr(i, ind, l){
		y += n[i];
	}



	string ans = "";
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	
	for(int i = 0; i < max(x.size(), y.size()); i++){
		if(i >= x.size()){
			int s = (y[i] - '0') + cary;
			int d = s%10;
			cary = s/10;
			ans += (d + '0');
		}
		else if(i >= y.size()){
			int s = (x[i] - '0') + cary;
			int d = s%10;
			cary = s/10;
			ans += (d + '0');
		}
		else{
			int s = (y[i] - '0') + (x[i] - '0') + cary;
			int d = s%10;
			cary = s/10;
			ans += (d + '0');
		}
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

bool cmp(string s1, string s2){
	if(s1.size() < s2.size()) return 1;
	else if(s1.size() > s2.size()) return 0;

	int l = s1.size();
	fr(i, 0, l){
		if(s1[i] < s2[i]) {return 1;}
		if(s1[i] > s2[i]) {return 0;}
	}
	return 0;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>l>>n;

 	int lef = l/2, rig = (l + 1)/2;

	while(n[lef] == '0') lef--;
	while(n[rig] == '0' and rig < l ) rig++;

	string s1 = find_(lef);
	string s2 = find_(rig);

	//cout<<s1<<" "<<s2<<'\n';
	if(cmp(s1, s2)) cout<<s1;
	else cout<<s2;
}