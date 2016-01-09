def solve():
    N, P = map(int, raw_input().split())
    B = map(int, raw_input().split())
    ans = 0
    for i in xrange(N):
        B[i] = B[i] + B[i - 1] if i > 0 else B[i]
    B.insert(0, 0)
    for i in xrange(1, N + 1):
        start = i
        end = N
        while end - start > 1:
            mid = start + (end - start) / 2
            val = B[mid] - B[i - 1]
            if val <= P:
                start = mid
            else:
                end = mid
        if B[start] - B[i - 1] > P:
            continue
        pos = end if B[end] - B[i - 1] <= P else start
        ans += pos - i + 1
    return ans

T = input()
for i in xrange(T):
    ans = solve()
    print "Case #" + str(i + 1) + ": " + str(ans)
