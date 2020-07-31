# 1042 字符统计

# from collections import Counter
# cnt = Counter()  # a sub class of dict

text = input()

alpha = [chr(ord('a') + i) for i in range(26)]
alpha_dict = {char:0 for char in alpha}
for char in text.lower():
    if char in alpha:
        alpha_dict[char] += 1

num_alpha = {alpha_dict[char]:char for char in alpha_dict}
nums = list(alpha_dict.values())
# There may be two or more freq num
freq_num = max(nums)
freq_chars = [char for char in alpha_dict if alpha_dict[char] == freq_num]

freq_char = sorted(freq_chars)[0]
print(freq_char, freq_num)