#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool match(const string &wildcard, const string &filename, vector<vector<bool>> &checked, int w_cur, int f_cur)
{
  if (wildcard.length() == w_cur && filename.length() == f_cur)
  {
    return true;
  }
  if (wildcard.length() <= w_cur)
  {
    return false;
  }
  if (wildcard[w_cur] == '*')
  {
    if (match(wildcard, filename, checked, w_cur + 1, f_cur))
    {
      return true;
    }
    if (filename.length() <= f_cur)
    {
      return false;
    }
    checked[w_cur][f_cur] = true;
    return match(wildcard, filename, checked, w_cur + 1, f_cur + 1) || match(wildcard, filename, checked, w_cur, f_cur + 1);
  }
  if (filename.length() <= f_cur)
  {
    return false;
  }
  if (checked[w_cur][f_cur])
  {
    return false;
  }
  checked[w_cur][f_cur] = true;
  if (wildcard[w_cur] == '?' || wildcard[w_cur] == filename[f_cur])
  {
    return match(wildcard, filename, checked, w_cur + 1, f_cur + 1);
  }
  return false;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int c;
  cin >> c;
  while (c--)
  {
    vector<string> answer;
    string wildcard;
    cin >> wildcard;
    int n;
    cin >> n;
    while (n--)
    {
      string filename;
      cin >> filename;
      vector<vector<bool>> checked(wildcard.length() + 1, vector<bool>(filename.length() + 1, false));
      if (match(wildcard, filename, checked, 0, 0))
      {
        answer.push_back(filename);
      }
    }
    sort(answer.begin(), answer.end());
    for (auto s : answer)
    {
      cout << s << '\n';
    }
  }

  return 0;
}