#include <iostream>
#include <vector>

using namespace std;

int answerMax = -1e9;
int answerMin = 1e9;

void insertOperator(int index, vector<int> &oper, vector<int> &seq)
{
  if (index >= seq.size() - 1)
  {
    int answer = 0;
    for (int i = 0; i < seq.size(); i++)
    {
      answer += seq[i];
    }
    answerMax = max(answer, answerMax);
    answerMin = min(answer, answerMin);
    return;
  }
  for (int i = 0; i < 4; i++)
  {
    if (oper[i] == 0)
    {
      continue;
    }
    oper[i]--;
    int origin1 = seq[index];
    int origin2 = seq[index + 1];
    switch (i)
    {
    case 1:
      seq[index + 1] *= -1;
      break;
    case 2:
      seq[index + 1] *= seq[index];
      seq[index] = 0;
      break;
    case 3:
      seq[index + 1] = seq[index] / seq[index + 1];
      seq[index] = 0;
      break;
    default:
      break;
    }
    insertOperator(index + 1, oper, seq);
    seq[index] = origin1;
    seq[index + 1] = origin2;
    oper[i]++;
  }
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> seq(n);
  vector<int> oper(4);
  for (int i = 0; i < n; i++)
  {
    cin >> seq[i];
  }
  for (int i = 0; i < 4; i++)
  {
    cin >> oper[i];
  }
  insertOperator(0, oper, seq);
  cout << answerMax << '\n'
       << answerMin;
  return 0;
}