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

/*
  도가뉴의 항등식: https://ko.wikipedia.org/wiki/%ED%94%BC%EB%B3%B4%EB%82%98%EC%B9%98_%EC%88%98
  F_{m+n}=F_{m-1}F_{n}+F_{m}F_{n+1}
  짝수일경우:
  a{2n} = a{n-1}a{n} + a{n}a{n+1}
        = a{n}(a{n-1} + a{n+1})
        = a{n}(a{n-1} + a{n} + a{n-1})
        = a{n}(a{n} + 2a{n-1})
  홀수일 경우:
  a{2n-1} = a{n}a{n} + a{n-1}a{n-1}
*/

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
