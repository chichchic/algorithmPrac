#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  if (n == 1)
  {
    cout << 0;
    return 0;
  }
  vector<bool> isPrime(n + 1, true);
  int index = 2;
  vector<int> primes;
  while (index <= n)
  {
    if (!isPrime[index])
    {
      index++;
      continue;
    }
    primes.push_back(index);
    for (int i = 2; index * i <= n; i++)
    {
      isPrime[index * i] = false;
    }
    index++;
  }
  int s = 0, e = 1;
  int sum = primes[0];
  int ans = 0;
  while (s < primes.size())
  {
    if (sum == n)
    {
      ans++;
    }
    if (sum > n || e == primes.size())
    {
      sum -= primes[s];
      s++;
    }
    else
    {
      sum += primes[e];
      e++;
    }
  }
  cout << ans;
  return 0;
}