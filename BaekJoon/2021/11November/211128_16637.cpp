#include <iostream>
#include <vector>
#include <climits>
#include <stack>
#include <queue>

using namespace std;

int answer = INT_MIN;
string str;
int n;

int calc(int a, int b, char s)
{
  switch (s)
  {
  case '+':
    return a + b;
  case '*':
    return a * b;
  case '-':
    return a - b;
  default:
    return a;
  }
}

void recur(int idx, int cur)
{
  if (idx > n - 1)
  {
    answer = max(cur, answer);
    return;
  }
  char s = idx == 0 ? '+' : str[idx - 1];
  if (idx + 2 < n)
  {
    int b = calc(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
    recur(idx + 4, calc(cur, b, s));
  }
  recur(idx + 2, calc(cur, str[idx] - '0', s));
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> str;
  recur(0, 0);
  cout << answer;
  return 0;
}