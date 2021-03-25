function solution(gems) {
  var answer = [1, gems.length];
  const displayedGem = new Set([...gems]);
  const gemIdx = {};
  for (let i = 0; i < gems.length; i++) {
    const gem = gems[i];
    if (!gemIdx[gem]) {
      gemIdx[gem] = [];
    }
    gemIdx[gem].push(i);
  }
  const gemCnt = displayedGem.size;
  const apeachGems = new Set();
  let fIdx = 0;
  let sIdx = 0;
  function hasGems(f, s, kind) {
    const kindLength = gemIdx[kind].length;
    if (s - f < kindLength) {
      for (let i = f + 1; i <= s; i++) {
        if (gems[i] === kind) return true;
      }
      return false;
    }
    for (let i = 0; i < kindLength; i++) {
      const idx = gemIdx[kind][i];
      if (idx > f && s >= idx) return true;
    }
    return false;
  }
  for (; sIdx < gems.length; sIdx++) {
    const curGem = gems[sIdx];
    apeachGems.add(curGem);
    if (apeachGems.has(curGem)) {
      while (fIdx < sIdx) {
        const kind = gems[fIdx];
        if (hasGems(fIdx, sIdx, kind)) fIdx++;
        else break;
      }
    }
    if (apeachGems.size === gemCnt) {
      const [f, s] = answer;
      if (s - f > sIdx - fIdx) answer = [fIdx + 1, sIdx + 1];
    }
  }
  return answer;
}
