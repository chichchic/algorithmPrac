#include <iostream>
#include <queue>
#define GT greater<int>
#define LT less<int>
using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  priority_queue<int, vector<int>, LT> pq;
  int nums[5] = {1, 2, 3, 4, 5};
  for (auto a : nums)
  {
    pq.push(a);
  }
  while (!pq.empty())
  {
    cout << pq.top() << '\n';
    pq.pop();
  }
  return 0;
}