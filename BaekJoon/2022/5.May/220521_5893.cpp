#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string n;
  cin >> n;
  reverse(n.begin(), n.end());
  vector<int> input(10000, -1);
  for (int i = 0; i < n.size(); i++)
  {
    if (n[i] == '1')
    {
      input[i] = 17;
    }
    else
    {
      input[i] = 0;
    }
  }
  string answer = "";
  int i = 0;
  while (true)
  {
    int cur = input[i] % 2;
    if (cur == 1)
    {
      answer += '1';
    }
    else
    {
      answer += '0';
    }
    int carry = input[i] / 2;
    if (carry == 0 && input[i + 1] == -1)
    {
      break;
    }
    if (input[i + 1] == -1)
    {
      input[i + 1] = 0;
    }
    input[i + 1] += carry;
    i++;
  }
  reverse(answer.begin(), answer.end());
  cout << answer;

  return 0;
}