#include <iostream>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll fermat(ll top, ll btm)
{
  vector<ll> multi(32);
  multi[0] = btm % MOD;
  for (int i = 1; i <= 31; i++)
  {
    multi[i] = (multi[i - 1] * multi[i - 1]) % MOD;
  }
  long long quotient = MOD - 2;
  long long output = 1;
  for (int i = 0; i <= 31; i++)
  {
    if (quotient & (1 << i))
    {
      output = (output * multi[i]) % MOD;
    }
  }
  return ((top % MOD) * output) % MOD;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m;
  cin >> m;
  ll answer = 0;
  for (int i = 0; i < m; i++)
  {
    long long btm, top;
    cin >> btm >> top;
    answer = (answer + fermat(top, btm)) % MOD;
  }
  cout << answer;

  return 0;
}