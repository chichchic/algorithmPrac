#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<int> f(4);
  vector<int> s(2);
  for (int i = 0; i < 4; i++)
  {
    cin >> f[i];
  }
  for (int i = 0; i < 2; i++)
  {
    cin >> s[i];
  }
  sort(f.begin(), f.end(), greater<int>());
  sort(s.begin(), s.end(), greater<int>());
  cout << f[0] + f[1] + f[2] + s[0];
  return 0;
}