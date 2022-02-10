#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string ans = "";
  string memo[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
  while (scanf("%1d", &n) != EOF)
  {
    ans += memo[n];
  }
  int i = 0;
  for (; i < ans.length(); i++)
  {
    if (ans[i] != '0')
    {
      break;
    }
  }
  ans = ans.substr(i, ans.length() - i);
  if (ans == "")
  {
    cout << "0";
  }
  cout << ans;
  return 0;
}