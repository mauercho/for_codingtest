function findParent(parent, a){
    if (parent[a] != a)
        parent[a] = findParent(parent, parent[a]);
    return parent[a]
}

function getUnion(parent, a, b){
    let c = findParent(parent ,a);
    let d = findParent(parent, b);
    
    if (c < d){
        parent[d] = c;
    } else {
        parent[c] = d;
    }
}

function solution(n, costs) {
    var answer = 0;
    costs.sort((a, b) => a[2] - b[2]);
    const parent = [...new Array(n)].map((_, i) => i);
    for (let cost of costs){
        if (findParent(parent, cost[1]) !== findParent(parent, cost[0])){
            answer += cost[2];
            getUnion(parent, cost[0], cost[1]);
        }
    }
    return answer;
}