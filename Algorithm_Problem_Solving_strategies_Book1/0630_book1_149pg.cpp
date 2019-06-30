#include <iostream>
#include <vector>

using namespace std;

void print_pick_store(vector<int> pick_store, int size)
{
    for(int i = 0; i < size-1; i++)
    {
        cout << pick_store[i] << " ";
    }
    cout << pick_store[size-1] << endl;
}

void pick(const vector<int> input, vector<int> & pick_store, int remain_cnt, const int input_size, int smallest, const int max_cnt)
{
    if(remain_cnt == 0)
    {
        print_pick_store(pick_store, max_cnt);
        return;
    }

    for(int i = smallest; i < input_size; i++)
    {
        pick_store.push_back(input[i]);
        pick(input, pick_store, remain_cnt-1, input_size, i, max_cnt);
        pick_store.pop_back();
    }
}

int main()
{
    int pic_cnt, input_size, temp;
    vector<int> input, pick_store;
    cin >> input_size >> pic_cnt;

    for(int i = 0; i < input_size; i++)
    {
        cin >> temp;
        input.push_back(temp);
    }

    pick(input, pick_store, pic_cnt, input_size, 0, pic_cnt);

    return 0;
}