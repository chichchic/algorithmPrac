#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
unordered_map<ll, ll> memo;
ll fibo(ll n)
{
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;

  auto memory = memo.find(n);
  if (memory != memo.end())
  {
    return memory->second;
  }
  if (n % 2 == 0)
  {
    ll fm = fibo(n / 2 - 1) % MOD;
    ll fn = fibo(n / 2) % MOD;
    ll output = (fn * (2 * fm + fn)) % MOD;
    memo[n] = output;
    return output;
  }
  else
  {
    ll fm = fibo(n / 2 + 1) % MOD;
    ll fn = fibo(n / 2) % MOD;
    ll output = (fm * fm + fn * fn) % MOD;
    memo[n] = output;
    return output;
  }
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  cout << fibo(n) % MOD;

  return 0;
}