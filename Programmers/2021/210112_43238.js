function calcOutput(times, time) {
  return times.reduce((acc, cur) => {
    return acc + Math.floor(time / cur);
  }, 0);
}

function solution(n, times) {
  let end = 1000000000000000001;
  let begin = 0;
  let answer = end;
  while (begin + 1 < end) {
    const mid = Math.floor((begin + end) / 2);
    const output = calcOutput(times, mid);
    if (output >= n) {
      answer = Math.min(answer, mid);
      end = mid;
    } else if (output < n) {
      begin = mid;
    }
  }
  return answer;
}
