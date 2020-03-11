#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<char> vc;

int n, k;
vector<char> teach;
vector<vc> word;
int ans = 0;
int total = 0;
void backtracking(vector<bool> &candi, int size, int start)
{
  if (size == k)
  {
    total++;
    // for (int i = 0; i < candi.size(); i++)
    // {
    //   if (candi[i])
    //     cout << (char)(i + 'a') << ' ';
    // }
    // cout << " : ";
    int cnt = 0;
    for (int i = 0; i < word.size(); i++)
    {
      bool can_cnt = true;
      for (int j = 0; j < word[i].size(); j++)
      {
        if (candi[word[i][j] - 'a'] == false)
        {
          can_cnt = false;
          break;
          // cout << word[i][j];
        }
      }
      // cout << ' ';
      if (can_cnt)
        cnt++;
    }
    if (ans < cnt)
      ans = cnt;
    // cout << '\n';
    return;
  }
  for (char i = start; i <= 26 - k + size; i++)
  {
    if (candi[i])
      continue;
    candi[i] = true;
    backtracking(candi, size + 1, i + 1);
    candi[i] = false;
  }
}

int main()
{
  freopen("input.txt", "r", stdin);
  char str[20];
  scanf(" %d %d", &n, &k);
  vector<bool> check_init(26, false);
  if (k < 5)
  {
    cout << 0;
    return 0;
  }
  else if (k == 26)
  {
    cout << n;
    return 0;
  }
  k -= 5;
  check_init['a' - 'a'] = check_init['c' - 'a'] = check_init['i' - 'a'] = check_init['t' - 'a'] = check_init['n' - 'a'] = true;

  for (int i = 0; i < n; i++)
  {
    scanf(" %s", str);
    vector<bool> check = check_init;
    vector<char> temp;
    for (int j = 0; j < strlen(str); j++)
    {
      int idx = str[j] - 'a';
      if (!check[idx])
      {
        check[idx] = true;
        temp.push_back(str[j]);
      }
    }
    word.push_back(temp);
  }

  backtracking(check_init, 0, 0);
  cout << total << "!\n";
  cout << ans;
  return 0;
}