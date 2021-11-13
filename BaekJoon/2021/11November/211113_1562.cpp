#include <iostream>
#include <vector>
using namespace std;
//NOTE: 반복적으로 호출되는 형식을 기록 하는 것이 핵심
const int MOD = 1e9;

long long answer = 0;
int n;
int fullBit = (1 << 10) - 1;
vector<vector<vector<long long>>> dp(101, vector<vector<long long>>(10, vector<long long>(1 << 10, -1)));

int stairNum(int depth, int endNum, int numBit)
{
  if (depth == n)
  {
    return numBit == fullBit ? 1 : 0;
  }
  if (dp[depth][endNum][numBit] != -1)
  {
    return dp[depth][endNum][numBit];
  }
  int ret = 0;
  if (endNum - 1 >= 0)
  {
    ret += stairNum(depth + 1, endNum - 1, numBit | (1 << (endNum - 1)));
  }
  if (endNum + 1 <= 9)
  {
    ret += stairNum(depth + 1, endNum + 1, numBit | (1 << (endNum + 1)));
  }
  ret %= MOD;
  return dp[depth][endNum][numBit] = ret;
}

int main()
{
  freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;

  int answer = 0;
  for (int i = 1; i <= 9; i++)
  {
    answer += stairNum(1, i, 1 << i);
    answer %= MOD;
  }
  cout << answer;
  return 0;
}