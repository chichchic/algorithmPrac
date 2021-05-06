function calc(result, parent, child, revenue) {
  const cut = Math.floor(revenue / 10);
  result[child] += revenue - cut;
  if (parent[child] === "-") {
    return;
  }
  calc(result, parent, parent[child], cut);
}

function solution(enroll, referral, seller, amount) {
  const result = enroll.reduce((acc, cur) => {
    acc[cur] = 0;
    return acc;
  }, {});
  const parent = enroll.reduce((acc, cur, index) => {
    acc[cur] = referral[index];
    return acc;
  }, {});
  seller.forEach((name, index) => {
    calc(result, parent, name, amount[index] * 100);
  });
  const answer = [];
  for (let name in result) {
    answer.push(result[name]);
  }
  return answer;
}
