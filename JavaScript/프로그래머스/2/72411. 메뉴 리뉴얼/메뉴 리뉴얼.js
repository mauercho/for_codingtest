function combi(start, depth, end, str, obj, order) {
    if (depth == end){
        const newStr = str.split("").sort().join("");
        if (obj[newStr]){
            obj[newStr] += 1;
        } else {
            obj[newStr] = 1;
        }
        return ;
    }
    for (let i = start + 1; i < order.length; i++){
        combi(i, depth + 1, end, str + order[i], obj, order);
    }
}

function makeObj(orders, num){
    const obj = {};

    for (const order of orders){
        if (order.length >= num){
            combi(-1, 0, num, "", obj, order)
        }
    }
    return obj;
}

function solution(orders, course) {
    var answer = [];
    const obj = {};
    for (let mem of course){
        obj[mem] = makeObj(orders, mem);
        const newArray = Object.entries(obj[mem]).sort(([key, value], [key1, value1]) => value1- value);
        if (newArray.length > 0){
            const max_val = newArray[0][1];
            if (max_val > 1){
                for (const arr of newArray){
                    if (arr[1] == max_val){
                        answer.push(arr[0]);
                    } else {
                        break ;
                    }
                }
            }
        }
    }
    return answer.sort();
}