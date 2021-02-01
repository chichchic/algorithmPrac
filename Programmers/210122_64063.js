function solution(k, room_number) {
  var answer = [];
  const map = new Map();

  function nextRoom(val) {
    const cur = map.has(val) ? nextRoom(map.get(val)) : val + 1;
    map.set(val, cur);
    return map.get(val);
  }
  room_number.forEach((val) => {
    answer.push(nextRoom(val) - 1);
  });
  return answer;
}
