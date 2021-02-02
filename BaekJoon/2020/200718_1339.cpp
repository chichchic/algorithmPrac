#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

long long curMax = 0;
int alpha = 0;

int main()
{
  // freopen("input.txt", "r", stdin);
  unordered_map<char, int> alpahTable;
  int n;
  cin >> n;
  vector<string> input(n);
  int fastCalc[10] = {};
  int alphaCandi[10] = {};
  for (int i = 0; i < n; i++)
  {
    cin >> input[i];
    reverse(input[i].begin(), input[i].end());
    int ten = 1;
    unordered_map<char, int>::iterator itr;
    for (int j = 0; j < input[i].length(); j++)
    {
      itr = alpahTable.find(input[i][j]);
      if (itr != alpahTable.end())
      {
        fastCalc[alpahTable[input[i][j]]] += ten;
      }
      else
      {
        alpahTable.insert(make_pair(input[i][j], alpha++));
        fastCalc[alpahTable[input[i][j]]] += ten;
      }
      ten *= 10;
    }
  }
  int numCandi = 9;
  sort(fastCalc, fastCalc + alpha, greater<int>());
  for (int i = 0; i < alpha; i++)
  {
    curMax += fastCalc[i] * numCandi--;
  }
  printf("%lld\n", curMax);
  return 0;
}