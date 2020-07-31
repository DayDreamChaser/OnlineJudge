# 1094 谷歌的招聘

# 在这个问题上， 用C/C++ 比python快 4倍， 内存只用python的1/8
import math
input_nums = input()
L, N = [int(num) for num in input_nums.split(" ")]
number = input() #length = L

def is_prime_sqrt(N):
	if N <= 1:
		return False
	else:
		flag = True
		num = int(math.sqrt(N))
		for  i in range(2, num+1):
			if (N % i) == 0:
				flag = False
				break
		return flag

# 找N以上的， 如果L小于N就不考虑
flag = 0
for i in range(L - N + 1):
	cur_num = int(number[i:i+N])
	num_string = number[i:i+N]
	# print(cur_num)	if 200236, then 0023
	if is_prime_sqrt(cur_num):
		flag = 1
		break

if flag == 1:
    print(num_string)
else:
    print("404")    