#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int getLength(string s, int &index)
{
  int answer = 0;
  bool isOpened = false;
  for (; index < s.length(); index++)
  {
    if (index + 1 < s.length() && s[index + 1] == '(')
    {
      index += 2;
      int multiply = s[index - 2] - '0';
      answer += multiply * getLength(s, index);
      continue;
    }
    if (s[index] == ')')
    {
      return answer;
      continue;
    }
    answer++;
  }
  return answer;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  stack<char> st;

  int index = 0;
  cout << getLength(s, index);
  return 0;
}