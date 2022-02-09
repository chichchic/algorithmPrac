//NOTE: https://cocoon1787.tistory.com/360

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int n;
vector<vector<bool>> weights(32, vector<bool>(1e7, false));
vector<int> input(32);

void getWeight(int i, int w)
{
  if(weights[i][w] || i > n) {
    return;
  }
  weights[i][w] = true;
  getWeight(i + 1, w + input[i]);
  getWeight(i + 1, w);
  getWeight(i + 1, abs(w - input[i]));
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> input[i];
  }
  getWeight(0,0);
  int m;
  cin >> m;
  for(int i = 0; i < m; i++)
  {
    int test;
    cin >> test;
    cout << (weights[n][test] ? "Y " : "N ");
  }
  return 0;
}