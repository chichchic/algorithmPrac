function solution(food_times, k) {
  const foods = food_times
    .map((time, id) => ({ time, id: id + 1 }))
    .sort((a, b) => a.time - b.time);
  let eatAll = 0;
  for (let i = 0; i < foods.length; i++) {
    const foodCount = foods.length - i;
    const food = foods[i];
    const eatAmount = foodCount * (food.time - eatAll);
    if (eatAmount <= k) {
      k -= eatAmount;
      eatAll = food.time;
    } else {
      const foodIdx = k === 0 ? 0 : k % foodCount;
      const sorted = foods.slice(i).sort((a, b) => a.id - b.id);
      return sorted[foodIdx].id;
    }
  }
  return -1;
}
