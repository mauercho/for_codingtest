function solution(s)
{
    var answer = 0;
    const stack = [];
    for (const alpha of s){
        if (stack.length === 0) {
            stack.push(alpha);
            continue;
        }
        if (stack[stack.length - 1] === alpha) stack.pop();
        else {
            stack.push(alpha);
        }
    }
    if (stack.length) answer = 0;
    else answer = 1;
    return answer;
}