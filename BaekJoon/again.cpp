#include <iostream>
#include <vector>

using namespace std;

class company
{
private:
  int size;
  vector<int> number;

public:
  company(int n);
  int find(int x)
  {
    if (x == number[x])
      return x;
    else
      return number[x] = find(number[x]);
  }
  void Union(int x, int y)
  {
    x = find(x);
    y = find(y);

    if (x != y)
    {
      number[y] = x;
    }
  }
};

company::company(int n)
{
  size = n;
  number.resize(n);
  for (int i = 0; i < n; i++)
  {
    number[i] = i;
  }
}

int main()
{
  freopen("input.txt", "r", stdin);
  int n, m;
  cin >> n >> m;
  company c = company(n);
  for (int i = 0; i < n; i++)
  {
    int my_boss;
    cin >> my_boss;
    if (my_boss == -1)
      continue;
    c.Union(i, my_boss - 1);
  }
  vector<int> compliment(n, 0);
  for (int i = 0; i < m; i++)
  {
    int cur, val;
    cin >> cur >> val;
    compliment[cur - 1] = val;
  }
  for (int i = 0; i < n; i++)
  {
    int boss = c.find(i);
    if (boss != i)
      compliment[i] +=
  }
  return 0;
}