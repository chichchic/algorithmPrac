function solution(n, s) {
  var answer = [];
  const mid = Math.floor(s / n);
  if (mid <= 0) return [-1];
  s -= mid * n;
  return Array.from(Array(n), () => {
    if (s > 0) {
      s--;
      return mid + 1;
    }
    return mid;
  }).sort((a, b) => a - b);
}
