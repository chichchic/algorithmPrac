function isAllthingSame(isRoot) {
  for (let i = 0; i < isRoot.length - 1; i++) {
    if (isRoot[i] !== isRoot[i + 1]) return false;
  }
  return true;
}

function makeSameRoot(isRoot, smallNum, bigNum) {
  isRoot.forEach((val, index) => {
    isRoot[index] === bigNum && (isRoot[index] = smallNum);
  });
}

function solution(n, costs) {
  var answer = 0;
  const isRoot = Array.from(Array(n), (_, idx) => idx);

  costs.sort((a, b) => a[2] - b[2]);

  for (var val of costs) {
    const [candi1, candi2, cost] = val;
    const first = isRoot[candi1];
    const second = isRoot[candi2];
    if (first === second) continue;
    const smallNum = Math.min(first, second);
    const bigNum = Math.max(first, second);
    makeSameRoot(isRoot, smallNum, bigNum);
    answer += cost;
    if (isAllthingSame(isRoot)) break;
  }
  return answer;
}
