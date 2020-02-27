#include <iostream>
#include <string>

using namespace std;

bool check[1000000] = {};
int main()
{
  // freopen("input.txt", "r", stdin);
  int n, m, ans = 0;
  cin >> n >> m;
  long long p = 0;
  int plen = 2 * n + 1;
  int cur = 1;
  for (int i = 0; i < plen; i++)
  {
    if (i % 2 == 0)
      p += 'I' * cur;
    else
      p += 'O' * cur;
    cur *= 2;
  }
  long long hash = 0;
  string s;
  cin >> s;
  cur = 1;
  for (int i = 0; i < plen; i++)
  {
    hash += s[i] * cur;
    cur *= 2;
  }
  if (hash == p)
    ans++;
  cur /= 2;
  for (int i = 0; i < m - plen; i++)
  {
    hash -= s[i];
    hash /= 2;
    hash += s[i + plen] * cur;
    // cout << i << ' ' << s[i] << ' ' << s[i + plen] << '\n';
    if (hash == p)
    {
      // cout << i << ' ' << hash << ' ' << p << '\n';
      ans++;
    }
  }
  cout << ans;
  return 0;
}