def main2():
    D = input()
    p = map(int, raw_input().split())
    ans = 1234567
    for i in range(1, 1001):
        tot = 0
        for e in p:
            tot += int((e - 1) / i)
        ans = min(ans, tot + i)
    print int(ans)

for i in xrange(input()):
    print "Case #" + str(i + 1) + ": ",
    main2()
