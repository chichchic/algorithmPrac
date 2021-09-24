const MOD = 1e9 + 7;

function findIdx(arr, target) {
  let start = 0, end = arr.length - 1;
  while (start <= end) {
    const mid = Math.floor((start + end) / 2);
    if (arr[mid] === target) return mid;
    if (arr[mid] < target) start = mid + 1;
    else end = mid - 1;
  }
  return -1;
}

function hasHalf(prefix, b, e, dp, idx) {
  const current = b[idx] * Math.pow(2, e - 1);
  let i = findIdx(prefix, prefix[idx + 1] - current) - 1
  const ep = Math.log2((prefix[idx + 1] - prefix[i + 1]) / b[i]);
  if (Math.floor(ep) === ep && dp[i][ep] > 0) {
    return true;
  }
  return false;
}
function findFull(prefix, b, idx, e) {
  const target = prefix[idx + 1] - b[idx] * Math.pow(2, e);
  const full = findIdx(prefix, target) - 1;
  return full < 0 ? 0 : full;
}

function cell(b) {
  const prefix = b.reduce((acc, cur) => (acc.push(acc[acc.length - 1] + cur), acc), [0]);
  const dp = Array.from(b, () => Array(31).fill(0));
  dp[0][0] = 1;
  const total = [];
  for (let i = 1; i < b.length; ++i) {
    dp[i][0] = dp[i - 1].reduce((acc, cur) => (acc + cur) % MOD, 0);
    total.push(dp[i][0]);
    let j = 0;
    while (j < 31) {
      j++;
      if (dp[i][j - 1] <= 0 || !hasHalf(prefix, b, j, dp, i)) {
        break;
      }
      const full = findFull(prefix, b, i, j);
      dp[i][j] = total[full];
    }
  }
  return dp[b.length - 1].reduce((acc, cur) => (acc + cur) % MOD, 0);
}

function solution(a, s) {
  const answer = [];
  let acc = 0;
  for (let i = 0; i < s.length; ++i) {
    const target = a.slice(acc, acc + s[i]);
    acc += s[i];
    answer.push(cell(target));
  }
  return answer;
}

// console.log(solution([1, 1, 1, 1, 1, 1, 2, 5, 8, 2, 1, 1, 4, 8, 8, 8, 12, 6, 6], [4, 3, 1, 5, 6]))
