#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 1000000

using namespace std;

int n;
string s[100001];


int cnt(string x){
	int ans = 0;
	fr(i, 0, x.size()){
		if(x[i] == 'a' || x[i] == 'e' || x[i] == 'i' || x[i] == 'o' || x[i] == 'u') ans++;
	}
	return ans;
}

int l(string x){
	int ans = 0;
	for(int i = 0; i < x.size(); i++){
		if(x[i] == 'a' || x[i] == 'e' || x[i] == 'i' || x[i] == 'o' || x[i] == 'u') ans = x[i] - 'a';
	}
	return ans;
}

vector<pair<int, int>> v[maxn + 1];

signed main()
{
	FILEIO
	FLASH

	cin>>n;

	fr(i, 1, n + 1){
		cin>>s[i];
		v[cnt(s[i])].pb({l(s[i]), i});
	}
	vector<int> fir, sec;

	fr(i, 1, maxn + 1){

		sort(v[i].begin(), v[i].end());
		int len = v[i].size();
		
		vector<int> temp;
		for(int j = 0; j < len; j++){

			if(j == len - 1){
				temp.pb(v[i][j].second);
				break;
			}
			else if(v[i][j].first == v[i][j + 1].first){
				sec.pb(v[i][j].second);
				sec.pb(v[i][j + 1].second);
				j++;
			}
			else{
				temp.pb(v[i][j].second);
			}			
		}

		len = temp.size();

		fr(j, 0, len - 1){
			fir.pb(temp[j]);
			fir.pb(temp[j + 1]);
			j++;
		}

	}


	int ans = min(fir.size(), sec.size())/2;
	int ind = 2*ans;

	ans += ((int) sec.size() - 2*ans)/4;

	cout<<ans<<'\n';

	fr(i, 0, ind){
		cout<<s[fir[i]]<<" "<<s[sec[i]]<<"\n";
	}

	fr(i, ind, sec.size()){
		if(i + 3 >= sec.size()) break;
		cout<<s[sec[i]]<<" "<<s[sec[i + 2]]<<'\n'<<s[sec[i + 1]]<<' '<<s[sec[i + 3]]<<'\n';
		i += 3;
	}

}