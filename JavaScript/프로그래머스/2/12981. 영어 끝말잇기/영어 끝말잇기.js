function solution(n, words) {
    var answer = [0, 0];
    let turn = 0;
    let person;
    const newObj = {};
    let lastWord = " ";
    for (let [i, word] of words.entries()){
        if (i % n === 0) turn += 1;
        if (lastWord !== " "){
            if (newObj[word] === 1 || lastWord !== word[0]){
                person = (i % n) + 1;
                break;
            }
        }
        
        lastWord = word[word.length - 1];
        newObj[word] = 1;
    }
    if (person === undefined) return answer;
    answer = [person, turn]
    return answer;
}