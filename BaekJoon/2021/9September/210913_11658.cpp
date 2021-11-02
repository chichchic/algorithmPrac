#include <iostream>
#include <typeinfo>
#include <vector>

using namespace std;
int n, m;

class FlatSeg
{
private:
  vector<int> arr;
  vector<int> tree;

public:
  FlatSeg()
  {
    tree.resize(1024 * 4);
  }
  FlatSeg(vector<int> v)
  {
    arr = v;
    tree.resize(v.size() * 4);
    init(0, v.size() - 1, 0);
  }
  int init(int start, int end, int node)
  {
    if (start == end)
    {
      return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2 + 1) + init(mid + 1, end, node * 2 + 2);
  }
  int sum(int start, int end, int node, int fStart, int fEnd)
  {
    if (fStart > end || fEnd < start)
    {
      return 0;
    }
    if (start >= fStart && end <= fEnd)
    {
      return tree[node];
    }
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2 + 1, fStart, fEnd) + sum(mid + 1, end, node * 2 + 2, fStart, fEnd);
  }
  void update(int start, int end, int node, int index, int dif)
  {
    if (index < start || index > end)
      return;
    tree[node] += dif;
    if (start == end)
      return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2 + 1, index, dif);
    update(mid + 1, end, node * 2 + 2, index, dif);
  }
  vector<int> getTree()
  {
    return tree;
  }
  vector<int> setTree(vector<int> t)
  {
    return tree = t;
  }
};

class MatrixSeg
{
private:
  vector<FlatSeg> tree;
  vector<FlatSeg> flatSegs;

public:
  MatrixSeg(vector<FlatSeg> vF)
  {
    flatSegs = vF;
    tree.resize(vF.size() * 4);
    init(0, vF.size() - 1, 0);
  }
  vector<int> init(int start, int end, int node)
  {
    if (start == end)
    {
      return tree[node].setTree(flatSegs[start].getTree());
    }
    int mid = (start + end) / 2;
    vector<int> a = init(start, mid, node * 2 + 1);
    vector<int> b = init(mid + 1, end, node * 2 + 2);
    vector<int> c(a.size(), 0);
    for (int i = 0; i < a.size(); i++)
    {
      c[i] = a[i] + b[i];
    }
    return tree[node].setTree(c);
  }
  int sum(int x1, int x2, int node, int fx1, int fy1, int fx2, int fy2)
  {
    if (x2 < fx1 || x1 > fx2)
      return 0;
    if (x1 >= fx1 && x2 <= fx2)
    {
      int output = tree[node].sum(0, n - 1, 0, fy1, fy2);
      return output;
    }
    int mid = (x1 + x2) / 2;
    return sum(x1, mid, node * 2 + 1, fx1, fy1, fx2, fy2) +
           sum(mid + 1, x2, node * 2 + 2, fx1, fy1, fx2, fy2);
  }
  void update(int start, int end, int node, int x, int y, int dif)
  {
    if (x < start || x > end)
      return;

    tree[node].update(0, n - 1, 0, y, dif);
    if (start == end)
      return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2 + 1, x, y, dif);
    update(mid + 1, end, node * 2 + 2, x, y, dif);
  }
  vector<FlatSeg> getTree()
  {
    return tree;
  }
};

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  vector<vector<int>> arr(n, vector<int>(n, 0));
  vector<FlatSeg> flatSegs;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> arr[i][j];
    }
    flatSegs.push_back(FlatSeg(arr[i]));
  }
  MatrixSeg matrixSeg(flatSegs);
  int type;
  while (m--)
  {
    cin >> type;
    if (type)
    {
      int x1, x2, y1, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      cout << matrixSeg.sum(0, n - 1, 0, x1 - 1, y1 - 1, x2 - 1, y2 - 1) << '\n';
    }
    else
    {
      int x, y, value;
      cin >> x >> y >> value;
      int dif = value - arr[x - 1][y - 1];
      arr[x - 1][y - 1] = value;
      matrixSeg.update(0, n - 1, 0, x - 1, y - 1, dif);
    }
  }
  return 0;
}