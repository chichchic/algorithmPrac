function solution(new_id) {
  var answer = "";
  answer = new_id
    .toLowerCase()
    .replace(/[^0-9a-z\-_\.]/g, "")
    .replace(/\.+/g, ".");
  if (answer[0] === ".") {
    answer = answer.slice(1);
  }
  answer = answer.slice(0, 15);
  if (answer.length === 0) {
    answer = "a";
  }
  if (answer[answer.length - 1] === ".") {
    answer = answer.slice(0, answer.length - 1);
  }
  while (answer.length < 3) {
    answer += answer[answer.length - 1];
  }

  return answer;
}

// 다른 사람의 풀이

/*
function solution(new_id) {
    const answer = new_id
        .toLowerCase()
        .replace(/[^\w-.]/g, '')
        .replace(/\.+/g,'.')
        .replace(/^\.|\.$/g, '')
        .replace(/^$/, 'a')
        .slice(0, 15).replace(/\.$/, '')
    const len = answer.length;
    return len > 2 ? answer : answer + answer.charAt(len - 1).repeat(3 - len)
}
*/
