#include <iostream>

using namespace std;

bool broken[10] = {};
int n, m;

int btnCnt(int num)
{
  int result = abs(num - n);
  do
  {
    result++;
    num /= 10;
  } while (num);
  return result;
}

bool canMake(int num)
{
  do
  {
    if (broken[num % 10])
      return false;
    num /= 10;
  } while (num);
  return true;
}

int abs(int num)
{
  if (num < 0)
    return -num;
  return num;
}

int main()
{
  // freopen("input.txt", "r", stdin);
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int temp;
    cin >> temp;
    broken[temp] = true;
  }
  int can_min = n;
  int can_max = n;
  for (; can_max < 1000000; can_max++)
  {
    if (canMake(can_max))
      break;
  }
  for (; can_min >= 0; can_min--)
  {
    if (canMake(can_min))
      break;
  }
  int ans = abs(100 - n);
  if (can_min >= 0)
  {
    // cout << "min " << can_min << '\n';
    ans = min(btnCnt(can_min), ans);
  }
  if (can_max < 1000000)
  {
    // cout << "max " << can_max << '\n';
    ans = min(btnCnt(can_max), ans);
  }
  cout << ans;
  return 0;
}