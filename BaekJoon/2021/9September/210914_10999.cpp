#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

class LazySeg
{
private:
  vector<ll> arr;
  vector<ll> tree;
  vector<ll> lazy;

public:
  LazySeg(vector<ll> a)
  {
    arr = a;
    tree.resize(a.size() * 4);
    lazy.resize(a.size() * 4, 0);
    init(0, a.size() - 1, 0);
  }
  ll init(ll start, ll end, ll node)
  {
    if (start == end)
    {
      return tree[node] = arr[start];
    }
    ll mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2 + 1) + init(mid + 1, end, node * 2 + 2);
  }
  ll sum(ll start, ll end, ll node, ll fStart, ll fEnd)
  {
    if (end < fStart || start > fEnd)
    {
      return 0;
    }
    if (fStart <= start && end <= fEnd)
    {
      if (lazy[node] != 0)
      {
        tree[node] += lazy[node] * (end - start + 1);
        if (node * 2 + 2 < tree.size())
        {
          lazy[node * 2 + 1] += lazy[node];
          lazy[node * 2 + 2] += lazy[node];
        }
        lazy[node] = 0;
      }
      return tree[node];
    }
    ll mid = (start + end) / 2;
    if (lazy[node] != 0)
    {
      tree[node] += lazy[node] * (end - start + 1);
      if (node * 2 + 2 < tree.size())
      {
        lazy[node * 2 + 1] += lazy[node];
        lazy[node * 2 + 2] += lazy[node];
      }
      lazy[node] = 0;
    }
    return sum(start, mid, node * 2 + 1, fStart, fEnd) + sum(mid + 1, end, node * 2 + 2, fStart, fEnd);
  }
  ll update(ll start, ll end, ll node, ll fStart, ll fEnd, ll value)
  {
    ll dif = 0;
    if (end < fStart || start > fEnd)
    {
      return dif;
    }
    if (fStart <= start && end <= fEnd)
    {
      dif += (end - start + 1) * value;
      if (lazy[node] != 0)
      {
        tree[node] += lazy[node] * (end - start + 1);
        if (node * 2 + 2 < tree.size())
        {
          lazy[node * 2 + 1] += lazy[node];
          lazy[node * 2 + 2] += lazy[node];
        }
        lazy[node] = 0;
      }
      if (node * 2 + 2 < tree.size())
      {
        lazy[node * 2 + 1] += value;
        lazy[node * 2 + 2] += value;
      }
      tree[node] += dif;
      return dif;
    }
    ll mid = (start + end) / 2;
    dif += update(start, mid, node * 2 + 1, fStart, fEnd, value);
    dif += update(mid + 1, end, node * 2 + 2, fStart, fEnd, value);
    tree[node] += dif;
    return dif;
  }
};

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> input(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> input[i];
  }
  LazySeg lazySeg(input);

  ll type, x, y, value;
  ll counter = m + k;
  while (counter--)
  {
    cin >> type;
    if (type == 1)
    {
      cin >> x >> y >> value;
      lazySeg.update(0, n - 1, 0, x - 1, y - 1, value);
    }
    else
    {
      cin >> x >> y;
      cout << lazySeg.sum(0, n - 1, 0, x - 1, y - 1) << '\n';
    }
  }
  return 0;
}