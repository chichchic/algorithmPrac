#include <iostream>
#include <vector>
using namespace std;

vector<bool> isPrime(1000001, true);
vector<int> primes;
int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= 1e6; i++)
  {
    if (!isPrime[i])
    {
      continue;
    }
    primes.push_back(i);
    for (int j = 2; j * i <= 1e6; j++)
    {
      isPrime[i * j] = false;
    }
  }
  while (true)
  {
    cin >> n;
    if (n == 0)
    {
      break;
    }
    for (int i = 0; i < primes.size(); i++)
    {
      int dif = n - primes[i];
      if (isPrime[dif])
      {
        printf("%d = %d + %d\n", n, primes[i], dif);
        break;
      }
    }
  }

  return 0;
}