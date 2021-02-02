#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, m;
string s, p;
int ans = 0;
vector<int> pi(2, 0);

int main()
{
  // freopen("input.txt", "r", stdin);
  cin >> n >> m;
  cin >> s;
  for (int i = 0; i < n; i++)
  {
    p += "IO";
  }
  p += 'I';
  for (int i = 2; i <= 2 * n; i++)
    pi.push_back(i - 1);
  int s_len = s.size();
  int p_len = p.size();
  int j = 0;
  for (int i = 0; i < s_len; i++)
  {
    while (s[i] != p[j])
    {
      if (j == 0)
        break;
      j = pi[j - 1];
    }
    if (s[i] == p[j])
    {
      j++;
      if (j == p_len)
      {
        ans++;
        j = pi[j - 1];
      }
    }
  }
  cout << ans;
  return 0;
}