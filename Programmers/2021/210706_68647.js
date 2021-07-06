//참고: https://yabmoons.tistory.com/583

function solution(a) {
  const combination = Array.from(new Array(301), (val, index) => new Array(index+1).fill(1n));
  const rowLen = a.length;
  const colLen = a[0].length ;
  const MOD = BigInt(1e7 + 19)
  for(let n = 2; n <= 300; ++n) {
      for(let r = 1; r < n; ++r) {
          combination[n][r] = BigInt(combination[n-1][r-1] + combination[n-1][r]) % MOD;
      }
  }
  const colCnt = [];
  for(let col = 0; col < colLen; ++col) {
      let count = 0;
      for(let r = 0; r < rowLen; ++r) {
          count += a[r][col]
      }
      colCnt.push(count);
  }
  const dp = Array.from(new Array(302), _ => new Array(302).fill(0n));
  dp[0][rowLen - colCnt[0]] = combination[rowLen][rowLen - colCnt[0]];
  for(let col = 1; col < colLen; ++col) {
      const colOneCnt = colCnt[col];
      for(let evenNum = 0; evenNum <= rowLen; ++evenNum) {
          if(dp[col-1][evenNum] === 0) continue;
          for(let k = 0; k <= evenNum && k <= colOneCnt; ++k) {
              const beEvenNum = evenNum - k + colOneCnt - k
              if(beEvenNum > rowLen) continue;
              if(rowLen - evenNum < colOneCnt - k) continue;
              const result =
                  (combination[evenNum][k] * combination[rowLen - evenNum][colOneCnt - k]) % MOD;
              dp[col][beEvenNum] += dp[col-1][evenNum] * result;
              dp[col][beEvenNum] %= MOD;
          }
      }
  }
  return dp[colLen-1][rowLen]
}