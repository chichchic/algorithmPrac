#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> answer;
int findMinIdx(vector<int> &sequence, int curIdx)
{
  while (true)
  {
    curIdx++;
    if (sequence[curIdx] == -1)
      return curIdx;
  }
}

bool getShomSequence(int depth, vector<int> &shom, int minIdx, vector<bool> &usednums, vector<int> &sequence)
{
  if (depth >= shom.size())
  {
    answer.assign(sequence.begin(), sequence.end());
    return true;
  }
  for (int i = 0; i < shom.size(); i++)
  {
    if (usednums[i])
    {
      continue;
    }
    int curNum = shom[i];
    int pairIdx = minIdx + 1 + curNum;
    if (pairIdx >= sequence.size() || sequence[pairIdx] != -1)
    {
      continue;
    }
    sequence[minIdx] = curNum;
    sequence[pairIdx] = curNum;
    usednums[i] = true;
    int nextIdx = -1;
    if (depth + 1 < shom.size())
    {
      nextIdx = findMinIdx(sequence, minIdx);
    }
    if (getShomSequence(depth + 1, shom, nextIdx, usednums, sequence))
    {
      return true;
    }
    sequence[minIdx] = -1;
    sequence[pairIdx] = -1;
    usednums[i] = false;
  }
  return false;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> sequence(n * 2, -1);
  vector<int> shom(n);
  vector<bool> usednums(n, false);
  for (int i = 0; i < n; i++)
  {
    cin >> shom[i];
  }
  sort(shom.begin(), shom.end());
  if (getShomSequence(0, shom, 0, usednums, sequence))
  {
    for (auto num : answer)
    {
      cout << num << ' ';
    }
  }
  else
  {
    cout << -1;
  }
  return 0;
}