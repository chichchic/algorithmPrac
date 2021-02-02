#include <iostream>
#include <queue>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  priority_queue<int> pq; // min_heap으로 사용하고 싶을 경우 -를 붙여 넣으면 된다.
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int a;
    scanf(" %d", &a);
    if (a == 0)
    {
      if (pq.empty())
        printf("%d\n", a);
      else
      {
        printf("%d\n", -pq.top());
        pq.pop();
      }
    }
    else
      pq.push(-a);
  }

  return 0;
}