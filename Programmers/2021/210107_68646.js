function solution(a) {
  var answer = 0;
  const len = a.length;
  const leftDirection = [];
  const rightDirection = [];

  leftDirection.push(a[0]);
  let small = a[0];
  for (let i = 1; i < len; i++) {
    small = Math.min(small, a[i]);
    leftDirection.push(small);
    rightDirection.push(-1);
  }

  rightDirection[len - 1] = a[len - 1];
  small = a[len - 1];
  for (let i = len - 2; i >= 0; i--) {
    small = Math.min(small, a[i]);
    rightDirection[i] = small;
  }
  for (let i = 0; i < len; i++) {
    if (a[i] > leftDirection[i] && a[i] > rightDirection[i]) continue;
    answer++;
  }

  return answer;
}
