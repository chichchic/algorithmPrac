class Tree {
  constructor(val) {
    this.right = false;
    this.left = false;
    this.val = val;
  }
  rightPush(val) {
    this.right = new Tree(val);
  }
  leftPush(val) {
    this.left = new Tree(val);
  }
}

function solution(nodeinfo) {
  const len = nodeinfo.length;
  let tree = false;
  const pre = [];
  const post = [];
  function push([newX, newY, newIdx]) {
    if (!tree) {
      tree = new Tree([newX, newIdx]);
      return;
    }
    let curTree = tree;
    while (true) {
      const [curX, curIdx] = curTree.val;
      if (newX < curX) {
        if (!curTree.left) {
          curTree.leftPush([newX, newIdx]);
          curTree = curTree.left;
          break;
        }
        curTree = curTree.left;
      } else {
        if (!curTree.right) {
          curTree.rightPush([newX, newIdx]);
          curTree = curTree.right;
          break;
        } else curTree = curTree.right;
      }
    }
  }
  function preorder(curTree) {
    pre.push(curTree.val[1]);
    if (curTree.left) {
      preorder(curTree.left);
    }
    if (curTree.right) {
      preorder(curTree.right);
    }
  }
  function postorder(curTree) {
    if (curTree.left) {
      postorder(curTree.left);
    }
    if (curTree.right) {
      postorder(curTree.right);
    }
    post.push(curTree.val[1]);
  }
  nodeinfo = nodeinfo.map((val, idx) => [...val, idx + 1]);
  nodeinfo.sort((a, b) => b[1] - a[1]);
  nodeinfo.forEach((val) => push(val));
  preorder(tree);
  postorder(tree);
  return [pre, post];
}
