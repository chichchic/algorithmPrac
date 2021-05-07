// 정답
function solution(play_time, adv_time, logs) {
  const total = convertSecond(play_time);
  const adSecond = convertSecond(adv_time);
  const ad = Array(total).fill(0);
  for (const log of logs) {
    const [front, back] = log.split("-");
    const start = convertSecond(front);
    const end = convertSecond(back);
    ad[start]++;
    ad[end]--;
  }
  for (let i = 1; i <= total; i++) {
    ad[i] += ad[i - 1];
  }
  for (let i = 1; i <= total; i++) {
    ad[i] += ad[i - 1];
  }
  let sum = ad[adSecond - 1];
  let answerIndex = 0;
  for (let i = adSecond - 1; i < total; i++) {
    if (sum < ad[i] - ad[i - adSecond]) {
      sum = ad[i] - ad[i - adSecond];
      answerIndex = i - adSecond + 1;
    }
  }
  return convertString(answerIndex);
}

// 시간 초과
const Node = {
  constructor: function (value) {
    this.value = value;
    this.next = null;
    return this;
  },
  linkNext: function (nextNode) {
    this.next = nextNode;
  },
};

const Queue = {
  constructor: function () {
    this.front = null;
    this.last = null;
    return this;
  },
  pop: function () {
    const output = this.front.value;
    this.front = this.front.next;
    return output;
  },
  push: function (node) {
    if (this.front === null) {
      this.front = node;
      this.last = node;
    } else {
      this.last.next = node;
      this.last = this.last.next;
    }
  },
};

function convertSecond(time) {
  let cur = 3600;
  return time.split(":").reduce((acc, val) => {
    acc += Number(val) * cur;
    cur /= 60;
    return acc;
  }, 0);
}

function convertString(second) {
  return [3600, 60, 1]
    .reduce((acc, cur) => {
      let str = String(Math.floor(second / cur));
      second %= cur;
      acc += str.length === 1 ? "0" + str + ":" : str + ":";
      return acc;
    }, "")
    .slice(0, 8);
}

function solution(play_time, adv_time, logs) {
  const ad = Array(360001).fill(0);
  for (const log of logs) {
    const [front, back] = log.split("-");
    const start = convertSecond(front);
    const end = convertSecond(back);
    for (let i = start; i < end; ++i) {
      ++ad[i];
    }
  }
  let total = convertSecond(play_time);
  let adSecond = convertSecond(adv_time);

  const queue = Object.create(Queue).constructor();
  let idx = 0;
  let sum = 0;
  let maxSum = 0;

  for (let i = 0; i < adSecond; i++) {
    sum += ad[i];
    const node = Object.create(Node).constructor(ad[i]);
    queue.push(node);
  }
  maxSum = sum;

  for (let i = adSecond; i < total; i++) {
    sum += ad[i];
    const node = Object.create(Node).constructor(ad[i]);
    queue.push(node);
    sum -= queue.pop();
    if (sum > maxSum) {
      idx = i - adSecond + 1;
      maxSum = sum;
    }
  }
  return convertString(idx);
}
