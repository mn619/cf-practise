#include<bits/stdc++.h>
#include <string>
using namespace std;
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);


bool isPalindrome(string word)
{
  int n = word.size();
  stack <int> s;
  queue <int> q;
  for(int i = 0; i<n; i++)
  {
    int temp = word[i];
    if(temp >= 65 and temp <= 90)
    {
      int t = 'a';
      temp = t + temp -65;
    }
    char c = temp;
    cout<<c;
    s.push(temp);
    q.push(temp);
  }

  cout<<'\n';

  while(!s.empty())
  {
    if(s.top() != q.front()) return 0;
    q.pop();
    s.pop();
  }
  return 1;
}
int main()
{
	FILEIO
	

  string word;
  cin >> word;
  cout << isPalindrome(word) << endl;
}