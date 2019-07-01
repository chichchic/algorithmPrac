/*
//내가 푼 방법
#include <iostream>
#include <vector>

using namespace std;

int ansCnt = 0;

void cntPair(vector< pair<int, int> > input, int stdlist[], int remainPair, int index)
{
    if(remainPair == 0) { ansCnt++; return;}
    for(int i = index; i < input.size(); i++)
    {
        if(stdlist[input[i].first] != 0 || stdlist[input[i].second] != 0)
            continue;
        stdlist[input[i].first] = 1;
        stdlist[input[i].second] = 1;
        cntPair(input, stdlist, remainPair-1, i);
        stdlist[input[i].first] = 0;
        stdlist[input[i].second] = 0;
    }
}

int main()
{
    int testCase, stdNum, pairNum;
    cin >> testCase;
    while(testCase--)
    {
        ansCnt = 0;
        int stdList[10] = {};
        cin >> stdNum >> pairNum;
        vector< pair<int, int> > input;
        for(int i = 0; i < pairNum; i++)
        {
            pair<int, int> temp;
            cin >> temp.first >> temp.second;
            input.push_back(temp);
        }
        cntPair(input, stdList, stdNum/2, 0);
        cout << ansCnt << endl;
    }
    
    return 0;
}
*/

#include <iostream>

using namespace std;

bool freind[10][10] = {false};

int countPairings(int std_num, bool couple[])
{
    int smallest = -1;
    int ans = 0;

    for(int i = 0; i < std_num; i++)
    {
        if(!couple[i])
        {
            smallest = i;
            break;
        }
    }
    if(smallest == -1) return 1;

    for(int i = smallest+1; i < std_num; i++)
    {
        if(!couple[i] && freind[smallest][i])
        {
            couple[i] = true;
            couple[smallest] = true;
            ans += countPairings(std_num, couple);
            couple[i] = false;
            couple[smallest] = false;
        }
    }

    return ans;
}

int main()
{
    int test_case, std_num, pair_num, temp1, temp2;
    cin >> test_case;
    while(test_case--)
    {
        cin >> std_num >> pair_num;
        bool couple[10] = {};
        fill(&freind[0][0], &freind[9][10], false);
        for(int i = 0; i < pair_num; i++)
        {
            cin >> temp1 >> temp2;
            freind[temp1][temp2] = true;
            freind[temp2][temp1] = true;
        }
        cout << countPairings(std_num, couple) << endl;
    }
}