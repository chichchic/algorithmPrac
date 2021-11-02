#include <iostream>
#include <list>
#include <stack>

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string str1, str2;
  cin >> str1 >> str2;
  list<char> str_list;
  stack<list<char>::iterator> list_pointer;
  for (char c : str1)
  {
    str_list.push_back(c);
    if (c == str2[0])
    {
      list_pointer.push(--str_list.end());
    }
  }
  bool is_end = true;
  while (!list_pointer.empty())
  {
    bool is_match = true;
    auto iter = list_pointer.top();
    list_pointer.pop();
    auto t_iter = iter;
    for (int i = 0; i < str2.length(); i++)
    {
      if (str2[i] != *t_iter)
      {
        is_match = false;
        break;
      }
      t_iter++;
    }
    if (is_match)
    {
      while (iter != t_iter)
        iter = str_list.erase(iter);
    }
  }
  if (str_list.empty())
  {
    cout << "FRULA";
  }
  else
  {
    for (char c : str_list)
      cout << c;
  }

  return 0;
}