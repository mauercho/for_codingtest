class Node {
  constructor(info, idx, left = null, right = null) {
    this.info = info;
    this.idx = idx;
    this.left = left;
    this.right = right;
  }

  hasLeft() {
    // null이면
    return this.left !== null;
  }

  hasRight() {
    return this.right !== null;
  }
}

function makeBT(nodeinfo) {
  // 여기서 BTree 만든다.

  let array = [...new Array(nodeinfo.length)].map((_, i) => i);
  array.sort((a, b) => {
    const [ax, ay] = nodeinfo[a];
    const [bx, by] = nodeinfo[b];

    //y 는 내림 차순임.
    if (ay < by) {
      return 1;
    } else if (ay === by) {
      // x는 오름 차순
      if (ax < bx) {
        return -1;
      } else {
        return 1;
      }
    } else {
      return -1;
    }
  });
  let root = null;
  for (const mem of array) {
    if (!root) {
      root = new Node(nodeinfo[mem], mem);
    } else {
      let parent = root;
      const newNode = new Node(nodeinfo[mem], mem);
      while (true) {
        if (nodeinfo[mem][0] < parent.info[0]) {
          if (parent.hasLeft()) {
            parent = parent.left;
            continue;
          }
          parent.left = newNode;
          break;
        } else {
          if (parent.hasRight()) {
            parent = parent.right;
            continue;
          }
          parent.right = newNode;
          break;
        }
      }
    }
  }
  return root;
}

function preOrder(root, answer) {
  if (root === null) return;
  answer[0].push(root.idx + 1);
  preOrder(root.left, answer);
  preOrder(root.right, answer);
}

function postOrder(root, answer) {
  if (root === null) return;
  postOrder(root.left, answer);
  postOrder(root.right, answer);
  answer[1].push(root.idx + 1);
}

function solution(nodeinfo) {
  //[[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]]
  let answer = [[], []];

  const root = makeBT(nodeinfo);
  preOrder(root, answer);
  postOrder(root, answer);
  return answer;
}