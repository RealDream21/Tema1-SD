import random as r

max_number = 2147483647
n_testcases = 10
print('generating numbers...')

for i in range(n_testcases):
    fileName = "testcase" + str(i)
    f = open(fileName, "w")
    N = r.randint(10**6, 10**7)
    f.write(str(N))
    f.write('\n')
    for _ in range(N):
        f.write(str(r.randint(0, max_number)) + " ")
        if _ % 10 == 0 and _ != 0:
            f.write('\n')
    f.close()
input('generated numbers')