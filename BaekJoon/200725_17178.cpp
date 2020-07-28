#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ticket
{
  char alpha;
  int num;
  ticket() {}
  ticket(char a, int n) : alpha(a), num(n) {}
};
typedef vector<ticket> vt;

bool comp(ticket a, ticket b)
{
  if (a.alpha == b.alpha)
  {
    return a.num > b.num;
  }
  return a.alpha > b.alpha;
}

int main()
{
  //freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  vt fansOrder;
  vt fanRow(5);
  vector<vt> fan(n, fanRow);
  vt waiting;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      char alpha;
      char dash;
      int num;
      cin >> alpha >> dash >> num;
      fansOrder.push_back(ticket(alpha, num));
      fan[i][j] = ticket(alpha, num);
    }
  }
  sort(fansOrder.begin(), fansOrder.end(), comp);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (!waiting.empty() && waiting.back().alpha == fansOrder.back().alpha && waiting.back().num == fansOrder.back().num)
      {
        fansOrder.pop_back();
        waiting.pop_back();
        j--;
      }
      else if (fansOrder.back().alpha == fan[i][j].alpha && fansOrder.back().num == fan[i][j].num)
      {
        fansOrder.pop_back();
      }
      else
      {
        waiting.push_back(fan[i][j]);
      }
    }
    while (!waiting.empty())
    {
      if (waiting.back().alpha == fansOrder.back().alpha && waiting.back().num == fansOrder.back().num)
      {
        fansOrder.pop_back();
        waiting.pop_back();
      }
      else
        break;
    }
  }
  if (!fansOrder.empty())
    cout << "BAD";
  else
    cout << "GOOD";
  return 0;
}