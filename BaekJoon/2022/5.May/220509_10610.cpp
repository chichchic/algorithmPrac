#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string str;
  cin >> str;
  int sum = 0;
  bool hasZero = false;
  int numbers[10] = {};
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == '0')
    {
      hasZero = true;
    }
    sum += (str[i] - '0');
    sum %= 3;
    numbers[str[i] - '0']++;
  }
  if (!hasZero || sum != 0)
  {
    cout << -1;
  }
  else
  {
    for (int i = 9; i >= 0; i--)
    {
      while (numbers[i])
      {
        cout << i;
        numbers[i]--;
      }
    }
  }
  return 0;
}