#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  deque<int> deq;
  int ballon[1001];
  for (int i = 1; i <= n; i++)
  {
    cin >> ballon[i];
    deq.push_back(i);
  }
  deq.pop_front();
  int num = ballon[1];
  cout << 1 << ' ';
  while (!deq.empty())
  {
    int temp;
    if (num < 0)
    {
      num *= -1;
      while (--num)
      {
        temp = deq.back();
        deq.pop_back();
        deq.push_front(temp);
      }
      temp = deq.back();
      deq.pop_back();
    }
    else
    {
      while (--num)
      {
        temp = deq.front();
        deq.pop_front();
        deq.push_back(temp);
      }
      temp = deq.front();
      deq.pop_front();
    }
    num = ballon[temp];
    cout << temp << ' ';
  }
  return 0;
}