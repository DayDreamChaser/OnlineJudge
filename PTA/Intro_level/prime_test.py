import math

def sievePrime(n):
	A = [i for i in range(n+1)]
	num = int(math.sqrt(n))
	for p in range(2, num+1):
		if A[p] != 0:    # p hasn't been eliminated on previous passes
			j = p * p
			while j <= n: # p*p <= n
				A[j] = 0  # mark element as eliminated
				j = j + p # 不断剔除p的倍数
	return [ item for item in A if item >= 2 ]

def main():
	text_input = input()
	low, high = [int(i) for i in text_input.split(" ")]
	pre_primes = sievePrime(high)
	primes = [p for p in pre_primes if p >= low and p < high]
	if len(primes) == 0:
		print("0")
	else:
		print(primes)
		ten_digit = sum([ p//10 for p in primes if p > 10])
		one_digit = sum([ p%10 for p in primes])
		print( ten_digit if ten_digit < one_digit else one_digit )
		
if __name__ == "__main__":
	main()
