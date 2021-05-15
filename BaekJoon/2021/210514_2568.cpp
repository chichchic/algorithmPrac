#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int len;
pair<int, int> connect[500001];
pair<int, int> answer[500001];
int cache[500001] = {};
bool visited[500001] = {};
vector<int> stack;

int LIS()
{
  int idx = 0;
  int length = 0;
  cache[idx] = connect[0].second;
  answer[0] = {0, connect->first};

  for (int i = 0; i < len; ++i)
  {
    if (cache[idx] < connect[i].second)
    {
      cache[++idx] = connect[i].second;
      answer[i] = {idx, connect[i].first};
    }
    else
    {
      int idx2 = lower_bound(cache, cache + idx, connect[i].second) - cache;
      cache[idx2] = connect[i].second;
      answer[i] = {idx2, connect[i].first};
    }
  }
  return idx + 1;
}

int main()
{
  freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> len;

  for (int i = 0; i < len; i++)
  {
    cin >> connect[i].first >> connect[i].second;
    visited[connect[i].first] = true;
  }
  sort(connect, connect + len);
  int result = LIS() - 1;

  cout << len - result - 1 << '\n';
  for (int i = len - 1; i >= 0; i--)
  {
    if (answer[i].first == result)
    {
      stack.push_back(answer[i].second);
      result--;
    }
  }
  while (!stack.empty())
  {
    visited[stack.back()] = false;
    stack.pop_back();
  }
  for (int i = 0; i < 500001; ++i)
  {
    if (visited[i])
    {
      cout << i << '\n';
    }
  }
  return 0;
}