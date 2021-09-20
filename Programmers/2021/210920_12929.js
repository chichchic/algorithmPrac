function solution(n) {
  const dp = [1];
  function splitCase(num) {
    let output = 0;
    for (let i = 0; i <= num - 1; i++) {
      output += dp[i] * dp[num - i - 1];
    }
    return output
  }
  for (let i = 1; i <= n; i++) {
    dp.push(splitCase(i));
  }
  return dp[n];
}