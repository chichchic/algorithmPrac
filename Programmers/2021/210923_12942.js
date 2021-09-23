sfunction solution(matrix_sizes) {
  const dp = Array.from(matrix_sizes, () => Array(matrix_sizes.length).fill(-1));
  function getDp(left, right) {
    if (dp[left][right] !== -1) return dp[left][right];
    if (left === right) return dp[left][right] = 0;
    if (right - left <= 1) {
      return dp[left][right] = matrix_sizes[left][0] * matrix_sizes[left][1] * matrix_sizes[right][1];
    }
    let candidate = Infinity;
    for (let i = left; i < right; i++) {
      candidate = Math.min(candidate, getDp(left, i) + getDp(i + 1, right) +
        matrix_sizes[left][0] * matrix_sizes[i][1] * matrix_sizes[right][1])
    }
    return dp[left][right] = candidate
  }

  return getDp(0, matrix_sizes.length - 1);
}