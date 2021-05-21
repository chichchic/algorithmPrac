#include <iostream>

using namespace std;

const int MAX_SIZE = 1e5;
const int INF = 1e9;
int *numbers = new int[MAX_SIZE];

class SegmentTree
{
private:
  int *tree = new int[3 * MAX_SIZE];
  const int &(*comp)(const int &, const int &);
  int out_boundary;

public:
  SegmentTree(const int &(*dist_comp)(const int &, const int &), int dist_out_boundary)
  {
    comp = dist_comp;
    out_boundary = dist_out_boundary;
  }
  int init(const int *dist_numbers, int node, int start, int end)
  {
    if (start == end)
    {
      return tree[node] = dist_numbers[start];
    }
    else
    {
      return tree[node] = comp(init(dist_numbers, node * 2 + 1, start, (start + end) / 2), init(dist_numbers, node * 2 + 2, (start + end) / 2 + 1, end));
    }
  }
  //start, end -> 현재 노드가 가르키는 범위. left, right -> 찾고자 하는 값의 범위(고정).
  int find(const int node, int start, int end, const int left, const int right)
  {
    if (left > end || right < start)
    {
      return out_boundary;
    }
    else if (left <= start && end <= right)
    {
      return tree[node];
    }
    else
    {
      return comp(find(node * 2 + 1, start, (start + end) / 2, left, right),
                  find(node * 2 + 2, (start + end) / 2 + 1, end, left, right));
    }
  }
};

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

  SegmentTree min_tree(min, INF);
  min_tree.init(numbers, 0, 0, N - 1);
  SegmentTree max_tree(max, 0);
  max_tree.init(numbers, 0, 0, N - 1);
  while (M--)
  {
    int a, b;
    cin >> a >> b;
    cout << min_tree.find(0, 0, N - 1, a - 1, b - 1) << ' '
         << max_tree.find(0, 0, N - 1, a - 1, b - 1) << '\n';
  }

  return 0;
}