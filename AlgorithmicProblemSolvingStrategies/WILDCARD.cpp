#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> split(string target)
{
  vector<string> ret;
  int cur = 0;
  for (int i = 0; i < target.length(); i++)
  {
    if (target.at(i) == '*')
    {
      ret.push_back(target.substr(cur, i - cur + 1));
      cur = i + 1;
    }
  }
  if (cur != target.length())
  {
    ret.push_back(target.substr(cur));
  }
  return ret;
}

bool match(const vector<string> &tokens, const string fileName, vector<vector<bool>> &checked, int tokenCur, int fileCur)
{
  if (fileCur == fileName.length() && tokenCur == tokens.size())
  {
    return true;
  }
  if (fileCur >= fileName.length() || tokenCur >= tokens.size())
  {
    return false;
  }
  string token = tokens[tokenCur];
  int idx = 0;
  while (idx < token.length())
  {
    if (token[idx] == '?' || token[idx] == fileName[fileCur])
    {
      idx++;
      fileCur++;
    }
    else if (token[idx] == '*')
    {
      while (fileCur < fileName.length())
      {
        if (checked[tokenCur + 1][fileCur])
        {
          return false;
        }
        checked[tokenCur + 1][fileCur] = true;
        if (match(tokens, fileName, checked, tokenCur + 1, fileCur))
        {
          return true;
        }
        fileCur++;
      }
      idx++;
    }
    else
    {
      return false;
    }
  }

  if (checked[tokenCur + 1][fileCur])
  {
    return false;
  }
  checked[tokenCur + 1][fileCur] = true;
  return match(tokens, fileName, checked, tokenCur + 1, fileCur);
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
    string w;
    cin >> w;
    vector<string> tokens = split(w);
    int n;
    cin >> n;
    while (n--)
    {
      string fileName;
      cin >> fileName;
      vector<vector<bool>> checked(tokens.size() + 1, vector<bool>(fileName.length() + 1, false));
      if (match(tokens, fileName, checked, 0, 0))
      {
        answer.push_back(fileName);
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