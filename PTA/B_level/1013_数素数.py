import math

def sievePrime( n ):
    """ Implement the seive og Eratosthenes
    param:  n (int)
    retype: list(int)
    """
    A = [ i for i in range(n+1)]
    num = int( math.sqrt(n) )
    for p in range(2, num+1):
        if A[p] != 0: # p hasn't been eliminated on previous passes            
            j = p * p
            while j <= n: # p*p <= n
                A[j] = 0 # mark element as eliminated
                j = j + p # 不断剔除p的倍数
    L = [ item for item in A if item >= 2 ]
    return L

def get_primes( N ):
    primes = []
    num = 70000 # 开始时计算num以内的素数
    step = 10000
    while len(primes) < N:
        num += step
        primes = sievePrime( num )
    # print("Got it!")
    return primes

# input two nums M and N    
nums = input()
M, N = [ int(n) for n in nums.split(' ') ] 
# print("M={0}, N={1}".format(M, N))
primes = get_primes( N )
# print("length of primes is", len(primes))
# print("Pm={0}, Pn={1}".format(primes[M-1], primes[N-1]))

round = 10
cnt = 0
for i in range( M-1, N):
    cnt += 1
    print(primes[i], end="")
    # at the end 
    if cnt == ( N - M + 1 ):
        break
    elif (cnt % round) != 0:
        print(" ", end="")
    else:
        print("")