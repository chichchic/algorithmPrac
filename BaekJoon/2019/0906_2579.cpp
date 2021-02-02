#include <iostream>
#include <utility>

using namespace std;

int main()
{
    int num_step;
    cin >> num_step;
    int score[301];
    for(int i = 0; i < num_step; i++)
    {
        cin >> score[i];
    }

    int dp[301][2] = {};
    dp[1][0] = score[num_step-1];
    dp[2][1] = dp[1][0] + score[num_step-2];
    int ans = dp[2][1];

    for(int i = num_step-3; i >= 0; i--)
    {
        int index = num_step - i;
        if(dp[index-1][0] != 0)
            dp[index][1] = dp[index-1][0] + score[i];
        dp[index][0] = max(dp[index-2][0], dp[index-2][1]) + score[i];
        ans = max(ans, max(dp[index][0], dp[index][1]));
    }

    cout << ans << endl;

    return 0;
}
/*

    다른 방식의 코드
    앞에서부터 올라오는 방식을 사용
    두칸전의 값과 지금의 값을 더하기 VS 세칸전의 값과 이전값(이전 계단을 두칸뛰어 도착했을 경우)에 지금의 값을 더하는 경우를 비교하여 큰값을 사용하는 방식

    보다 효율적임. 

#include <cstdio>
#define max(a,b) (((a)>(b))?(a):(b))

int main(void)
{
    int a[301];
    int d[301];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    d[1]=a[1];
    d[2]=a[1]+a[2];
    for(int i=3;i<=n; i++)
    {
        d[i]=max(d[i-2]+a[i], d[i-3]+a[i]+a[i-1]); 
    }

    printf("%d\n",d[n]);


    return 0;

}
*/