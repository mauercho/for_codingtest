function solution(nums) {
    var answer = 0;
    let len = nums.length;
    const st= new Set();
    for (let mem of nums) {
        st.add(mem);
    }
    answer = Math.min(st.size, len / 2);
    return answer;
}