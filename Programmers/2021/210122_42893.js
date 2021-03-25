function getUrl(page) {
  const metaPre = '<meta property="og:url" content="';
  const urlIdx = page.indexOf(metaPre) + metaPre.length;
  const urlLen = page.slice(urlIdx).indexOf('"/>');
  return page.slice(urlIdx, urlIdx + urlLen);
}

function getOutUrl(tag) {
  const urlStartIdx = tag.indexOf('href="') + 6;
  const urlEndIdx = tag.indexOf('">');
  return tag.slice(urlStartIdx, urlEndIdx);
}

function isAlpha(c) {
  const regx = /[A-Za-z]/;
  return regx.test(c);
}

function solution(word, pages) {
  const pageInfo = {};
  const pagesUrl = [];
  pages.forEach((val) => {
    const url = getUrl(val);
    pagesUrl.push(url);
    pageInfo[url] = {
      bagicValue: 0,
      linkUrl: [],
      linkValue: 0,
    };
  });
  const wordLen = word.length;

  pages.forEach((val, idx) => {
    const bodyStartIdx = val.indexOf("<body>") + 5;
    const bodyEndIdx = val.indexOf("</body>");
    let findWord = true;
    let j = 0;
    const curUrl = pagesUrl[idx];
    for (let i = bodyStartIdx; i < bodyEndIdx; i++) {
      if (val[i] === "<" && val[i + 1] === "a") {
        const tag = val.slice(i);
        const tagEnd = tag.indexOf("</a>") + 3;
        const outUrl = getOutUrl(tag);
        pageInfo[curUrl].linkUrl.push(outUrl);
        i += tagEnd;
        findWord = true;
        j = 0;
        continue;
      }

      if (!isAlpha(val[i])) {
        if (j === wordLen && findWord) {
          pageInfo[curUrl].bagicValue++;
        }
        findWord = true;
        j = 0;
        continue;
      }
      if (
        findWord &&
        j < wordLen &&
        val[i].toLowerCase() === word[j].toLowerCase()
      ) {
        j++;
      } else {
        findWord = false;
      }
    }
  });
  pagesUrl.forEach((val) => {
    const linkval = pageInfo[val].bagicValue / pageInfo[val].linkUrl.length;
    pageInfo[val].linkUrl.forEach((link) => {
      if (pageInfo[link]) {
        pageInfo[link].linkValue += linkval;
      }
    });
  });
  let max = -1;
  let answer = -1;
  pagesUrl.forEach((val, idx) => {
    const total = pageInfo[val].bagicValue + pageInfo[val].linkValue;
    if (total > max) {
      max = total;
      answer = idx;
    }
  });
  return answer;
}
