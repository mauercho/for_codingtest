class MinHeap {
    constructor() {
        this.items = [];
    }
    size() {
        return this.items.length;
    }
    push(item){
        this.items.push(item);
        this.bubbleUp();
    }
    pop() {
        if (this.size() === 0){
            return null;
        }
        
        const min = this.items[0];
        this.items[0] = this.items[this.size() - 1];
        this.items.pop();
        this.bubbleDown();
        return min;
    }
    
    swap(a, b){
        [this.items[a], this.items[b]] = [this.items[b], this.items[a]]
    }
    
    bubbleUp(){
        let index = this.size() - 1;
        while (index > 0){
            const parentIndex = Math.floor((index - 1) / 2);
            if (this.items[parentIndex][0] <= this.items[index][0]){
                break;
            }
            this.swap(index, parentIndex);
            index = parentIndex;
        }
    }
    
    bubbleDown() {
        let index = 0;
        while (index * 2 + 1 < this.size()) {
            let leftChild = index * 2 + 1;
            let rightChild = index * 2 + 2;
            let smallerChild = rightChild < this.size() && 
                this.items[rightChild][0] < this.items[leftChild][0] ? rightChild : leftChild;
            if (this.items[index][0] <= this.items[smallerChild][0]) {
                break;
            }
            this.swap(index, smallerChild);
            index = smallerChild;
        }
    }
}


function solution(land, height) {
    var answer = 0;
    const q = new MinHeap();
    const di = [0, 1, -1, 0];
    const dj = [1, 0, 0, -1];
    q.push([0, 0, 0]);
    const n = land.length;
    const visited = [...new Array(n)].map(()=> Array(n).fill(false))
    while (q.size() !== 0){
        const [cost, i, j] = q.pop();
        
        if (visited[i][j]) continue;
        visited[i][j] = true;
        answer += cost;
        for (let k = 0; k < 4; k++){
            const ni = i + di[k];
            const nj = j + dj[k];
            
            if (0 <= ni && ni < n && 0 <= nj && nj < n){
                const temp = Math.abs(land[ni][nj] - land[i][j]);
                const addtemp = temp > height ? temp : 0;
                q.push([addtemp, ni, nj])
            }
        }
    }
    return answer;
}
