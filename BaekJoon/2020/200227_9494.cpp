#include <iostream>
#include <string>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  int n;
  while (true)
  {
    cin >> n;
    string str;
    int idx = 0;
    if (n == 0)
      break;
    getchar();
    for (int i = 0; i < n; i++)
    {
      getline(cin, str);
      for (; idx < str.size(); idx++)
      {
        if (str[idx] == ' ')
          break;
      }
    }
    cout << idx + 1 << '\n';
  }
  return 0;
}