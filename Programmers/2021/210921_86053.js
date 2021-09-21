
function solution(a, b, g, s, w, t) {
  const len = t.length;
  function delivery(time) {
    let maxGold = 0;
    let maxSilver = 0;
    let totalWeight = 0;
    for (let i = 0; i < len; ++i) {
      const count = Math.ceil(Math.floor(time / t[i]) / 2);
      maxGold += Math.min(g[i], count * w[i]);
      maxSilver += Math.min(s[i], count * w[i]);
      totalWeight += Math.min(g[i] + s[i], count * w[i]);
    }
    if (a <= maxGold && b <= maxSilver && totalWeight >= (a + b)) return true;
    return false;
  }
  let lo = 0, hi = 10e15;
  while (lo + 1 < hi) {
    const mid = Math.floor((lo + hi) / 2);
    if (delivery(mid)) {
      hi = mid;
    } else {
      lo = mid
    }
  }
  return hi;
}