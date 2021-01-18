function solution(n, money) {
  let cur = Array(n + 1).fill(0);
  cur[0] = 1;
  for (let i = 0; i < money.length; i++) {
    const cost = money[i];
    for (let j = cost; j <= n; j++) {
      cur[j] += cur[j - cost];
    }
  }
  return cur[n];
}
