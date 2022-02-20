#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int amount[10] = {};
  int temp = 10;
  int acc = 0;
  for (int i = 1; i < 10; i++)
  {
    amount[i] = temp - acc - 1;
    temp *= 10;
    acc += amount[i];
  }
  temp = 1e8;
  int c = 8;
  while (temp > n)
  {
    temp /= 10;
    c--;
  }
  long long answer = 0;
  for (int i = 1; i <= c; i++)
  {
    answer += amount[i] * i;
  }
  answer += ((n - temp + 1) * (c + 1));
  cout << answer;
  return 0;
}