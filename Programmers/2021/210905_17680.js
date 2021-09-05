function solution(cacheSize, cities) {
  let cache = [];
  return cities.reduce((acc, cur) => {
    cur = cur.toLowerCase()
    let output = acc;
    cache = cache.slice(-cacheSize)
    const idx = cache.findIndex(val => val === cur);
    if (idx !== -1) {
      cache.splice(idx, 1)
      output += 1;
    } else {
      if (cache.length >= cacheSize) {
        cache.splice(0, 1)
      }
      output += 5;
    }
    cache.push(cur);
    return output;
  }, 0);
}