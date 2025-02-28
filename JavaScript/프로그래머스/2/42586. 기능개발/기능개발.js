class Queue{
    items = [];
    front = 0;
    rear = 0;
    size() {
        return (this.rear - this.front);
    }
    push(item){
        this.items.push(item);
        this.rear++;
    }
    getFront() {
        return this.items[this.front]
    }
    back(){
        return this.items[this.rear - 1];
    }
    upgrade() {
        this.items = [];
        this.front = 0;
        this.rear = 0;
    }
    isEmpty() {
        return this.front === this.rear;
    }
}

function solution(progresses, speeds) {
    var answer = [];
    const queue = new Queue();
    for (const [key, progress] of progresses.entries()){
        let calc = Math.ceil((100 - progress) / speeds[key]);
        if (queue.isEmpty()){
            queue.push(calc);
        } else {
            if (queue.getFront() >= calc){
                queue.push(calc);
            } else {
                answer.push(queue.size());
                queue.upgrade();
                queue.push(calc);
            }
        }
    }
    if (!queue.isEmpty()){
        answer.push(queue.size())
    }
    return answer;
}