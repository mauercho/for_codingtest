class Queue {
    items = [];
    rear = 0;
    front = 0;
    
    push(item){
        this.items.push(item);
        this.rear++;
    }
    pop(){
        return this.items[this.front++];
    }
    isEmpty(){
        return this.rear === this.front;
    }
}

function isValid(i, j, n, m, visited){
    return 0 <= i && i < n && 0 <= j && j < m && (visited[i][j] === -1);
}

function bfs(sI, sJ, eI, eJ, visited, maps, n, m){
    visited[sI][sJ] = 0;
    const q = new Queue();
    q.push([sI, sJ]);
    const di = [1, -1, 0, 0];
    const dj = [0, 0, 1, -1];
    while (!q.isEmpty()){
        const [i, j] = q.pop();
        if (i === eI && j === eJ) return visited[i][j];
        for (let k = 0; k < 4; k++){
            let ni = i + di[k];
            let nj = j + dj[k];
            if (!(isValid(ni, nj, n, m, visited))) continue;
            if (maps[ni][nj] === 'X') continue;
            q.push([ni, nj]);
            visited[ni][nj] = visited[i][j] + 1;
        }
    }
    return -1;
}

function solution(maps) {
    var answer = 0;
    const n = maps.length;
    const m = maps[0].length;
    let startI, startJ, leverI, leverJ, endI, endJ;
    
    const visitedLever = [...new Array(n)].map(() => new Array(m).fill(-1))
    const visitedEnd = [...new Array(n)].map(() => new Array(m).fill(-1))
    for (let i = 0; i < n; i++){
        for (let j = 0; j < m; j++){
            if (maps[i][j] === 'S'){
                startI = i;
                startJ = j;
            } else if (maps[i][j] === 'L'){
                leverI = i;
                leverJ = j;
            } else if (maps[i][j] === 'E'){
                endI = i;
                endJ = j;
            }
        }
    }
    let temp;
    temp = bfs(startI, startJ, leverI, leverJ, visitedLever, maps, n, m);
    if (temp === -1) return -1;
    answer += temp;
    temp = bfs(leverI, leverJ, endI, endJ, visitedEnd, maps, n, m);
    if (temp === -1) return -1;
    answer += temp;
    return answer;
}