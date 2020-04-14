#include <iostream>

using namespace std;

int n;
int req[10003];
int total;

bool check(int limit)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    if (req[i] <= limit)
      sum += req[i];
    else
      sum += limit;
  }
  if (sum <= total)
    return true;
  else
    return false;
}

int main()
{
  // freopen("input.txt", "r", stdin);
  int max = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    scanf(" %d", req + i);
    if (req[i] > max)
      max = req[i];
  }
  cin >> total;
  int s = 1, e = max + 1;
  while (e - s > 1)
  {
    int mid = (s + e) / 2;
    if (check(mid))
      s = mid;
    else
      e = mid;
  }
  cout << s;
  return 0;
}