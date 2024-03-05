def pls_check(N, arr):
    is_pls = False
    pls_cnt = 1
    cnt = 0
    for i in range(N-1):
        if is_pls == False:
            if arr[i] <= arr[i+1]:
                pls_cnt = 2     # pls_cnt 갱신
                is_pls = True
            else:
                pls_cnt = 1    # pls_cnt 갱신
        elif is_pls == True:
            if arr[i] <= arr[i+1]:
                pls_cnt += 1
            else:
                pls_cnt = 1    # pls_cnt 갱신
        cnt = max(cnt, pls_cnt)
    return cnt

def mns_check(N, arr):
    is_mns = False
    mns_cnt = 1
    cnt = 0
    for i in range(N - 1):
        if is_mns == False:
            if arr[i] >= arr[i + 1]:
                mns_cnt = 2  # mns_cnt 갱신
                is_mns = True
            else:
                mns_cnt = 1  # mns_cnt 갱신
        elif is_mns == True:
            if arr[i] >= arr[i + 1]:
                mns_cnt += 1
            else:
                mns_cnt = 1  # mns_cnt 갱신
        cnt = max(cnt, mns_cnt)
    return cnt

# for _ in range(3):
N = int(input())    # 입력받는 숫자의 개수
arr = list(map(int, input().split()))   # 입력받는 숫자 배열
if len(arr) == 1:
    print(1)
else:
    print(max(pls_check(N, arr), mns_check(N, arr)))