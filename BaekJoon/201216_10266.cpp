#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int WHOLE_CYCLE = 360000;
  vector<char> f_watch(WHOLE_CYCLE * 2 - 1, '0');
  vector<char> s_watch(WHOLE_CYCLE, '0');

  int index;
  for (int i = 0; i < n; i++)
  {
    cin >> index;
    f_watch[index] = '1';
    if (index != WHOLE_CYCLE - 1)
      f_watch[WHOLE_CYCLE + index] = '1';
  }
  for (int i = 0; i < n; i++)
  {
    cin >> index;
    s_watch[index] = '1';
  }
  vector<int> fail(WHOLE_CYCLE, 0);

  for (int i = 1, j = 0; i < WHOLE_CYCLE; i++)
  {
    while (j > 0 && s_watch[i] != s_watch[j])
      j = fail[j - 1];
    if (s_watch[i] == s_watch[j])
      fail[i] = ++j;
  }

  for (int i = 0, j = 0; i < f_watch.size(); i++)
  {
    while (j > 0 && f_watch[i] != s_watch[j])
      j = fail[j - 1];
    if (f_watch[i] == s_watch[j])
    {
      if (j == WHOLE_CYCLE - 1)
      {
        cout << "possible";
        return 0;
      }
      else
      {
        j++;
      }
    }
  }
  cout << "impossible";
  return 0;
}