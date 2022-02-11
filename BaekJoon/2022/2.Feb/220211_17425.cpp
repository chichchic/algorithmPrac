#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;
vector<long long> f(MAX + 1, 1);
vector<long long> d(MAX + 1);

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 2; i <= MAX; i++)
  {
    for (int j = 1; i * j <= MAX; j++)
    {
      f[i * j] += i;
    }
  }
  d[0] = 0;
  for (int i = 1; i <= MAX; i++)
  {
    d[i] = d[i - 1] + f[i];
  }
  while (t--)
  {
    int num;
    cin >> num;
    cout << d[num] << '\n';
  }

  return 0;
}