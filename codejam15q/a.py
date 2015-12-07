#!/usr/bin/env python
# coding=utf-8


def solve(N, S):
    N = int(N)
    ans = 0
    i = 1
    cur = int(S[0])
    for i in xrange(1, N + 1):
        tmp = int(S[i])
        if i > cur:
            ans += i - cur
            cur += i - cur
        cur += tmp
    return ans

T = input()
for i in xrange(T):
    N, S = raw_input().split(' ')
    print "Case #" + str(i + 1) + ": " + str(solve(N, S))
