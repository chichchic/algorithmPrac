function solution(sizes) {
  let width = 0, height = 0;
  for (const [w, h] of sizes) {
    let dif = Math.max(0, w - width) + Math.max(0, h - height);
    let rotateDif = Math.max(0, w - height) + Math.max(0, h - width);
    if (dif < rotateDif) {
      width = Math.max(width, w);
      height = Math.max(height, h);
    } else {
      width = Math.max(width, h);
      height = Math.max(height, w);
    }
  }
  return width * height;
}