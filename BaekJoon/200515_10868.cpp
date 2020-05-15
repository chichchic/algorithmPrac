#include <iostream>

using namespace std;

long long arr[4000000], size;

void construct()
{
  for (long long i = size; i >= 1; i--)
  {
    arr[i] = min(arr[i * 2], arr[i * 2 + 1]);
  }
}

long long solve(long long l, long long r, long long vtx, long long nl, long long nr)
{
  if (nl > r || nr < l)
    return 1e9;
  if (l <= nl && nr <= r)
    return arr[vtx];

  long long mid = (nl + nr) / 2;

  return min(solve(l, r, vtx * 2, nl, mid), solve(l, r, vtx * 2 + 1, mid + 1, nr));
}

int main()
{
  freopen("input.txt", "r", stdin);
  long long n, m;
  cin >> n >> m;

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

  for (long long i = 0; i < m; i++)
  {
    long long a, b, c;
    scanf(" %lld %llds", &a, &b);
    cout << solve(a, b, 1, 1, size + 1) << '\n';
  }
  return 0;
}