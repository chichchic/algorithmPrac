function solution(triangle) {
  var answer = 0;
  let dp1 = [triangle[0][0]];
  let dp2 = [];
  const triLen = triangle.length;
  for (let i = 1; i < triLen; i++) {
    const floor = triangle[i];
    for (let j = 0; j < floor.length; j++) {
      if (j === 0) {
        dp2.push(dp1[0] + floor[0]);
      } else if (j === floor.length - 1) {
        dp2.push(dp1[j - 1] + floor[j]);
      } else {
        const big = Math.max(dp1[j - 1], dp1[j]);
        dp2.push(big + floor[j]);
      }
    }
    dp1 = dp2;
    dp2 = [];
  }
  return Math.max(...dp1);
}
