std_str = input()
test_str = input()

chr_list = []
std_num = len(std_str)
test_num = len(test_str)

std_str = std_str.upper()
test_str = test_str.upper() 

std_list = [ chr for chr in std_str]
test_list = [ chr for chr in test_str]

std_set = set(std_list)
test_set = set(test_list)
bad_keys = []
for key in list(std_set):
	if key not in list(test_set):
		bad_keys.append(key)

order_keys = []
for chr in std_str:
	if chr in bad_keys and chr not in order_keys:
		order_keys.append(chr)

if len(order_keys) == 1:
	print(order_keys)
else:
	print("".join(order_keys))


# i = 0
# j = 0 
# print(std_num)

# start = input()
# while i <= (std_num - 1):
	# print("char comparing")
	# if test_str[j] != std_str[i]:
		# print("chars don't match")
		# if std_str[i] not in chr_list:
			# print("append bad key")
			# chr_list.append(std_str[i])
			# i += 1
	# elif test_str[j] == std_str[i]:
		# print("chars match")
		# i += 1
		# j += 1

# if len(chr_list) == 1:
	# print(chr_list)
# else:
	# print("".join(chr_list))

