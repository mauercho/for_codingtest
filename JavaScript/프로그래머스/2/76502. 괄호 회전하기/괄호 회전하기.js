function isVPS(s) {
  const obj = { "}": "{", "]": "[", ")": "(" };
	const stack = []
	for (const alpha of s){
		if (alpha === '{' || alpha === '[' || alpha === '('){
			stack.push(alpha);
		} else {
			if (stack.length === 0) return false;
			if (stack[stack.length - 1] !== obj[alpha]) return false;
			stack.pop();
		}
	}
	return !stack.length;
}
function solution(s) {
  var answer = 0;
  len = s.length;
  s += s;
  for (let i = 0; i < len; i++) {
    if (isVPS(s.slice(i, i + len))) answer += 1;
  }
  return answer;
}