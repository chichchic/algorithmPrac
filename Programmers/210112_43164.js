function findRoute(routes, path, curCnt, totalCnt, tickets, ticketCheck) {
  if (curCnt === totalCnt) {
    return true;
  }
  const cur = path[path.length - 1];
  if (!routes[cur]) return;
  for (const idx of routes[cur]) {
    if (ticketCheck[idx]) continue;
    ticketCheck[idx] = true;
    curCnt++;
    path.push(tickets[idx][1]);
    const result = findRoute(
      routes,
      path,
      curCnt,
      totalCnt,
      tickets,
      ticketCheck
    );
    if (result) return true;
    ticketCheck[idx] = false;
    curCnt--;
    path.pop();
  }
}

function solution(tickets) {
  var answer = [];
  const totalCnt = tickets.length;
  const routes = {};
  tickets.sort((a, b) => {
    if (a[1] > b[1]) {
      return 1;
    } else {
      return -1;
    }
  });
  const ticketCheck = Array(totalCnt).fill(false);
  tickets.forEach(([v1, v2], index) => {
    if (!routes[v1]) routes[v1] = [];
    routes[v1].push(index);
  });
  const path = ["ICN"];
  findRoute(routes, path, 0, totalCnt, tickets, ticketCheck);
  return path;
}
