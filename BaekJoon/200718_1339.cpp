//코드 버리고 백트랙킹으로 접근해야함

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

int stepNum[10][26] = {};
int maxNumber = 9;
int ansNumber[26] = {};
void findNumber(int curStep, bool candiCheck[])
{
  //1의 자리수 이하로 내려왔을 경우 재귀 멈춤
  if (curStep == 0)
    return;

  //해당 자리수의 숫자를 오름차순으로 정렬
  priority_queue<pii, vpii> que;
  for (int i = 0; i < 26; i++)
  {
    if (candiCheck[i])
    {
      if (stepNum[curStep][i])
        que.push(make_pair(stepNum[curStep][i], i));
    }
  }

  bool sameCandi[26] = {};
  bool haveSame = false;
  while (!que.empty())
  {
    pair<int, int> cur = que.top();
    que.pop();
    if (que.empty() || que.top().first != cur.first)
    {
      if (haveSame)
      {
        sameCandi[cur.second] = true;
        candiCheck[cur.second] = false;
        findNumber(curStep - 1, sameCandi);
        for (int i = 0; i < 26; i++)
        {
          if (sameCandi[i])
          {
            sameCandi[i] = false;
            ansNumber[i] = maxNumber;
            maxNumber--;
          }
        }
        haveSame = false;
      }
      else
      {
        candiCheck[cur.second] = false;
        ansNumber[cur.second] = maxNumber;
        maxNumber--;
      }
    }
    else
    {
      sameCandi[cur.second] = true;
      candiCheck[cur.second] = false;
      haveSame = true;
    }
  }
  findNumber(curStep - 1, candiCheck);
}

int main()
{
  freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  string word[10];
  bool candiCheck[26] = {};
  for (int i = 0; i < n; i++)
  {
    cin >> word[i];
    reverse(word[i].begin(), word[i].end());
  }

  for (int i = 1; i <= 10; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (word[j].length() >= i)
      {
        stepNum[i][word[j][i - 1] - 'A']++;
        candiCheck[word[j][i - 1] - 'A'] = true;
      }
    }
  }
  findNumber(10, candiCheck);
  long long ans = 0;
  for (int i = 0; i < 26; i++)
  {
    if (ansNumber[i] != 0)
    {
      printf("%c : %d\n", 'A' + i, ansNumber[i]);
    }
  }
  for (int i = 0; i < n; i++)
  {
    long long ten = 1;
    for (int j = 0; j < word[i].length(); j++)
    {
      ans += ansNumber[word[i][j] - 'A'] * ten;
      ten *= 10;
    }
  }
  cout << ans;
  return 0;
}