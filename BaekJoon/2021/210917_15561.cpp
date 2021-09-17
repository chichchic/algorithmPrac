#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll INF = 1e15;

struct Node
{
  ll lMax, rMax, total, maximum;
};

class Seg
{
private:
  vector<ll> arr;
  vector<Node> tree;

public:
  Seg(vector<ll> k)
  {
    arr = k;
    tree.resize(k.size() * 4);
    init(0, k.size() - 1, 0);
  }
  Node merge(Node a, Node b)
  {
    Node c;
    c.lMax = max(a.lMax, a.total + b.lMax);
    c.rMax = max(a.rMax + b.total, b.rMax);
    c.total = a.total + b.total;
    c.maximum = max({a.maximum, b.maximum, a.rMax + b.lMax});
    return c;
  }
  void init(int start, int end, int node)
  {
    if (start == end)
    {
      tree[node].lMax = arr[start];
      tree[node].rMax = arr[start];
      tree[node].total = arr[start];
      tree[node].maximum = arr[start];
      return;
    }
    int mid = (start + end) / 2;
    init(start, mid, node * 2 + 1);
    init(mid + 1, end, node * 2 + 2);
    tree[node] = merge(tree[node * 2 + 1], tree[node * 2 + 2]);
  }
  void update(int start, int end, int node, int idx, int value)
  {
    if (start > idx || end < idx)
      return;
    if (start == end)
    {
      tree[node].lMax += value;
      tree[node].rMax += value;
      tree[node].total += value;
      tree[node].maximum += value;
      return;
    }
    int mid = (start + end) / 2;
    update(start, mid, node * 2 + 1, idx, value);
    update(mid + 1, end, node * 2 + 2, idx, value);
    tree[node] = merge(tree[node * 2 + 1], tree[node * 2 + 2]);
  }
  Node query(int start, int end, int node, int fStart, int fEnd)
  {
    if (fStart > end || fEnd < start)
      return {-INF, -INF, -INF, -INF};
    if (fStart <= start && fEnd >= end)
    {
      return tree[node];
    }
    int mid = (start + end) / 2;
    Node a = query(start, mid, node * 2 + 1, fStart, fEnd);
    Node b = query(mid + 1, end, node * 2 + 2, fStart, fEnd);
    return merge(a, b);
  }
};

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q, u, v;
  cin >> n >> q >> u >> v;
  vector<ll> k(n);
  for (int i = 0; i < n; i++)
  {
    cin >> k[i];
    k[i] = k[i] * u + v;
  }
  Seg seg(k);
  while (q--)
  {
    int c, a, b;
    cin >> c >> a >> b;
    if (!c)
    {
      cout << seg.query(0, n - 1, 0, a - 1, b - 1).maximum - v << '\n';
    }
    else
    {
      seg.update(0, n - 1, 0, a - 1, b * u - k[a - 1] + v);
      k[a - 1] = b * u + v;
    }
  }
  return 0;
}