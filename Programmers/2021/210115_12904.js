function isPalindrome(string) {
  let s = 0,
    e = string.length - 1;
  while (s < e) {
    if (string[s] !== string[e]) return 0;
    s++;
    e--;
  }
  return string.length;
}

function solution(s) {
  var answer = 1;
  for (let i = 0; i <= s.length - answer; i++) {
    for (let j = i + 1; j < s.length; j++) {
      const candi = isPalindrome(s.slice(i, j + 1));
      answer = Math.max(answer, candi);
    }
  }

  return answer;
}
