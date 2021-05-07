//정답
function solution(arr) {
  const maxDP = [...Array(101)].map((_) => Array(101).fill(-101000));
  const minDP = [...Array(101)].map((_) => Array(101).fill(101000));
  const numberCount = Math.ceil(arr.length / 2);

  for (let i = 0; i < numberCount; ++i) {
    maxDP[i][i] = Number(arr[i * 2]);
    minDP[i][i] = Number(arr[i * 2]);
  }

  for (let gap = 1; gap < numberCount; ++gap) {
    for (let start = 0; start < numberCount - gap; ++start) {
      const end = start + gap;
      for (let operatorIndex = start; operatorIndex < end; ++operatorIndex) {
        if (arr[operatorIndex * 2 + 1] === "+") {
          maxDP[start][end] = Math.max(
            maxDP[start][end],
            maxDP[start][operatorIndex] + maxDP[operatorIndex + 1][end]
          );
          minDP[start][end] = Math.min(
            minDP[start][end],
            minDP[start][operatorIndex] + minDP[operatorIndex + 1][end]
          );
        } else if (arr[operatorIndex * 2 + 1] === "-") {
          maxDP[start][end] = Math.max(
            maxDP[start][end],
            maxDP[start][operatorIndex] - minDP[operatorIndex + 1][end]
          );
          minDP[start][end] = Math.min(
            minDP[start][end],
            minDP[start][operatorIndex] - maxDP[operatorIndex + 1][end]
          );
        }
      }
    }
  }
  return maxDP[0][numberCount - 1];
}

//재귀 - TestCase 한개 시간초과
function solution(arr) {
  const maxDP = [...Array(101)].map((_) => Array(101).fill(-101000));
  const minDP = [...Array(101)].map((_) => Array(101).fill(101000));
  function max(start, end) {
    if (start === end) {
      return Number(arr[start * 2]);
    }
    if (maxDP[start][end] === -101000) {
      for (let operatorIndex = start; operatorIndex < end; operatorIndex++) {
        if (arr[operatorIndex * 2 + 1] === "+") {
          maxDP[start][end] = Math.max(
            maxDP[start][end],
            max(start, operatorIndex) + max(operatorIndex + 1, end)
          );
        } else if (arr[operatorIndex * 2 + 1] === "-") {
          maxDP[start][end] = Math.max(
            maxDP[start][end],
            max(start, operatorIndex) - min(operatorIndex + 1, end)
          );
        }
      }
    }
    return maxDP[start][end];
  }
  function min(start, end) {
    if (start === end) {
      return Number(arr[start * 2]);
    }
    if (minDP[start][end] === 101000) {
      for (let operatorIndex = start; operatorIndex < end; operatorIndex++) {
        if (arr[operatorIndex * 2 + 1] === "+") {
          minDP[start][end] = Math.min(
            minDP[start][end],
            min(start, operatorIndex) + min(operatorIndex + 1, end)
          );
        } else if (arr[operatorIndex * 2 + 1] === "-") {
          minDP[start][end] = Math.min(
            minDP[start][end],
            min(start, operatorIndex) - max(operatorIndex + 1, end)
          );
        }
      }
    }
    return minDP[start][end];
  }
  return max(0, Math.ceil(arr.length / 2) - 1);
}
