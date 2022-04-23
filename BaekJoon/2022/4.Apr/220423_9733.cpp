#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  char work[3];
  string order[7] = {"Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex"};
  unordered_map<string, int> table;
  double total = 0;
  while (scanf("%s", work) != EOF)
  {
    if (table.find(work) == table.end())
    {
      table[work] = 0;
    }
    table[work]++;
    total++;
  }
  for (int i = 0; i < 7; i++)
  {
    string cur = order[i];
    if (table.find(cur) == table.end())
    {
      table[cur] = 0;
    }
    printf("%s %d %.2f\n", cur.c_str(), table.find(cur)->second, table.find(cur)->second / total);
  }
  printf("Total %d 1.00", (int)total);

  return 0;
}