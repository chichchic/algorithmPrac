#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string input;
  cin >> input;
  int cnt = 0;
  int mem[3] = {1, 2, 4};
  int memo = 0;
  vector<int> answer;
  for (int i = input.length() - 1; i >= 0; i--)
  {
    if (input[i] == '1')
    {
      memo += mem[cnt];
    }
    cnt++;
    if (cnt == 3)
    {
      answer.push_back(memo);
      memo = 0;
      cnt = 0;
    }
  }
  if (cnt != 0)
  {
    answer.push_back(memo);
    memo = 0;
    cnt = 0;
  }
  for (int i = answer.size() - 1; i >= 0; i--)
  {
    cout << answer[i];
  }

  return 0;
}