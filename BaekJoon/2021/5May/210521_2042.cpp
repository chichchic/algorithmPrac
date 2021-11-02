#include <iostream>

using namespace std;

const int MAX_SIZE = 1e6;
long long *numbers = new long long[MAX_SIZE];
long long *tree = new long long[3 * MAX_SIZE];

long long initTree(int node, int start, int end)
{
  if (start == end)
  {
    return tree[node] = numbers[start];
  }
  else
  {
    return tree[node] = initTree(node * 2 + 1, start, (start + end) / 2) + initTree(node * 2 + 2, (start + end) / 2 + 1, end);
  }
}

//start, end -> 현재 노드가 가르키는 범위. left, right -> 찾고자 하는 값의 범위(고정).
long long findTree(const int node, int start, int end, const int left, const int right)
{
  if (left > end || right < start)
  {
    return 0;
  }
  else if (left <= start && end <= right)
  {
    return tree[node];
  }
  else
  {
    return findTree(node * 2 + 1, start, (start + end) / 2, left, right) +
           findTree(node * 2 + 2, (start + end) / 2 + 1, end, left, right);
  }
}
//start, end -> 현재 노드가 가르키는 범위.
long long modifyTree(const int node, int start, int end, const int change_number, const long long change_value)
{
  if (start == end && start == change_number)
  {
    return tree[node] = change_value;
  }
  else if (start <= change_number && change_number <= end)
  {
    return tree[node] = modifyTree(node * 2 + 1, start, (start + end) / 2, change_number, change_value) +
                        modifyTree(node * 2 + 2, (start + end) / 2 + 1, end, change_number, change_value);
  }
  else
  {
    return tree[node];
  }
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, M, K;
  cin >> N >> M >> K;
  for (int i = 0; i < N; ++i)
  {
    cin >> numbers[i];
  }
  initTree(0, 0, N - 1);
  for (int i = 0; i < M + K; ++i)
  {
    long long a, b, c;
    cin >> a >> b >> c;
    if (a == 1)
    {
      modifyTree(0, 0, N - 1, b - 1, c);
    }
    else
    {
      cout << findTree(0, 0, N - 1, b - 1, c - 1) << '\n';
    }
  }

  return 0;
}