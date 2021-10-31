#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
vector<string> dp(1, "-1");
int idx = 1;
// char sources[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
void getShrink(string source, int len)
{
  if (source.length() == len)
  {
    dp.push_back(source);
  }
  for (char c = '0'; c <= '9' && source.size() == 0 || source.back() > c; c++)
  {
    getShrink(source + c, len);
  }
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= 10; i++)
  {
    getShrink("", i);
  }
  if (dp.size() <= n)
  {
    cout << -1;
  }
  else
  {
    cout << dp[n];
  }
  return 0;
}
