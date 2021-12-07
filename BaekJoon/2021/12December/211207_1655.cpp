//NOTE: [ref]https://regularmember.tistory.com/142

#include <iostream>
#include <queue>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  priority_queue<int> max_heap;
  priority_queue<int> min_heap;
  int n, number;
  cin >> n;
  while (n--)
  {
    cin >> number;
    if (min_heap.size() < max_heap.size())
    {
      min_heap.push(-number);
    }
    else
    {
      max_heap.push(number);
    }
    if (min_heap.size() < 1)
    {
      cout << max_heap.top() << '\n';
      continue;
    }
    if ((min_heap.top() * -1) < max_heap.top())
    {
      int min_top = min_heap.top();
      min_heap.pop();
      int max_top = max_heap.top();
      max_heap.pop();
      min_heap.push(-max_top);
      max_heap.push(-min_top);
    }
    cout << max_heap.top() << '\n';
  }
  return 0;
}