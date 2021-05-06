function rotate(matrix, x1, y1, x2, y2) {
  x1--;
  y1--;
  x2--;
  y2--;
  let memo = matrix[x1 + 1][y1];
  let min = 10001;
  for (let c = y1; c <= y2; c++) {
    const temp = matrix[x1][c];
    min = Math.min(min, temp);
    matrix[x1][c] = memo;
    memo = temp;
  }
  for (let r = x1 + 1; r <= x2; r++) {
    const temp = matrix[r][y2];
    min = Math.min(min, temp);
    matrix[r][y2] = memo;
    memo = temp;
  }
  for (let c = y2 - 1; c >= y1; c--) {
    const temp = matrix[x2][c];
    min = Math.min(min, temp);
    matrix[x2][c] = memo;
    memo = temp;
  }
  for (let r = x2 - 1; r > x1; r--) {
    const temp = matrix[r][y1];
    min = Math.min(min, temp);
    matrix[r][y1] = memo;
    memo = temp;
  }
  return min;
}

function solution(rows, columns, queries) {
  let number = 0;
  const matrix = Array.from(Array(rows), () =>
    Array(columns)
      .fill(1)
      .map(() => ++number)
  );
  return queries.map((query) => {
    return rotate(matrix, ...query);
  });
}
