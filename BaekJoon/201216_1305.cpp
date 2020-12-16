#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int l;
  string str;
  cin >> l >> str;
  int len = str.length();

  vector<int> fail(len, 0);
  int j = 0;
  for (int i = 1; i < len; i++)
  {
    while (j > 0 && str[i] != str[j])
      j = fail[j - 1];
    if (str[i] == str[j])
      fail[i] = ++j;
  }
  cout << len - j;
  return 0;
}