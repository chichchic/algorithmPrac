#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int n, m;
  string temp;
  cin >> n >> m;
  vector<string> inputList(n);
  string check[28] = {
      "Bulbasaur",
      "Ivysaur",
      "Venusaur",
      "Charmander",
      "Charmeleon",
      "Charizard",
      "Squirtle",
      "Wartortle",
      "Blastoise",
      "Caterpie",
      "Metapod",
      "Butterfree",
      "Weedle",
      "Kakuna",
      "Beedrill",
      "Pidgey",
      "Pidgeotto",
      "Pidgeot",
      "Rattata",
      "Raticate",
      "Spearow",
      "Fearow",
      "Ekans",
      "Arbok",
      "Pikachu",
      "Raichu"};
  int hashTable[100001];
  for (int i = 0; i < n; i++)
  {
    int temp = 0;
    //cin >> inputList[i];
    inputList[i] = check[i];
    for (int j = 0; j < inputList[i].size(); j++)
      temp += inputList[i][j];
    temp %= 99991;
    while (true)
    {
      if (temp >= 100000)
        temp = 0;
      if (hashTable[temp++] == 0)
      {
        hashTable[temp] = i + 1;
        break;
      }
    }
  }
  for (int i = 0; i < m; i++)
  {
    cin >> temp;
    if (temp[0] <= '9' && temp[0] >= '0')
    {
      int i = stoi(temp);
      cout << inputList[i - 1] << '\n';
    }
    else
    {
      int tempNum = 0;
      for (int j = 0; j < temp.size(); j++)
        tempNum += temp[j];
      tempNum %= 99991;
      while (true)
      {
        if (tempNum >= 100000)
          tempNum = 0;
        cout << inputList[-1];
        if (hashTable[tempNum] != 0 && temp == inputList[hashTable[tempNum] - 1])
        {
          cout << hashTable[tempNum] << '\n';
          break;
        }
        tempNum++;
      }
    }
  }

  return 0;
}