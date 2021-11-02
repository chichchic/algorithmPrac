#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long ll;
const int SIZE = 1 << 18;

class SegmentTree
{
  vector<int> arr;

  int sum(int s, int e, int node, int ns, int ne)
  {
    if (e <= ns || ne <= s)
      return 0;
    if (s <= ns && e >= ne)
      return arr[node];
    int mid = (ns + ne) / 2;
    return sum(s, e, node * 2, ns, mid) + sum(s, e, node * 2 + 1, mid, ne);
  }

public:
  SegmentTree()
  {
    arr.resize(SIZE, 0);
  }
  int sum(int s, int e)
  {
    return sum(s, e, 1, 0, SIZE / 2);
  }
  void increase(int n)
  {
    n += SIZE / 2;
    //부모까지 한개씩 늘려줌
    while (n > 0)
    {
      arr[n]++;
      n /= 2;
    }
  }
};
ll solution()
{
  int count;
  cin >> count;
  vector<pair<int, int>> positions(count);
  SegmentTree seg;
  for (int i = 0; i < count; i++)
  {
    int x, y;
    cin >> x >> y;
    positions[i].first = x;
    positions[i].second = y;
  }
  sort(positions.begin(), positions.end(), [](pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
  });
  int newY[750000] = {0};
  int range = 0;
  for (int i = 1; i < count; i++)
  {
    if (positions[i].second != positions[i - 1].second)
      range++;
    newY[i] = range;
  }
  //second 값은 y의 값이 작을수록 작다.
  for (int i = 0; i < count; i++)
  {
    positions[i].second = newY[i];
  }
  //x값이 작은것 부터, 같을 경우 y값이 큰곳부터 확인.
  sort(positions.begin(), positions.end(), [](pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
      return a.second > b.second;
    return a.first < b.first;
  });
  ll result = 0;
  for (int i = 0; i < count; i++)
  {
    //y값이 큰곳으로만 향할 수 있음, 이전 섬의 방향이 북쪽일 경우.
    result += seg.sum(positions[i].second, SIZE / 2);
    seg.increase(positions[i].second);
  }
  return result;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test_case;
  cin >> test_case;
  while (test_case--)
  {
    cout << solution() << '\n';
  }

  return 0;
}