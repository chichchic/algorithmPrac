#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, n, m, num;
  cin >> t >> n;
  int A[1001], B[1001];
  A[0] = 0;
  B[0] = 0;
  for(int i = 1; i <= n; i++)
  {
    cin >> A[i];
  }
  cin >> m;

  for(int i = 1; i <= m; i++)
  {
    cin >> B[i];
  }
  vector<int> partSeqA;
  vector<int> partSeqB;
  for(int i = 1; i <= n; i++)
  {
    int sum = A[i];
    partSeqA.push_back(sum);
    for(int j = i + 1; j <= n; j++)
    {
      sum += A[j];
      partSeqA.push_back(sum);
    }
  }
  for(int i = 1; i <= m; i++)
  {
    int sum = B[i];
    partSeqB.push_back(sum);
    for(int j = i + 1; j <= m; j++)
    {
      sum += B[j];
      partSeqB.push_back(sum);
    }
  }
  sort(partSeqA.begin(), partSeqA.end());
  sort(partSeqB.begin(), partSeqB.end());
  int p1 = 0;
  int p2 = partSeqB.size() - 1;
  long long cnt = 0;
  while(true)
  {
    if(partSeqA[p1] + partSeqB[p2] == t) {
      long long cntA = 1;
      long long cntB = 1;
      while(p1 + 1 < partSeqA.size() && partSeqA[p1] == partSeqA[p1 + 1]) {
        p1++;
        cntA++;
      }
      while(p2 - 1 >= 0 && partSeqB[p2] == partSeqB[p2 -1]) {
        p2--;
        cntB++;
      }
      cnt += cntA * cntB;
      p1++;
    }
    if(p1 < partSeqA.size() && p2 >= 0 && partSeqA[p1] + partSeqB[p2] < t)
    {
      p1++;
    }
    if(p1 < partSeqA.size() && p2 >= 0 && partSeqA[p1] + partSeqB[p2] > t)
    {
      p2--;
    }
    if(p1 >= partSeqA.size() || p2 < 0) {
      break;
    }
  }
  cout << cnt;
  return 0;
}