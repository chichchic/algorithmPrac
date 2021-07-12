function solution(N, stages) {
  const arrivedCount = new Array(N + 1).fill(0);
  for (const stage of stages) {
      ++arrivedCount[stage - 1];
  }
  const accArrivedCount = [arrivedCount[arrivedCount.length - 1]];
  for(let idx = arrivedCount.length - 2; idx >= 0; --idx) {
      accArrivedCount.push(arrivedCount[idx] + accArrivedCount[accArrivedCount.length - 1]);
  }
  accArrivedCount.reverse();
  arrivedCount.pop();
  return arrivedCount.map((val, idx) => {
      if(val === 0) {
          return [0, idx + 1];
      }
      return [val / accArrivedCount[idx], idx + 1];
  }).sort((a, b) => {
      if(a[0] === b[0]) {
          return a[1] - b[1];
      }
      return b[0] - a[0];
  }).map(val => val[1]);
}