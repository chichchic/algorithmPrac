function slice(s, num) {
  const result = []
  let idx = 0
  for (let i = 0; i < s.length; ++i) {
    if (result.length === idx) {
      result.push('')
    }
    result[idx] += s[i];
    if (i % num === num - 1) idx++;
  }
  return result
}

function press(words, len) {
  let prev = words[0];
  let sameCnt = 1;
  for (let i = 1; i < words.length; ++i) {
    if (words[i] === prev) {
      len -= words[i].length;
      sameCnt++;
    } else {
      if (sameCnt !== 1) {
        len += Math.floor(Math.log10(sameCnt)) + 1
        sameCnt = 1;
      }
      prev = words[i]
    }
  }
  if (sameCnt !== 1) {
    len += Math.floor(Math.log10(sameCnt)) + 1
  }
  return len;
}

function solution(s) {
  let answer = s.length;
  for (let i = 1; i <= s.length / 2; ++i) {
    const words = slice(s, i);
    const pressedCnt = press(words, s.length);
    answer = Math.min(answer, pressedCnt)
  }
  return answer;
}