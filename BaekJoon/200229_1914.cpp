#include <iostream>
#include <string>

using namespace std;

string ans(int n)
{
  string result = "2";
  for (int i = 1; i < n; i++)
  {
    int carry = 0;
    for (int j = result.length() - 1; j >= 0; j--)
    {
      int cur = result[j] - '0';
      cur *= 2;
      cur += carry;
      if (cur >= 10)
      {
        carry = 1;
        cur -= 10;
      }
      else
        carry = 0;
      result[j] = cur + '0';
    }
    if (carry != 0)
    {
      char fchar = carry + '0';
      result = fchar + result;
    }
  }
  result[result.length() - 1] -= 1;
  return result;
}

void hanoi(int n, int from, int by, int to)
{
  if (n == 1)
  {
    cout << from << ' ' << to << '\n';
    return;
  }
  hanoi(n - 1, from, to, by);
  cout << from << ' ' << to << '\n';
  hanoi(n - 1, by, from, to);
}

int main()
{
  // freopen("input.txt", "r", stdin);
  long long n;
  cin >> n;
  cout << ans(n) << '\n';
  if (n > 20)
  {
    return 0;
  }
  hanoi(n, 1, 2, 3);
  return 0;
}