# 1019 数字黑洞 (20 分)
number = str(input())

def count_sort(number, reverse = False):
   # number is digit string, sort by descend
	nums = [i for i in range(10)]
	bucket = [number.count(str(i)) for i in nums]
	
	digit_collect = []
	for i in nums[::-1]:
		# get count num in bucket
		if bucket[i] != 0:
			digit_collect.extend([j for j in bucket[i] * str(i)])
	ret_nums = "".join(digit_collect)
	
	return ret_nums if reverse == False else ret_nums[::-1]
	
def asc_sort(number):
   # 非递减排序
	return count_sort(number, reverse = True)
	
def desc_sort(number):
	# 非递增排序
	return count_sort(number)

def differ(number):
	# number is str
	num = number
	result = int(desc_sort(num)) - int(asc_sort(num))
	if result == 0:
		return '0000'
	else:
		return str(result)
	
while differ(number) != '0000' and differ(number) != '6174':
	print("%04d - %04d = %04d" % (int(desc_sort(number)), int(asc_sort(number)), int(differ(number))))
	number = desc_sort(differ(number))

print("%04d - %04d = %04d" % (int(desc_sort(number)), int(asc_sort(number)), int(differ(number))))
	