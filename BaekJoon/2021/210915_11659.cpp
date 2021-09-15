#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, i, j;
  cin >> n >> m;
  vector<int> s(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    cin >> s[i];
    s[i] += s[i - 1];
  }
  while (m--)
  {
    cin >> i >> j;
    cout << s[j] - s[i - 1] << '\n';
  }
  return 0;
}