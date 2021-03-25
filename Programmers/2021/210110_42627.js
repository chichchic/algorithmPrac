class Heap {
  constructor() {
    this._memory = [];
    this._idx = 0;
  }

  push(a) {
    const idx = this._memory.findIndex(
      (val, index) => this._idx <= index && val[1] > a[1]
    );
    if (this._memory.length === 0 || idx === -1) {
      this._memory.push(a);
    } else {
      this._memory.splice(idx, 0, a);
    }
    return a;
  }

  pop() {
    return this._memory[this._idx++];
  }

  empty() {
    return this._idx >= this._memory.length;
  }
}

function process(reqTime, curTime, spendTime) {
  return curTime - reqTime + spendTime;
}

function solution(jobs) {
  var answer = 0;
  const schedule = new Heap();
  const len = jobs.length;
  jobs.sort((a, b) => {
    if (a[0] === b[0]) return a[1] - b[1];
    return a[0] - b[0];
  });
  let jobIdx = 0;
  while (jobIdx < len) {
    let curTime = jobs[jobIdx][0];
    schedule.push(jobs[jobIdx++]);
    while (!schedule.empty()) {
      const [reqTime, spendTime] = schedule.pop();
      answer += process(reqTime, curTime, spendTime);
      curTime += spendTime;
      while (jobIdx < len && curTime >= jobs[jobIdx][0]) {
        schedule.push(jobs[jobIdx++]);
      }
    }
  }
  return (answer / len) >> 0;
}
