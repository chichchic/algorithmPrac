function canCapture(camera, route) {
  for (const cam of camera) {
    if (cam[0] > route[1] || cam[1] < route[0]) continue;
    const polls = [...cam, ...route];
    polls.sort((a, b) => a - b);
    cam[0] = polls[1];
    cam[1] = polls[2];
    return;
  }
  camera.push(route);
  return;
}

function solution(routes) {
  var camera = [];
  routes.sort((a, b) => a[0] - b[0]);
  routes.forEach((route) => {
    canCapture(camera, route);
  });
  return camera.length;
}
