# 1021 个位数统计
number = str(input())
digits = [str(i) for i in range(10)]
digit_count = {i:number.count(i) for i in digits}

for i in range(10):
	if digit_count[str(i)] > 0:
		print("{0}:{1}".format(i, digit_count[str(i)]))