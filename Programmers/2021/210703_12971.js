function solution(sticker) {
  const dp = [];
  const dp2 = [];
  const len = sticker.length;
  if(sticker.length === 1) {
      return sticker[0];
  }
  let answer = Math.max(sticker[0], sticker[1]);
  if(sticker.length === 2) {
      return answer
  }
  dp[0] = sticker[0];
  dp[1] = Math.max(sticker[0], sticker[1]);
  dp2[0] = 0;
  dp2[1] = sticker[1];
  for(let i = 2; i < len; ++i) {
      if(i < len - 1) {
          dp[i] = Math.max(dp[i-1], dp[i-2] + sticker[i]);
          answer = Math.max(answer, dp[i]);
      }
      dp2[i] = Math.max(dp2[i-1], dp2[i-2] + sticker[i]);
      answer = Math.max(answer, dp2[i]);
  }
  return answer;
}