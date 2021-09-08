class Heap {
  constructor(compareFunc) {
    this.arr = new Map()
    this.compareFunc = compareFunc
  }

  size() {
    return this.arr.size;
  }

  pop() {
    const output = this.arr.get(0);
    this.arr.set(0, this.arr.get(this.arr.size - 1));
    this.arr.delete(this.arr.size - 1);
    let cur = 0;
    while (true) {
      let c1 = cur * 2 + 1;
      let c2 = cur * 2 + 2;
      let child;
      if (this.arr.size <= c1) {
        break;
      } else if (this.arr.size <= c2) {
        child = c1;
      } else {
        child = this.compareFunc(this.arr.get(c1), this.arr.get(c2)) ? c1 : c2;
      }
      if (this.compareFunc(this.arr.get(child), this.arr.get(cur))) {
        let temp = this.arr.get(child);
        this.arr.set(child, this.arr.get(cur));
        this.arr.set(cur, temp);
        cur = child;
      } else {
        break;
      }
    }
    return output;
  }

  push(input) {
    this.arr.set(this.arr.size, input);
    let cur = this.arr.size - 1;

    while (cur > 0) {
      let parent = Math.floor((cur - 1) / 2);
      const curVal = this.arr.get(cur)
      const pVal = this.arr.get(parent)
      if (this.compareFunc(curVal, pVal)) {
        this.arr.set(cur, pVal)
        this.arr.set(parent, curVal)
        cur = parent;
      } else {
        break;
      }
    }
  }
}

function solution(n, start, end, roads, traps) {
  const isTrap = Array(n + 1).fill(-1);
  for (const idx in traps) {
    isTrap[traps[idx]] = idx;
  }
  const roadMap = Array.from(({ length: n + 1 }), () => [])
  for (const [s, e, w] of roads) {
    roadMap[s].push({ e, w, roadType: 0 });
    roadMap[e].push({ e: s, w, roadType: 1 });
  }
  const visited = Array.from(({ length: n + 1 }), () => Array(1 << (traps.length + 1)).fill(false))
  const pq = new Heap((a, b) => a.weight < b.weight);
  pq.push({ cur: start, state: 0, weight: 0 });
  while (pq.size() > 0) {
    const { cur, state, weight } = pq.pop();
    visited[cur][state] = true;
    if (cur === end) {
      return weight;
    }
    let curType = 0;
    if (isTrap[cur] !== -1 && (state & (1 << isTrap[cur]))) {
      curType = 1;
    }
    for (let i = 0; i < roadMap[cur].length; ++i) {
      const { e, w, roadType } = roadMap[cur][i];
      let nextType = 0;
      let nextState = state;
      if (isTrap[e] !== -1) {
        nextState = state ^ (1 << isTrap[e]);
        nextType = (state & (1 << isTrap[e])) ? 1 : 0;
      }
      if ((curType ^ nextType) != roadType) continue;
      if (visited[e][nextState]) continue;
      pq.push({ cur: e, state: nextState, weight: weight + w })
    }
  }
}