function solution(s) {
    var answer = new Set();
    const array = s.slice(2, -2).split("},{")
    array.sort((a, b) => {
        if (a.length < b.length) return -1;
        else return 1;
    })
    for (const member of array){
        const arr = member.split(',');
        for (const temp of arr){
            if (!answer.has(parseInt(temp))){
                answer.add(parseInt(temp))
            }
        }
    }
    
    return [...answer];
}