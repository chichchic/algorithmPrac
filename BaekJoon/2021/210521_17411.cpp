#include <iostream>
#include <algorithm>

using namespace std;
const long long MAX_SIZE = 1000001;
const long long MOD = 1000000007;

struct node
{
  long long index;
  long long value;
};

node arr[MAX_SIZE];
node tree[MAX_SIZE * 4];

bool comp(node a, node b)
{
  if (a.value == b.value)
  {
    return a.index > b.index;
  }
  return a.value < b.value;
}

bool comp2(node a, node b)
{
  return a.index < b.index;
}

node merge(node a, node b)
{
  node ret;
  if (a.value > b.value)
  {
    ret = a;
  }
  else if (a.value < b.value)
  {
    ret = b;
  }
  else
  {
    ret.value = a.value;
    ret.index = a.index + b.index;
  }
  return ret;
}

node updateTree(long long index, node k, long long s, long long e, long long nod)
{
  if (index < s || index > e)
  {
    return tree[nod];
  }
  if (s == e)
  {
    return tree[nod] = k;
  }
  node a = updateTree(index, k, s, (s + e) / 2, nod * 2);
  node b = updateTree(index, k, (s + e) / 2 + 1, e, nod * 2 + 1);
  return tree[nod] = merge(a, b);
}

node findTree(long long l, long long r, long long s, long long e, long long nod)
{
  node x = {0, 0};
  if (r < s || e < l)
    return x;
  if (l <= s && e <= r)
    return tree[nod];
  node a = findTree(l, r, s, (s + e) / 2, nod * 2);
  node b = findTree(l, r, (s + e) / 2 + 1, e, nod * 2 + 1);
  return merge(a, b);
}

int main()
{
  freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long size;
  cin >> size;
  for (long long i = 1; i <= size; ++i)
  {
    cin >> arr[i].value;
    arr[i].index = i;
  }
  sort(arr + 1, arr + size + 1, comp);
  for (long long i = 1; i <= size; ++i)
  {
    arr[i].value = i;
  }
  sort(arr + 1, arr + size + 1, comp2);

  node ans = {0, 0};
  node x = {1, 0};
  updateTree(0, x, 0, size, 1);
  for (long long i = 1; i <= size; ++i)
  {
    node x = findTree(0, arr[i].value, 0, size, 1);
    x.value++;
    x.index %= MOD;
    ans = merge(ans, x);
    ans.index %= MOD;
    updateTree(arr[i].value, x, 0, size, 1);
  }

  cout << tree[1].value << ' ' << tree[1].index;

  return 0;
}