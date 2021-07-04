class Trie {
  constructor() {
      this.terminal = false;
      this.childCount = 0;
      this.children = new Array(26).fill(null);
  }
  insert(str) {
      let cursor = this;
      let idx = 0;
      while(str.length >= idx) {
          if(str.length === idx) {
              cursor.terminal = true;
              break;
          }
          const alphaIdx = str.charCodeAt(idx) - 'a'.charCodeAt(0);
          if(cursor.children[alphaIdx] === null) {
              cursor.children[alphaIdx] = new Trie();
          }
          cursor = cursor.children[alphaIdx]
          ++cursor.childCount;
          ++idx;
      }




  }
  find(str) {
      let cursor = this
      let idx = 0;
      while(str.length >= idx){
          if(str.length === idx || cursor.childCount === 1) {
              break;
          }
          const alphaIdx = str.charCodeAt(idx) - 'a'.charCodeAt(0);
          cursor = cursor.children[alphaIdx];
          idx++;
      }
      return idx;
  }
}

function solution(words) {
  const trie = new Trie();
  words.forEach(str => trie.insert(str));
  return words.reduce((acc, str) => {
      const depth = trie.find(str, 0)
      return acc + depth;
  }, 0)
}

/*
//더 쉬운 방법
function solution(words) {

    words.sort((a, b) => a < b ? -1 : a > b ? 1 : 0);
    console.log(words)

    let r = 0, a, b, c;

    words.forEach((w, i) => {
        const right = words[i + 1] || words[i - 1];
        const left = words[i - 1] || words[i + 1];

        for (let i = 1, l = w.length; i <= l; i++) {
            r++;
            a = w.substring(0, i);
            if (a != left.substring(0, i) && a != right.substring(0, i))
                return;
        }
    });
    return r;
}