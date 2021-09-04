function solution(n, k, cmd) {
  let begin = { prev: null, next: null, index: 0 }
  let prevNode = begin;
  let cursor = begin

  const answer = Array(n).fill(true)

  for (let i = 1; i < n; ++i) {
    const node = { prev: prevNode, next: null, index: i }
    if (i === k) cursor = node;
    prevNode.next = node;
    prevNode = node
  }

  const deleteStack = []
  for (const comand of cmd) {
    let [type, number] = comand.split(' ');
    if (type === 'D') {
      while (number--) {
        cursor = cursor.next;
      }
    } else if (type === 'U') {
      while (number--) {
        cursor = cursor.prev;
      }
    } else if (type === 'C') {
      const prev = cursor.prev;
      const next = cursor.next;
      if (prev !== null)
        prev.next = next;
      if (next !== null)
        next.prev = prev;
      deleteStack.push({ prev, next, cursor })
      answer[cursor.index] = false;
      if (next === null) {
        cursor = prev
      } else {
        cursor = next
      }
    } else if (type === 'Z') {
      const top = deleteStack[deleteStack.length - 1];
      deleteStack.pop();
      answer[top.cursor.index] = true;
      if (top.prev !== null)
        top.prev.next = top.cursor;
      if (top.next !== null)
        top.next.prev = top.cursor;
    }
  }

  return answer.map(val => val ? 'O' : 'X').join('')
}