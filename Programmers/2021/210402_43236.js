function solution(distance, rocks, n) {
  rocks.sort((a, b) => a - b);
  rocks.push(distance);
  function crossRiver(gap) {
    let pre = 0;
    let count = 0;
    for (const rock of rocks) {
      if (rock - pre < gap) {
        count++;
      } else {
        pre = rock;
      }
      if (count > n) {
        return false;
      }
    }
    return true;
  }

  let start = 1,
    end = 1000000001;
  while (end - start > 1) {
    const mid = Math.floor((start + end) / 2);
    if (crossRiver(mid)) {
      start = mid;
    } else {
      end = mid;
    }
  }

  return start;
}
