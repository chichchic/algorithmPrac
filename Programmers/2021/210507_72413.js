function solution(n, s, a, b, fares) {
  const distance = [...Array(n + 1)].map((_) => Array(n + 1).fill(Infinity));
  for (let i = 0; i <= n; i++) {
    distance[i][i] = 0;
  }
  fares.forEach(([start, end, cost]) => {
    distance[start][end] = cost;
    distance[end][start] = cost;
  });
  for (let k = 1; k <= n; ++k) {
    for (let i = 1; i <= n; ++i) {
      for (let j = 1; j <= n; ++j) {
        distance[i][j] = Math.min(
          distance[i][j],
          distance[i][k] + distance[j][k]
        );
      }
    }
  }
  let answer = distance[s][a] + distance[s][b];
  for (let k = 1; k <= n; ++k) {
    answer = Math.min(answer, distance[k][s] + distance[k][a] + distance[k][b]);
  }
  return answer;
}
