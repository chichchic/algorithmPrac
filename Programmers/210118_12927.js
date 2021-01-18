class Heap {
  constructor() {
    this.arr = new Array();
  }

  pop() {
    const output = this.arr[0];
    this.arr[0] = this.arr[this.arr.length - 1];
    this.arr.pop();
    let cur = 0;
    while (true) {
      let c1 = cur * 2 + 1;
      let c2 = cur * 2 + 2;
      let child;
      if (this.arr.length <= c1) {
        break;
      } else if (this.arr.length <= c2) {
        child = c1;
      } else {
        child = this.arr[c1] > this.arr[c2] ? c1 : c2;
      }
      if (this.arr[child] > this.arr[cur]) {
        let temp = this.arr[child];
        this.arr[child] = this.arr[cur];
        this.arr[cur] = temp;
        cur = child;
      } else {
        break;
      }
    }
    return output;
  }

  push(input) {
    this.arr.push(input);
    let cur = this.arr.length - 1;

    while (cur > 0) {
      let parent = Math.floor((cur - 1) / 2);
      const curVal = this.arr[cur];
      const pVal = this.arr[parent];
      if (curVal > pVal) {
        this.arr[cur] = pVal;
        this.arr[parent] = curVal;
        cur = parent;
      } else {
        break;
      }
    }
  }
}

function solution(n, works) {
  const heap = new Heap();
  let total = 0;
  works.forEach((val) => {
    heap.push(val);
    total += val;
  });
  if (total <= n) return 0;
  while (n > 0) {
    n--;
    heap.push(heap.pop() - 1);
  }
  return heap.arr.reduce((acc, cur) => acc + cur * cur, 0);
}
