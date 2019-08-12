#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int k, n;
vector <pair<int, int>> A, D, H;

set <int> s;

signed main()
{
	
	//FILEIO	
 	FLASH

 	cin>>n>>k;

 	for(int i = 1; i <= n; i++){
 		int a, h, d;
 		cin>>a>>d>>h;

 		A.pb({a, i});
 		D.pb({d,i});
 		H.pb({h, i});
 	}


 	sort(A.begin(), A.end());
 	sort(H.begin(), H.end());
 	sort(D.begin(), D.end());

	reverse(A.begin(), A.end());
 	reverse(H.begin(), H.end());
 	reverse(D.begin(), D.end());

 	for(int i = 0; i < k; i++){
 		s.insert(A[i].second);
 		s.insert(D[i].second);
 		s.insert(H[i].second);
 	}

 	cout<<s.size()<<'\n'; 	
}