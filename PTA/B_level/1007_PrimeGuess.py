# 素数对 
import math

def isPrime( N ):
	""" judge whether N is a prime number
    param:  N (int)
    retype: bool
    """
	if N <= 1:
		return False
	else:
		flag = True
		for  i in range(2, N):
			if (N % i) == 0:
				flag = False
				break
		return flag
        
def isPrimeSqrt( N ):
    if N <= 1:
        return False
    else:
        flag = True
        num = int( math.sqrt(N) )
        for  i in range(2, num+1):
            if (N % i) == 0:
                flag = False
                break
        return flag

def generatePrime( N ):
    prime = [ i for i in range(1,N+1) if isPrime(i) ]
    return prime
    
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
                j = j + p # 剔除p的倍数
    L = [ item for item in A if item >= 2 ]
    return L

def seive( N ):
    if N < 2:
        return []
    else:
        L = [ i for i in range(2, N+1) ]
        for i in range(2, len(L)):
            L = list( filter( lambda x: (x%i != 0) or x == i , L) ) 
        return L
        
N = int( input() )
cntPrimePair = 0
differ = 0
#for i in N:
#primes = generatePrime( N )
primes = sievePrime( N )
length = len(primes)
for i in range(length):
    if i < (length - 1):
        differ = primes[i+1] - primes[i]
        if differ == 2:
            cntPrimePair += 1
print(cntPrimePair)
    