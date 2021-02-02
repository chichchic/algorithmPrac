#include <iostream>

using namespace std;

long long size, arr[4000000], lazy[4000000];

void construct()
{
  for (long long i = size; i >= 1; i--)
    arr[i] = arr[i * 2] + arr[i * 2 + 1];
}

void prop(long long vtx, long long nr, long long nl)
{
  if (lazy[vtx])
  {
    if (vtx >= size)
    {
      lazy[vtx * 2] += lazy[vtx];
      lazy[vtx * 2 + 1] += lazy[vtx];
    }
    arr[vtx] += lazy[vtx] * (nr - nl + 1);
    lazy[vtx] = 0;
  }
}

long long update(long long l, long long r, long long vtx, long long nl, long long nr, long long val)
{
  prop(vtx, nl, nr);
  if (l > nr || r > nl)
    return 0;
  if (l <= nl && nr <= r)
  {
    lazy[vtx] += val;
    prop(vtx, nl, nr);
    return arr[vtx];
  }

  long long mid = (nl + nr) / 2;
  long long left = solve(l, r, vtx * 2, nl, mid, val);
  long long right = solve(l, r, vtx * 2 + 1, mid + 1, nr, val);
  arr[vtx] = arr[vtx * 2] + arr[vtx * 2 + 1];
  return left + right;
}

int main()
{
  freopen("input.txt", "r", stdin);
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
    scanf(" %d", arr + size + i);
  }

  construct();

  return 0;
}