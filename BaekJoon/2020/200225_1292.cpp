#include <iostream>

using namespace std;

int calc(int point)
{
  int i = 1;
  int temp = point;
  int result = 0;
  while (true)
  {
    if (temp - i <= 0)
      break;
    result += i * i;
    temp -= i++;
  }
  result += temp * i;
  return result;
}

int main()
{
  // freopen("input.txt", "r", stdin);
  int a, b;
  cin >> a >> b;
  cout << calc(b) - calc(a - 1);
  return 0;
}