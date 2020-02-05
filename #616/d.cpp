#include<bits/stdc++.h>

using namespace std;

int main()
{ 
    string s;
    cin>>s;

    int n = s.size();
    vector <bitset<26>> in(n + 1);

    for(int i = n - 1; i >= 0; i--)
        in[i] |= in[i + 1],in[i][s[i] - 'a'] = 1;
    
    char c = 'z';

    for(int i = 0; i < n; i++){
        while(!in[i][c - 'a'] and c > 'a') c--;
        if(s[i] == c) cout<<c;
    }
}