#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define INF 9223372036854775807

using namespace std;

struct load
{
  int to;
  float len;
  bool congestion;
  load() {}
  load(int to, int len, bool congestion) : to(to), len(len), congestion(congestion) {}
};

typedef vector<load> vl;
typedef vector<vl> vvl;
typedef vector<float> vf;
typedef vector<vf> vvf;

int main()
{
  //int long long 으로 바꿔야함
  //TODO:플로이드 와샬을 사용해야함
  freopen("input.txt", "r", stdin);
  int pointNum, loadNum, offS, offE;
  cin >> pointNum >> loadNum >> offS >> offE;
  vvl map(pointNum + 1);
  for (int i = 0; i < loadNum; i++)
  {
    int a, b, t1, t2;
    float l;
    cin >> a >> b >> l >> t1 >> t2;
    map[a].push_back(load(b, l, t1));
    map[b].push_back(load(a, l, t2));
  }
  vf tempVec(pointNum + 1, INF);
  vvf shortCut(pointNum + 1, tempVec);

  for (int i = 1; i <= pointNum; i++)
  {
    shortCut[i][i] = 0;
  }
  vector<bool> check(pointNum + 1, false);
  check[1] = true;

  //오프시간 계산하는것부터 다시 시작

  for (int i = 0; i < map[1].size(); i++)
  {
    int to = map[1][i].to;
    int congestion = map[1][i].congestion;
    float len = map[1][i].len;
    if (congestion && len > offS)
    {
      if (len <= float(offE))
        shortCut[1][to] = (len - float(offS)) * 2 + offS;
    }
    else
      shortCut[1][to] = len;
  }

  return 0;
}