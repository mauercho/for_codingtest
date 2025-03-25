class Node{
    constructor(info, num, left = null, right = null){
        this.info = info; // 노드 정보 (실제 x y 값)
        this.num = num; // 인덱스 넣기
        this.left = left; // 왼쪽 자식
        this.right = right; // 오른쪽 자식
    }
    
    hasLeft() {
        return this.left !== null;
    }
    
    hasRight() {
        return this.right !== null;
    }
}

function makeBT(nodeinfo){
    const arr = [...new Array(nodeinfo.length)].map((_, i) => i);
    arr.sort((a, b) => {
        const [ax, ay] = nodeinfo[a];
        const [bx, by] = nodeinfo[b];
        if (ay < by){
            return 1;
        } else if (ay === by){
            if (ax < bx) {
                return -1;
            } else {
                return 1;
            }
        } else {
            return -1;
        }
    })
    let root = null;
    for (const mem of arr){
        if (!root){
            root = new Node(nodeinfo[mem], mem);
        } else {
            let parent = root;
            const newNode = new Node(nodeinfo[mem], mem);
            while (true){
                if (newNode.info[0] < parent.info[0]) {
                    if (parent.hasLeft()){
                        parent = parent.left;
                        continue;
                    }
                    parent.left = newNode;
                    break;
                } else {
                    if (parent.hasRight()){
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

function preOrder(node, arr){
    arr.push(node.num + 1);
    if (node.hasLeft()){
        preOrder(node.left, arr);
    } 
    if (node.hasRight()){
        preOrder(node.right, arr);
    }
    
    
    return arr;
}

function postOrder(node, arr){
    if (node.hasLeft()){
        postOrder(node.left, arr);
    }
    if (node.hasRight()){
        postOrder(node.right, arr);
    }
    arr.push(node.num + 1);
    
    return arr;
}

function solution(nodeinfo) {
    var answer = [];
    const root = makeBT(nodeinfo)
    let tmp = [];
    preOrder(root, tmp);
    answer.push(tmp);
    tmp = []
    postOrder(root, tmp);
    answer.push(tmp);
    return answer;
}