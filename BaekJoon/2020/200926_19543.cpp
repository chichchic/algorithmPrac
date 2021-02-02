#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  string str;
  vector<string> mapStructure(k);
  getline(cin, str);
  for (int i = 0; i < k; i++)
  {
    getline(cin, mapStructure[i]);
  }
  getline(cin, str);
  long long ans = 0;
  int cur = str[n - 1] - 'A';
  int end = m - 1, start = m - 1;
  for (int i = m - 2; i >= 0; i--)
  {
    if (mapStructure[cur][i] == 'U')
    {
      start = i + 1;
      break;
    }
    if (i == 0)
      start = 0;
  }
  ans += end - start + 1;
  bool flag = false;
  for (int i = n - 2; i >= 0; i--)
  {
    cur = str[i] - 'A';
    for (; end >= 0; end--)
    {
      if (mapStructure[cur][end] == 'U')
      {
        break;
      }
      if (end == 0)
      {
        flag = true;
        break;
      }
    }
    if (flag)
      break;
    start--;
    for (; start >= 0; start--)
    {
      if (mapStructure[cur][start] == 'U')
      {
        start++;
        break;
      }
    }
    if (start < 0)
      start = 0;
    ans += end - start + 1;
  }
  cout << ans;
  return 0;
}