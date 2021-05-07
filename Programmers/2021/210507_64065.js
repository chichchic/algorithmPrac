function solution(s) {
  const check = new Set();
  return s
    .split(/[{|}]+/)
    .filter((val) => val !== "" && val !== ",")
    .map((val) => {
      return val.split(",").map((v) => Number(v));
    })
    .sort((a, b) => a.length - b.length)
    .reduce((acc, cur) => {
      const newNumber = cur.filter((val) => !acc.includes(val))[0];
      acc.push(newNumber);
      return acc;
    }, []);
}
