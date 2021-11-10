#include <iostream>
#include <vector>

using namespace std;

vector<long long> scores;
vector<long long> preSum;

long long getAnswer(int start, int end)
{
  if (start == end)
  {
    return scores[start] * scores[start];
  }
  int mid = (start + end) / 2;
  long long left = getAnswer(start, mid);
  long long right = getAnswer(mid + 1, end);
  long long ret = max(left, right);
  int i = mid, j = mid + 1;
  long long minScore = min(scores[i], scores[j]);
  ret = max(ret, (preSum[j] - preSum[i - 1]) * minScore);
  while (i > start || j < end)
  {
    if (j < end && ((i == start) || scores[i - 1] < scores[j + 1]))
    {
      j++;
      minScore = min(minScore, scores[j]);
    }
    else
    {
      i--;
      minScore = min(minScore, scores[i]);
    }
    ret = max(ret, (preSum[j] - preSum[i - 1]) * minScore);
  }
  return ret;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  scores.resize(n + 1);
  preSum.resize(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    cin >> scores[i];
    preSum[i] = scores[i] + preSum[i - 1];
  }
  cout << getAnswer(1, n);
  return 0;
}