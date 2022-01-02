#include <iostream>

using namespace std;

char ans[50];
bool findAnswer = false;
int cnt[3] = {};
bool dp[51][51][51][3][3] = {};

bool makeSeq(int a, int b, int c, int pp, int p)
{
  if (a == cnt[0] && b == cnt[1] && c == cnt[2])
  {
    return true;
  }
  if (dp[a][b][c][pp][p])
  {
    return false;
  }
  dp[a][b][c][pp][p] = true;

  ans[a + b + c] = 'A';
  if (a < cnt[0])
  {
    if (makeSeq(a + 1, b, c, p, 0))
    {
      return true;
    }
  }
  ans[a + b + c] = 'B';
  if (b < cnt[1] && p != 1)
  {
    if (makeSeq(a, b + 1, c, p, 1))
    {
      return true;
    }
  }
  ans[a + b + c] = 'C';
  if (c < cnt[2] && pp != 2 && p != 2)
  {
    if (makeSeq(a, b, c + 1, p, 2))
    {
      return true;
    }
  }
  return false;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++)
  {
    switch (s[i])
    {
    case 'A':
      cnt[0]++;
      break;
    case 'B':
      cnt[1]++;
      break;
    case 'C':
      cnt[2]++;
      break;
    }
  }
  if (makeSeq(0, 0, 0, 0, 0))
  {
    for (int i = 0; i < s.length(); i++)
    {
      cout << ans[i];
    }
  }
  else
  {
    cout << -1;
  }
  return 0;
}