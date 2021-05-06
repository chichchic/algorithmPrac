function solution(lottos, win_nums) {
  const result = [6, 6, 5, 4, 3, 2, 1];
  const worst = lottos.reduce((acc, cur) => {
    if (win_nums.findIndex((val) => cur === val) < 0) {
      return acc;
    }
    return acc + 1;
  }, 0);
  const best = lottos.reduce((acc, cur) => {
    if (cur === 0) {
      return acc + 1;
    }
    if (win_nums.findIndex((val) => cur === val) < 0) {
      return acc;
    }
    return acc + 1;
  }, 0);
  return [result[best], result[worst]];
}
