class Trie {
  constructor() {
    this.child = {};
    this.cnt = 0;
  }

  push(str) {
    let cur = this;
    let idx = 0;
    while (str.length > idx) {
      cur.cnt++;
      const curChar = str[idx].charCodeAt() - 97;
      if (!cur.child[curChar]) {
        cur.child[curChar] = new Trie();
      }
      cur = cur.child[curChar];
      idx++;
    }
  }

  find(str) {
    let cur = this;
    let idx = 0;
    while (true) {
      if (str[idx] === "?") {
        return cur.cnt;
      }
      const curChar = str[idx].charCodeAt() - 97;
      if (!cur.child[curChar]) {
        return 0;
      }
      cur = cur.child[curChar];
      idx++;
    }
  }
}

function solution(words, queries) {
  var answer = [];
  const trie = Array.from(Array(10001), () => new Trie());
  const revTrie = Array.from(Array(10001), () => new Trie());
  words.forEach((val) => {
    const valLen = val.length;
    trie[valLen].push(val);
    revTrie[valLen].push([...val].reverse());
  });
  queries.forEach((val, idx) => {
    const valLen = val.length;
    if (val[0] === "?") {
      answer.push(revTrie[valLen].find([...val].reverse()));
    } else {
      answer.push(trie[valLen].find(val));
    }
  });
  return answer;
}
