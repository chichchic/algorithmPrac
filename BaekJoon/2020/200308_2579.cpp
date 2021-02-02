#include <iostream>
#include <vector>
using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  int input[302];
  int memo[302][2];
  for (int i = 1; i <= n; i++)
  {
    cin >> input[i];
  }
  memo[0][0] = 0;
  memo[0][1] = 0;
  memo[1][0] = input[1];
  memo[1][1] = input[1];
  if (n == 1)
  {
    cout << input[1];
    return 0;
  }
  memo[2][0] = input[2];
  memo[2][1] = input[2] + input[1];
  if (n == 2)
  {
    cout << memo[2][1];
    return 0;
  }
  for (int i = 3; i <= n; i++)
  {
    memo[i][0] = max(memo[i - 2][0], memo[i - 2][1]) + input[i];
    memo[i][1] = memo[i - 1][0] + input[i];
  }

  cout << max(memo[n][0], memo[n][1]);
  return 0;
}