function solution(numbers) {
    var answer = '';
    numbers.sort((a, b) => {
        let stringA = String(a) + String(b);
        let stringB = String(b) + String(a);
        if (stringA >= stringB) return -1;
        else return 1;
    })
    
    answer = numbers.join("");
    
    if (answer[0] === "0") return "0";
    
    return answer;
}