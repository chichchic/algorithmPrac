#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string str;
  cin >> str;
  int len = str.length();
  int ans = 1;
  for (int i = 0; i < len / 2; i++)
  {
    if (str[i] != str[len - 1 - i])
    {
      ans = 0;
      break;
    }
  }
  cout << ans;
  return 0;
}