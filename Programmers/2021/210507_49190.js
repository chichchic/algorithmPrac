function solution(arrows) {
  const checkEdge = new Set();
  const checkNode = new Set();
  const mx = [0, 1, 1, 1, 0, -1, -1, -1];
  const my = [-1, -1, 0, 1, 1, 1, 0, -1];

  function move(x, y, direction) {
    const nextX = x + mx[direction] * 2;
    const nextY = y + my[direction] * 2;
    if (x === nextX) {
      if (y > nextY) {
        return `${x}/${y}-${nextX}/${nextY}`;
      } else {
        return `${nextX}/${nextY}-${x}/${y}`;
      }
    } else {
      if (x > nextX) {
        return `${x}/${y}-${nextX}/${nextY}`;
      } else {
        return `${nextX}/${nextY}-${x}/${y}`;
      }
    }
  }
  let currentX = 0;
  let currentY = 0;
  let answer = 0;
  checkNode.add("0/0");
  for (const direction of arrows) {
    const nextEdge = move(currentX, currentY, direction);
    const middleX = currentX + mx[direction];
    const middleY = currentY + my[direction];
    currentX += mx[direction] * 2;
    currentY += my[direction] * 2;
    const middleNode = `${middleX}/${middleY}`;
    const nextNode = `${currentX}/${currentY}`;
    if (!checkEdge.has(nextEdge)) {
      if (checkNode.has(nextNode)) {
        ++answer;
      }
      if (checkNode.has(middleNode)) {
        ++answer;
      }
    }
    checkNode.add(nextNode);
    checkNode.add(middleNode);
    checkEdge.add(nextEdge);
  }
  return answer;
}
