#include <iostream>
#include <vector>

using namespace std;
long long n, q, u, v;
long long find_max_sum(vector<long long> k, long long a, long long b)
{
  long long output = u * k[a];
  long long prev = u * k[a];
  for (long long i = a + 1; i <= b; i++)
  {
    prev = max(prev + k[i] * u + v, k[i] * u);
    output = max(output, prev);
  }
  return output;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q >> u >> v;
  vector<long long> k(n + 1);
  for (long long i = 1; i <= n; ++i)
  {
    cin >> k[i];
  }
  while (q--)
  {
    long long c, a, b;
    cin >> c >> a >> b;
    if (c)
    {
      k[a] = b;
    }
    else
    {
      cout << find_max_sum(k, a, b) << '\n';
    }
  }

  return 0;
}