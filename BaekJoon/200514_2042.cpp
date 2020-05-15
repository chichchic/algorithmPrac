#include <iostream>

using namespace std;

long long arr[4000000], size;

void construct()
{
  for (long long i = size; i >= 1; i--)
  {
    arr[i] = arr[i * 2] + arr[i * 2 + 1];
  }
}

void update(long long idx, long long val)
{
  idx = size + idx;
  arr[idx] = val;

  while (idx > 1)
  {
    idx /= 2;
    arr[idx] = arr[idx * 2] + arr[idx * 2 + 1];
  }
}

long long solve(long long l, long long r, long long vtx, long long nl, long long nr)
{
  if (nl > r || nr < l)
    return 0;
  if (l <= nl && nr <= r)
    return arr[vtx];

  long long mid = (nl + nr) / 2;

  return solve(l, r, vtx * 2, nl, mid) + solve(l, r, vtx * 2 + 1, mid + 1, nr);
}

int main()
{
  // freopen("input.txt", "r", stdin);
  long long n, m, k;
  cin >> n >> m >> k;

  long long lv = 1;
  while (size < n)
  {
    size += lv;
    lv *= 2;
  }

  for (long long i = 1; i <= n; i++)
  {
    scanf("%lld", arr + size + i);
  }

  construct();

  for (long long i = 0; i < m + k; i++)
  {
    long long a, b, c;
    scanf(" %lld %lld %lld", &a, &b, &c);
    if (a == 1)
      update(b, c);
    else
      cout << solve(b, c, 1, 1, size + 1) << '\n';
  }
  return 0;
}