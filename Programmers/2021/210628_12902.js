// 참고: https://wonillism.github.io/programmers/Programmers-3xn-tiling/
function solution(n) {
    const dp = Array(5001).fill(false);
    const mod = 1000000007;
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    for(let cur = 4; cur <= n; cur += 2) {
        dp[cur] = 3 * dp[cur - 2];
        for(let i = 4; i <= cur; i += 2) {
            dp[cur] += 2 * dp[cur - i];
        }
        dp[cur] %= mod;
    }
    return dp[n];
}