function solution(N, number) {
  var answer = 0;
  const dp = new Array(32001).fill(9);
  for (let i = "1"; i * N <= 32000; i += "1") {
    dp[i * N] = i.length;
  }
  for (let i = 1; i < 8; i++) {
    for (let j = 1; j <= 32000; j++) {
      if (dp[j] > i) continue;
      for (let k = j; k <= 32000; k++) {
        if (dp[k] > i) continue;
        const f = dp[j];
        const s = dp[k];
        const candidate = [j + k, k - j, Math.floor(k / j), j * k];
        candidate.forEach(function (val) {
          if (val != 0 && val <= 32000) {
            dp[val] = Math.min(f + s, dp[val]);
          }
        });
      }
    }
  }
  return dp[number] > 8 ? -1 : dp[number];
}
