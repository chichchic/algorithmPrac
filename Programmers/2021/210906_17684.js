function solution(msg) {
  const dictionary = {}
  const answer = []
  for (let i = 0; i < 26; i++) {
    dictionary[String.fromCharCode(65 + i)] = i + 1
  }
  let dictLastNumber = 26;
  for (let i = 0; i < msg.length; i++) {
    let w = msg[i];
    let next = 0;
    while (dictionary[w] !== undefined) {
      ++next;
      if (i + next >= msg.length) {
        break;
      }
      w += msg[i + next];
    }
    i = i + next - 1;
    answer.push(dictionary[w.slice(0, w.length - (i === msg.length - 1 ? 0 : 1))]);
    if (dictionary[w] === undefined) {
      dictionary[w] = ++dictLastNumber;
    }
  }
  return answer
}