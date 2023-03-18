import random as r
import threading

max_number = 2147483647
min_sizeof_vector = 10**7
max_sizeof_vector = 10**7
n_testcases = 20

def trulyRandomTests(start, end):
    global n_testcases
    global max_number
    for i in range(start, end):
        fileName = "testcase" + str(i)
        f = open(fileName, "w")
        N = r.randint(min_sizeof_vector, max_sizeof_vector)
        f.write(str(N))
        f.write('\n')
        for _ in range(N):
            f.write(str(r.randint(0, max_number)) + " ")
            if _ % 10 == 0 and _ != 0:
                f.write('\n')
        f.close()

def closeNumbersTests(start, end):
    global n_testcases
    global max_number
    for i in range(start, end):
        fileName = "testcase" + str(i)
        f = open(fileName, "w")
        N = r.randint(min_sizeof_vector, max_sizeof_vector)
        f.write(str(N))
        f.write('\n')
        j = 0
        while j < N:
            j += 1
            if j == N:
                f.close()
                break
            nr = r.randint(0, max_number)
            f.write(str(nr) + " ")
            close_numbers = r.randint(1, 1000)
            for _ in range(close_numbers):
                f.write(str(nr + r.randint(1,100)) + " ")
                j += 1
                if j == N:
                    f.close()
                    break
        f.close()

def repeatingNumbersTests(start, end):
    global n_testcases
    global max_number
    for i in range(start, end):
        fileName = "testcase" + str(i)
        f = open(fileName, "w")
        N = r.randint(min_sizeof_vector, max_sizeof_vector)
        f.write(str(N))
        f.write('\n')
        j = 0
        while j  < N:
            nr = r.randint(0, N)
            repeat = r.randint(0, max_number)
            for _ in range(nr):
                f.write(str(repeat) + " ")
                j += 1
                if j == N:
                    f.close()
                    break

print("Pick test type")
print("1: Truly random numbers")
print("2: Close numbers")
print("3: Repeating numbers")
x = 2
print('generating numbers...')
if x == 1:
    t1 = threading.Thread(target = trulyRandomTests, args = (0, 5))
    t2 = threading.Thread(target = trulyRandomTests, args = (5, 10))
    t3 = threading.Thread(target = trulyRandomTests, args = (10, 15))
    t4 = threading.Thread(target = trulyRandomTests, args = (15, n_testcases))
    t1.start()
    t2.start()
    t3.start()
    t4.start()
    t1.join()
    t2.join()
    t3.join()
    t4.join()
elif x == 2:
    t1 = threading.Thread(target = closeNumbersTests, args = (0, 5))
    t2 = threading.Thread(target = closeNumbersTests, args = (5, 10))
    t3 = threading.Thread(target = closeNumbersTests, args = (10, 15))
    t4 = threading.Thread(target = closeNumbersTests, args = (15, n_testcases))
    t1.start()
    t2.start()
    t3.start()
    t4.start()
    t1.join()
    t2.join()
    t3.join()
    t4.join()
elif x == 3:
    t1 = threading.Thread(target = repeatingNumbersTests, args = (0, 5))
    t2 = threading.Thread(target = repeatingNumbersTests, args = (5, 10))
    t3 = threading.Thread(target = repeatingNumbersTests, args = (10, 15))
    t4 = threading.Thread(target = repeatingNumbersTests, args = (15, n_testcases))
    t1.start()
    t2.start()
    t3.start()
    t4.start()
    t1.join()
    t2.join()
    t3.join()
    t4.join()
input('generated numbers')
