#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Trie
{
private:
  bool end;
  map<string, Trie *> foodList;

public:
  Trie()
  {
    end = false;
  }
  ~Trie()
  {
    for (auto iter = foodList.begin(); iter != foodList.end(); iter++)
    {
      delete iter->second;
    }
  }

  void insert(string foodStr)
  {
    if (foodStr == "")
    {
      end = true;
      return;
    }
    int blankIndex = foodStr.find_first_of(' ');
    string food;
    string remainFood;
    if (blankIndex != string::npos)
    {
      food = foodStr.substr(0, blankIndex);
      remainFood = foodStr.substr(blankIndex + 1);
    }
    else
    {
      food = foodStr;
      remainFood = "";
    }

    if (foodList.find(food) == foodList.end())
    {
      foodList[food] = new Trie();
    }
    foodList[food]->insert(remainFood);
  }

  void print(int depth)
  {
    for (auto iter = foodList.begin(); iter != foodList.end(); iter++)
    {
      for (int i = 0; i < depth; i++)
      {
        cout << "--";
      }

      cout << iter->first << '\n';
      if (!end)
        iter->second->print(depth + 1);
    }
  }
};

int main()
{
  freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  Trie trie = Trie();
  for (int i = 0; i < n; i++)
  {
    int step;
    cin >> step;
    string food;
    getline(cin, food);
    trie.insert(food.substr(1));
  }
  trie.print(0);
  return 0;
}