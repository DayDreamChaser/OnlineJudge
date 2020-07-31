# 1019 数字黑洞 (20 分)

number = '{:0>4}'.format(int(input()))  # add 0 for those number less than 1000
print("number is ", number, "\n")

def desc_sort(number):
	# return "".join(sorted(number, reverse=True))
	return "".join(sorted(number))[::-1]

def asc_sort(number):
	return "".join(sorted(number))

def differ(number):
	# num is string
	num = number
	result = int(desc_sort(num)) - int(asc_sort(num))
	if result == 0:
		return 0
	else:
		return result
	
while True:
	des = desc_sort(number)
	asc = asc_sort(number)
	number = '{:0>4}'.format(differ(number))
	print("%04d - %04d = %04d" % (int(des), int(asc), int(number)))
	if int(number) == 0 or str(number) == '6174':
		break
	