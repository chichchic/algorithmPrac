#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

typedef vector<long long> vl;
typedef vector<vl> matrix;

matrix gop(matrix a, matrix b)
{
  matrix ans(2);
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      ans[i].push_back(0);
      for (int k = 0; k < 2; k++)
      {
        ans[i][j] += a[i][k] * b[k][j] % MOD;
        ans[i][j] %= MOD;
      }
    }
  }
  return ans;
}

matrix f(matrix a, long long b)
{
  if (b == 1)
    return a;
  if (b % 2 == 0)
  {
    matrix k = f(a, b / 2);
    return gop(k, k);
  }
  else
  {
    return gop(f(a, b - 1), a);
  }
}

int main()
{
  // freopen("input.txt", "r", stdin);
  long long n;
  cin >> n;
  matrix a(2);
  matrix b(2);
  a[0].push_back(1);
  a[0].push_back(1);
  a[1].push_back(1);
  a[1].push_back(0);

  if (n == 1)
    return cout << 1, 0;
  if (n == 2)
    return cout << 2, 0;

  b = f(a, n - 1);
  a = f(a, n - 2);

  cout << ((a[0][0] + a[0][1]) % MOD * ((b[0][0] + b[0][1]) % MOD)) % MOD;
  return 0;
}