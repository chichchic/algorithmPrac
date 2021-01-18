function canCandidate(banStr, userStr) {
  if (banStr.length !== userStr.length) return false;
  for (let i = 0; i < banStr.length; i++) {
    const curChar = banStr[i];
    if (curChar === "*") continue;
    if (userStr[i] !== curChar) return false;
  }
  return true;
}

function solution(user_id, banned_id) {
  var answer = 0;
  const banList = new Set();
  const userLen = user_id.length;
  const banLen = banned_id.length;
  const list = Array(userLen).fill(false);
  function ban(banIdx) {
    if (banIdx >= banLen) {
      const candidateList = list.reduce((acc, cur, idx) => {
        if (cur) {
          acc += "1";
        } else {
          acc += "0";
        }
        return acc;
      }, "");
      banList.add(candidateList);
      return;
    }
    const banStr = banned_id[banIdx];
    for (let i = 0; i < user_id.length; i++) {
      const userStr = user_id[i];
      if (!list[i] && canCandidate(banStr, userStr)) {
        list[i] = true;
        ban(banIdx + 1);
        list[i] = false;
      }
    }
  }
  ban(0);
  return banList.size;
}
