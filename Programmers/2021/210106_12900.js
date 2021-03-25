function solution(n) {
  var answer = 0;
  if (n === 1) return 1;
  if (n === 2) return 2;
  var first = 1;
  var second = 2;
  for (let i = 2; i < n; i++) {
    var temp = second;
    second += first;
    first = temp;
    second %= 1000000007;
    first %= 1000000007;
  }
  return second;
}
