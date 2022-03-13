#include <iostream>

using namespace std;

string add(string num1, string num2)
{
  int cursor = 0;
  int sum = 0;
  for (; cursor < num2.size(); cursor++)
  {
    sum = (int)(num2[num2.size() - 1 - cursor] + num1[num1.size() - 1 - cursor] - '0' * 2 + sum);
    num1[num1.size() - 1 - cursor] = (sum % 10 + '0');
    sum /= 10;
  }

  while (sum != 0)
  {
    int numCursor = num1.size() - 1 - cursor;
    if (numCursor >= 0)
    {
      sum = (int)(num1[num1.size() - 1 - cursor] - '0' + sum);
      num1[num1.size() - 1 - cursor] = (char)(sum % 10) + '0';
    }
    else
    {
      num1 = (char)(sum % 10 + '0') + num1;
    }
    cursor++;
    sum /= 10;
  }
  return num1;
}

string sub(string num1, string num2)
{
  int carry = 0;
  int i = 0;
  for (; i < num2.size(); i++)
  {
    int cursor1 = num1.size() - 1 - i;
    int cursor2 = num2.size() - 1 - i;
    if (num1[cursor1] >= num2[cursor2] + carry)
    {
      num1[cursor1] = num1[cursor1] - (num2[cursor2] + carry) + '0';
      carry = 0;
    }
    else
    {
      num1[cursor1] = num1[cursor1] + 10 - num2[cursor2] - carry + '0';
      carry = 1;
    }
  }
  while (carry != 0)
  {
    int cursor1 = num1.size() - 1 - i;
    if (num1[cursor1] >= carry + '0')
    {
      num1[cursor1] = num1[cursor1] - carry;
      carry = 0;
    }
    else
    {
      num1[cursor1] = num1[cursor1] + 10 - carry;
      carry = 1;
    }
    i++;
  }
  return num1;
}

void print(string number)
{
  bool flag = false;
  for (int i = 0; i < number.size(); i++)
  {
    if (number[i] == '0' && !flag)
    {
      continue;
    }
    else
    {
      flag = true;
      cout << number[i];
    }
  }
  if (!flag)
  {
    cout << '0';
  }
  cout << '\n';
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string number;
  string gap;
  cin >> number >> gap;
  int cur = 0;
  string answer1 = "", answer2 = "";
  string b = add(number, gap);
  for (int i = 0; i < b.size(); i++)
  {
    cur += (int)(b[i] - '0');
    answer1 = answer1 + (char)((cur / 2) + '0');
    cur %= 2;
    cur *= 10;
  }
  print(answer1);
  string a = sub(number, gap);
  cur = 0;
  for (int i = 0; i < a.size(); i++)
  {
    cur += (int)(a[i] - '0');
    answer2 = answer2 + (char)((cur / 2) + '0');
    cur %= 2;
    cur *= 10;
  }
  print(answer2);

  return 0;
}