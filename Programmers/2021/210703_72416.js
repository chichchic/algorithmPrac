//참고: https://yabmoons.tistory.com/625
function solution(sales, links) {
  const employNum = sales.length;
  const linkNodes = Array.from(new Array(employNum), _ => []);
  links.forEach(([parent, child]) => {
      linkNodes[parent-1].push(child-1);
  })
  const dp = Array.from(new Array(employNum), _ => []);
  const dfs = function(num) {
      if(linkNodes[num].length === 0) {
          dp[num] = [0, sales[num]]
          return;
      }
      linkNodes[num].forEach(val => dfs(val));
      let nonAttend = 0;
      let teamAttend = false;
      for(let i = 0; i < linkNodes[num].length; ++i) {
          const crewNum = linkNodes[num][i];
          if(dp[crewNum][1] <= dp[crewNum][0]) {
              teamAttend = true;
              nonAttend += dp[crewNum][1];
              continue;
          }
          nonAttend += dp[crewNum][0];
      }
      if(!teamAttend) {
          nonAttend += Math.min(...linkNodes[num].map((crewNum) => dp[crewNum][1] - dp[crewNum][0]))
      }
      const attend = linkNodes[num].reduce((acc, cur) => {
          return acc + Math.min(...dp[cur]);
      }, sales[num]);
      dp[num] = [nonAttend, attend];
  }
  dfs(0);
  return Math.min(...dp[0]);
}