function solution(a, b) {
  return a.reduce((acc, cur, idx) => {
    return acc + cur * b[idx];
  }, 0);
}
