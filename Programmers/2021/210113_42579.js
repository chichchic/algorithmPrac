function push(arr, value) {
  const arrIdx = arr.findIndex(([val, idx]) => {
    if (val === value[0]) {
      return idx > value[1];
    }
    return val < value[0];
  });
  if (arrIdx === -1) {
    arr.push(value);
  } else {
    arr.splice(arrIdx, 0, value);
  }
}

function solution(genres, plays) {
  var answer = [];
  const len = genres.length;
  const group = {};
  const groupTotal = {};
  for (let i = 0; i < len; i++) {
    const curG = genres[i];
    const curP = plays[i];
    if (!group[curG]) {
      group[curG] = [];
      groupTotal[curG] = 0;
    }
    groupTotal[curG] += curP;
    push(group[curG], [curP, i]);
  }
  const sortA = [];
  for (const key in groupTotal) {
    sortA.push([groupTotal[key], key]);
  }
  sortA.sort((a, b) => b[0] - a[0]);
  sortA.forEach(([_, key]) => {
    const cur = group[key];
    answer.push(cur[0][1]);
    if (cur.length >= 2) {
      answer.push(cur[1][1]);
    }
  });
  return answer;
}
