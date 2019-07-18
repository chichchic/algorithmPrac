//인생 최고 병신짓한 문제

#include <iostream>

using namespace std;

int xHeap[300000] = {};
int heap_size = 0;

void insert(int i)
{
    int check = heap_size;
    xHeap[heap_size++] = i;

    while(check > 0)
    {
        if(xHeap[check] > xHeap[(check-1)/2])
        {
            int temp = xHeap[check];
            xHeap[check] = xHeap[(check-1)/2];
            xHeap[(check-1)/2] = temp;
            check = (check-1)/2;
        }
        else
        {
            break;
        }
    }
}

int pop()
{
    if(heap_size == 0)
        return 0;
    
    int return_val = xHeap[0];
    int check = 0;

    xHeap[0] = xHeap[heap_size-1]; // -1 안붙여서 계속 틀림....
    xHeap[heap_size--] = 0;

    while(1)
    {
        if(check*2+1 > heap_size) break;
        if(xHeap[check] < xHeap[check*2+1] || xHeap[check] < xHeap[check*2+2])
        {
            int index;
            if(xHeap[check*2+1] > xHeap[check*2+2])
                index = check*2+1;
            else
                index = check*2+2;

            int temp = xHeap[check];
            xHeap[check] = xHeap[index];
            xHeap[index] = temp;
            check = index;
        }
        else
        {
            break;
        }
    }
    
    return return_val;
}

int main()
{
    int _case, input;
    cin >> _case;

    while(_case--)
    {
        scanf("%d", &input);

        if(input > 0) // 삽입
        {
            insert(input);
        }
        else if(input == 0)// 출력
        {
            printf("%d\n",pop());
        }
    }

    return 0;
}