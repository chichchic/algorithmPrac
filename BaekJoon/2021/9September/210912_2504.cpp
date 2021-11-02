#include <iostream>
#include <stack>

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string input;
  cin >> input;
  stack<long long> number;
  stack<char> brackets;
  bool isWrong = false;
  for (long long i = 0; i < input.length(); ++i)
  {
    char current = input[i];
    long long curNum = 0;
    if (current == '(' || current == '[')
    {
      brackets.push(current);
      continue;
    }
    else if (current == ')')
    {
      while (!brackets.empty() && brackets.top() == 'n')
      {
        curNum += number.top();
        number.pop();
        brackets.pop();
      }
      if (brackets.empty() || brackets.top() != '(')
      {
        isWrong = true;
        break;
      }
      brackets.pop();
      if (curNum)
      {
        number.push(curNum * 2);
      }
      else
      {
        number.push(2);
      }
      brackets.push('n');
    }
    else if (current == ']')
    {
      while (!brackets.empty() && brackets.top() == 'n')
      {
        curNum += number.top();
        number.pop();
        brackets.pop();
      }
      if (brackets.empty() || brackets.top() != '[')
      {
        isWrong = true;
        break;
      }
      brackets.pop();
      if (curNum)
      {
        number.push(curNum * 3);
      }
      else
      {
        number.push(3);
      }
      brackets.push('n');
    }
  }
  if (isWrong)
  {
    cout << 0;
    return 0;
  }
  long long answer = 0;
  while (!brackets.empty() && brackets.top() == 'n')
  {
    answer += number.top();
    brackets.pop();
    number.pop();
  }
  if (brackets.empty())
    cout << answer;
  else
    cout << 0;
  return 0;
}