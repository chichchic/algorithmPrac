#include <iostream>

using namespace std;

const int MAX_SIZE = 1e5;
const int INF = 1e9;
int *numbers = new int[MAX_SIZE];
int *tree = new int[3 * MAX_SIZE];

int initTree(int node, int start, int end)
{
  if (start == end)
  {
    return tree[node] = numbers[start];
  }
  else
  {
    return tree[node] = min(initTree(node * 2 + 1, start, (start + end) / 2), initTree(node * 2 + 2, (start + end) / 2 + 1, end));
  }
}

//start, end -> 현재 노드가 가르키는 범위. left, right -> 찾고자 하는 값의 범위(고정).
int findTree(const int node, int start, int end, const int left, const int right)
{
  if (left > end || right < start)
  {
    return INF;
  }
  else if (left <= start && end <= right)
  {
    return tree[node];
  }
  else
  {
    return min(findTree(node * 2 + 1, start, (start + end) / 2, left, right),
               findTree(node * 2 + 2, (start + end) / 2 + 1, end, left, right));
  }
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; ++i)
  {
    cin >> numbers[i];
  }
  initTree(0, 0, N - 1);
  while (M--)
  {
    int a, b;
    cin >> a >> b;
    cout << findTree(0, 0, N - 1, a - 1, b - 1) << '\n';
  }

  return 0;
}