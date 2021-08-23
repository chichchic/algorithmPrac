function solution(table, languages, preference) {
  var answer = '';
  const lang_score = languages.reduce((acc, cur, idx) => {
    acc[cur] = preference[idx]
    return acc
  }, {})
  return table
    .map((info_str) => {
      const [type, ...lang] = info_str.split(' ')
      return [type, lang.reduce((acc, cur, idx) => {
        const score = lang_score[cur] || 0
        return acc + score * (5 - idx)
      }, 0)]
    })
    .sort((a, b) => {
      if (a[1] === b[1]) return a[0] < b[0] ? -1 : 1
      return b[1] - a[1]
    })[0][0]
}