function solution(n) {
  var answer = "";
  const num = ["4", "1", "2"];
  while (n) {
    const rest = n % 3;
    answer = num[rest] + answer;
    n = Math.floor(n / 3);

    if (rest === 0) {
      n -= 1;
    }
  }
  return answer;
}
