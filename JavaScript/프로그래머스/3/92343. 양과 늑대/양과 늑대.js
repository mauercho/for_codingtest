class Queue {
    items = [];
    rear = 0;
    front = 0;
    
    push(item) {
        this.items.push(item);
        this.rear++;
    }
    
    pop() {
        return this.items[this.front++];
    }
    isEmpty() {
        return this.rear === this.front;
    }
}

function solution(info, edges) {
    var answer = 0;
    const infoLen = info.length
    const graph = [...new Array(infoLen)].map(()=> [])
    for (const edge of edges) {
        graph[edge[0]].push(edge[1]);
    }
    const q = new Queue();
    q.push([0 ,1 , 0, new Set()]);
    while (!q.isEmpty()){
        const [now, lambs, wolfs, visited] = q.pop();
        answer = Math.max(lambs, answer);
        for (const next of graph[now]){
            visited.add(next);
        }
        for (const next of visited){
            if (info[next] === 1){ // 늑대 
                if (lambs > wolfs + 1){
                    const newVisited = new Set(visited);
                    newVisited.delete(next);
                    q.push([next, lambs, wolfs + 1, newVisited]);
                }
            } else {
                const newVisited = new Set(visited);
                newVisited.delete(next);
                q.push([next, lambs + 1, wolfs, newVisited])
            }
        }
    }
    
    return answer;
}