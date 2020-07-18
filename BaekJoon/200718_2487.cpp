#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b)
{
  while (b != 0)
  {
    long long r = a % b;
    a = b;
    b = r;
  }
  return a;
}

long long lcm(long long a, long long b)
{
  return a * b / gcd(a, b);
}
int main()
{
  // freopen("input.txt", "r", stdin);
  long long n;
  cin >> n;
  vector<long long> pattern(n + 1);
  vector<bool> check(n + 1, false);
  vector<long long> cycle;
  for (long long i = 1; i <= n; i++)
  {
    cin >> pattern[i];
  }
  for (long long i = 1; i <= n; i++)
  {
    if (!check[i])
    {
      check[i] = true;
      long long link = 1;
      long long cur = i;
      // cout << cur << ' ';
      while (!check[pattern[cur]])
      {
        check[pattern[cur]] = true;
        link++;
        cur = pattern[cur];
        // cout << cur << ' ';
      }
      // cout << '\n';
      // cout << "link " << link << '\n';
      cycle.push_back(link);
    }
  }
  long long ans = cycle[0];
  for (long long i = 1; i < cycle.size(); i++)
  {
    ans = lcm(ans, cycle[i]);
  }
  cout << ans;
  return 0;
}