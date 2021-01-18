function solution(n) {
  const cur = [];
  cur.push(0);
  cur.push(1);
  cur.push(2);
  for (let i = 3; i <= n; i++) {
    const path = (cur[i - 1] + cur[i - 2]) % 1234567;
    cur.push(path);
  }
  return cur[n];
}
