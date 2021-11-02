#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, l;
  cin >> n >> l;
  vector<int> a(n);
  vector<int> answerArray;
  queue<int> que;
  priority_queue<int> pq;
  priority_queue<int> out_pq;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++)
  {
    pq.push(-a[i]);
    que.push(a[i]);
    if (i >= l)
    {
      int out = que.front();
      que.pop();
      out_pq.push(-out);
      while (!out_pq.empty() && pq.top() == out_pq.top())
      {
        pq.pop();
        out_pq.pop();
      }
    }
    answerArray.push_back(-pq.top());
  }
  for (int answer : answerArray)
  {
    cout << answer << ' ';
  }
  return 0;
}