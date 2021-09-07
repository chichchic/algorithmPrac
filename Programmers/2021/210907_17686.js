function solution(files) {
  var answer = [];
  const fileInfos = files.map((val) => {
    const s = val.search(/[0-9]/)
    let e = s + 1
    while (/[0-9]/.test(val[e])) {
      e++;
    }
    const head = val.slice(0, s).toLowerCase()
    const number = Number(val.slice(s, e));
    const origin = val
    return { head, number, origin }
  })
  return fileInfos.sort((a, b) => {
    if (a.head === b.head) return a.number - b.number;
    if (a.head < b.head) return -1
    else if (a.head > b.head) return 1
  }).map((v) => v.origin)
}

/*
  //NOTE: 더 좋은 풀이법
  1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
function solution(files) {
    let answerWrap = files.map((file, index) => ({file, index}));
    const compare = (a, b) => {
      const reg = /(\D*)([0-9]*)/i;
      const A = a.match(reg); // group을 통해서 match할 경우 그룹별로 나눠서 Array에 들어옴
      const B = b.match(reg);
      const compareHead = A[1].toLowerCase().localeCompare(B[1].toLowerCase()); //localeCompare을 통해 사전순으로 비교해 숫자값을 반환해준다.
      const compareNumber = (a, b) => {
         return parseInt(a) > parseInt(b) ?
            1 : parseInt(a) < parseInt(b) ?
             -1
            : 0
      }
      return compareHead === 0 ? compareNumber(A[2], B[2]) : compareHead
    }
    answerWrap.sort((a, b) => {
      const result = compare(a.file, b.file);
      return result === 0 ? a.index - b.index : result;
    })
    return answerWrap.map(answer => answer.file);
}
*/