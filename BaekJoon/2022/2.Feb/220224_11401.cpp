#include <iostream>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll factorial(ll num)
{
  ll ret = 1;
  while (num > 1)
  {
    ret = (ret * num) % MOD;
    num--;
  }
  return ret;
}

ll pow(ll num, ll e)
{
  if (e == 1)
  {
    return num % MOD;
  }
  ll temp = pow(num, e / 2);
  if (e % 2 == 1)
  {
    return (temp * temp % MOD) * num % MOD;
  }
  return temp * temp % MOD;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n, k;
  cin >> n >> k;
  ll numer = factorial(n);
  ll denom = factorial(k) * factorial(n - k) % MOD;
  cout << numer * pow(denom, MOD - 2) % MOD;

  return 0;
}