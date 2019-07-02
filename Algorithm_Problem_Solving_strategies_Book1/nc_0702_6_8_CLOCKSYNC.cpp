//혼자 못품

#include <iostream>

#define INF 100

using namespace std;

void click(int clock[], int sw_num) // 버튼 입력시 변화값
{
    switch(sw_num)
    {
        case 0:
            clock[0] = ++clock[0]%4;
            clock[1] = ++clock[1]%4;
            clock[2] = ++clock[2]%4;
            break;
        case 1:
            clock[3] = ++clock[3]%4;
            clock[7] = ++clock[7]%4;
            clock[9] = ++clock[9]%4;
            clock[11] = ++clock[11]%4;
            break;
        case 2:
            clock[4] = ++clock[4]%4;
            clock[10] = ++clock[10]%4;
            clock[14] = ++clock[14]%4;
            clock[15] = ++clock[15]%4;
            break;
        case 3:
            clock[0] = ++clock[0]%4;
            clock[4] = ++clock[4]%4;
            clock[5] = ++clock[5]%4;
            clock[6] = ++clock[6]%4;
            clock[7] = ++clock[7]%4;
            break;
        case 4:
            clock[6] = ++clock[6]%4;
            clock[7] = ++clock[7]%4;
            clock[8] = ++clock[8]%4;
            clock[10] = ++clock[10]%4;
            clock[12] = ++clock[12]%4;
            break;
        case 5:
            clock[0] = ++clock[0]%4;
            clock[2] = ++clock[2]%4;
            clock[14] = ++clock[14]%4;
            clock[15] = ++clock[15]%4;
            break;
        case 6:
            clock[3] = ++clock[3]%4;
            clock[14] = ++clock[14]%4;
            clock[15] = ++clock[15]%4;
            break;
        case 7:
            clock[4] = ++clock[4]%4;
            clock[5] = ++clock[5]%4;
            clock[7] = ++clock[7]%4;
            clock[14] = ++clock[14]%4;
            clock[15] = ++clock[15]%4;
            break;
        case 8:
            clock[1] = ++clock[1]%4;
            clock[2] = ++clock[2]%4;
            clock[3] = ++clock[3]%4;
            clock[4] = ++clock[4]%4;
            clock[5] = ++clock[5]%4;
            break;
        case 9:
            ++clock[3] %= 4;
            ++clock[4] %= 4;
            ++clock[5] %= 4;
            ++clock[9] %= 4;
            ++clock[13] %= 4;
            break;
    }
}

void unClick(int clock[], int sw_num) // 버튼 입력 취소 변화값
{
    switch(sw_num)
    {
        case 0:
            clock[0] = --clock[0]%4;
            clock[1] = --clock[1]%4;
            clock[2] = --clock[2]%4;
            break;
        case 1:
            clock[3] = --clock[3]%4;
            clock[7] = --clock[7]%4;
            clock[9] = --clock[9]%4;
            clock[11] = --clock[11]%4;
            break;
        case 2:
            clock[4] = --clock[4]%4;
            clock[10] = --clock[10]%4;
            clock[14] = --clock[14]%4;
            clock[15] = --clock[15]%4;
            break;
        case 3:
            clock[0] = --clock[0]%4;
            clock[4] = --clock[4]%4;
            clock[5] = --clock[5]%4;
            clock[6] = --clock[6]%4;
            clock[7] = --clock[7]%4;
            break;
        case 4:
            clock[6] = --clock[6]%4;
            clock[7] = --clock[7]%4;
            clock[8] = --clock[8]%4;
            clock[10] = --clock[10]%4;
            clock[12] = --clock[12]%4;
            break;
        case 5:
            clock[0] = --clock[0]%4;
            clock[2] = --clock[2]%4;
            clock[14] = --clock[14]%4;
            clock[15] = --clock[15]%4;
            break;
        case 6:
            clock[3] = --clock[3]%4;
            clock[14] = --clock[14]%4;
            clock[15] = --clock[15]%4;
            break;
        case 7:
            clock[4] = --clock[4]%4;
            clock[5] = --clock[5]%4;
            clock[7] = --clock[7]%4;
            clock[14] = --clock[14]%4;
            clock[15] = --clock[15]%4;
            break;
        case 8:
            clock[1] = --clock[1]%4;
            clock[2] = --clock[2]%4;
            clock[3] = --clock[3]%4;
            clock[4] = --clock[4]%4;
            clock[5] = --clock[5]%4;
            break;
        case 9:
            --clock[3] %= 4;
            --clock[4] %= 4;
            --clock[5] %= 4;
            --clock[9] %= 4;
            --clock[13] %= 4;
            break;
    }
}

bool clockCheck(int clock[]) // 모두 12시인지 확인
{
    for(int i = 0; i < 16; i++)
    {
        if(clock[i] != 0)
            return false;
    }
    return true;
}
int solve(int clock[], int sw_num)
{
    if(sw_num == 10) return clockCheck(clock) ? 0 : INF;

    int ans = INF;

    for(int i = 0; i < 4; i++)
    {
        ans = min(ans, i + solve(clock, sw_num+1));
        click(clock, sw_num);
    }

    return ans;
}

int main()
{
    int test_case, input_temp;
    cin >> test_case;

    while(test_case--)
    {
        int clock[16];
        int scn[16] ={};

        for(int i = 0; i < 16; i++) // 시계 값 입력
        {
            cin >> input_temp;
            switch (input_temp)
            {
            case 12:
                clock[i] = 0;
                break;
            
            case 3:
                clock[i] = 1;
                break;

            case 6:
                clock[i] = 2;
                break;

            case 9:
                clock[i] = 3;
                break;
            
            default:
                break;
            }
        }
        int temp = solve(clock, 0);
        if(temp == INF) cout << -1 << endl;
        else cout << temp << endl;
    }

    return 0;
}