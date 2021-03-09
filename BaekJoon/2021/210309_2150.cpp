#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dsfn[10001] = {};
bool finished[10001] = {};
int sccNum[10001] = {};
vector<int> stack;
vector<int> children[10001];
vector<vector<int>> scc;
int dsfnCnt = 0;

int dfs(int curNum)
{
  dsfn[curNum] = ++dsfnCnt;
  stack.push_back(curNum);

  int result = dsfn[curNum];
  for (int i = 0; i < children[curNum].size(); i++)
  {
    int nextNum = children[curNum][i];
    if (dsfn[nextNum] == 0)
    {
      result = min(result, dfs(nextNum));
    }
    // 교차 간선 중 역방향으로 가는 경우
    else if (!finished[nextNum])
    {
      result = min(result, dsfn[nextNum]);
    }
  }
  if (result == dsfn[curNum])
  {
    vector<int> sccGroup;
    while (true)
    {
      int top = stack.back();
      stack.pop_back();
      sccGroup.push_back(top);
      finished[top] = true;
      sccNum[top] = scc.size();
      if (top == curNum)
      {
        break;
      }
    }
    sort(sccGroup.begin(), sccGroup.end());
    scc.push_back(sccGroup);
  }
  return result;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int vNum, eNum;
  cin >> vNum >> eNum;

  for (int i = 0; i < eNum; i++)
  {
    int u, v;
    cin >> u >> v;
    children[u].push_back(v);
  }
  for (int i = 1; i < vNum; i++)
  {
    if (dsfn[i] != 0)
    {
      continue;
    }
    dfs(i);
  }
  sort(scc.begin(), scc.end());

  cout << scc.size() << '\n';
  for (int i = 0; i < scc.size(); i++)
  {
    for (int j = 0; j < scc[i].size(); j++)
    {
      cout << scc[i][j] << ' ';
    }
    cout << "-1\n";
  }

  return 0;
}