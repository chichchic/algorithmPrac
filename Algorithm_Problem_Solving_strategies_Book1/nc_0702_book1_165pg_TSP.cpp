//혼자못품
#include <iostream>
#include <vector>

#define INF 100000
using namespace std;

int tst(vector< vector<int> > ctc, bool city_check[], int current_len, vector<int> path, const int city_num)
{
    if(path.size() == city_num)
    {
        return current_len + ctc[0][path.back()];
    }

    int ans = INF;

    for(int i = 1; i < city_num; i++)
    {
        if(city_check[i]) continue;
        city_check[i] = true;
        int now = path.back();
        path.push_back(i);

        int now_len = tst(ctc, city_check, current_len + ctc[now][i], path, city_num);

        city_check[i] = false;
        path.pop_back();
        ans = (now_len < ans) ? now_len : ans;
    }

    return ans;
}

int main()
{
    int city_num;
    vector< vector<int> > ctc;
    cin >> city_num;
    bool city_check[10] = {true, };
    vector<int> path;
    path.push_back(0);

    for(int i = 0; i < city_num; i++)
    {
        vector<int> temp_vec;
        for(int j = 0; j< city_num; j++)
        {
            int temp;
            cin >> temp;
            temp_vec.push_back(temp);
        }
        ctc.push_back(temp_vec);
    }

    cout << tst(ctc, city_check, 0, path, city_num);

    return 0;
}