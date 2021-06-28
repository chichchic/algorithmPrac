//참고 https://minnnne.tistory.com/49
function solution(strs, t) {
  const dp = [];
  for(let i = 0; i < t.length; ++i) {
      const curSpell = t[i];
      const candidate = strs.filter(val => val[val.length-1] === curSpell && val.length - 1 <= i)
      const count = candidate.reduce((acc, cur) => {
          const beginIndex = i - cur.length + 1
          if(t.slice(beginIndex, i + 1) !== cur) {
              return acc;
          }
          if(beginIndex === 0) {
              return 1;
          }
          return Math.min(acc, 1 + dp[beginIndex - 1]);
      }, t.length + 1);
      dp.push(count);
  }
  return dp[t.length - 1] > t.length ? -1 : dp[t.length - 1];
}