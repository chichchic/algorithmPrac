function solution(record) {
  const actions = record.map(val => val.split(' '))
  const id2name = actions.reduce((acc, [action, id, name]) => {
      if(action !== 'Leave') {
          acc[id] = name
      }
      return acc
  }, {});

  return actions.reduce((acc, [action, id]) => {
      if(action !== 'Change') {
          const actionMsg = action === 'Enter' ? '들어왔습니다.' : '나갔습니다.';
          acc.push(`${id2name[id]}님이 ${actionMsg}`);
      }
      return acc;
  }, []);
}