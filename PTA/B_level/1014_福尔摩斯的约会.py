""" PAT-B 1014 福尔摩斯的约会
Input:
    3485djDkxh4hhGE
    2984akDfkkkkggEdsb
    s&hgsfdk
    d&Hyscvnm
Output:
    THU 14:04
"""
seqs_a = input()
seqs_b = input()
seqs_day1 = input()
seqs_day2 = input()

# From days[0] to daya[6] is equals to each day in a week
days = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"]
day_in_week = {chr(ord("A")+i): days[i] for i in range(len(days))}

hours = [str(i) for i in range(10)]  # From 0-9 and A-N to represent 0-23 hour
hours.extend([chr(ord("A")+i) for i in range(14)])
hours = {hours[i]: str(i) for i in range(len(hours))}
for i in [str(i) for i in range(10)]:
    hours[i] = "0" + hours[i]

# Search for the first upper equaled alpha and second equaled char
cnt = 0  # the first identical char pair
first_chr = ""
second_chr = ""
for a, b in zip(seqs_a, seqs_b):
    # first char is a upper alpha
    if a == b:
        if cnt == 0 and a in day_in_week.keys():
            # round 1
            first_chr = a    # a must in A:G
            cnt = 1
        elif cnt == 1 and a in hours.keys():
            second_chr = a   # a must in char seq 0:N
            break

index = 0
for x, y in zip(seqs_day1, seqs_day2):
    if x == y and x.isalpha():
        break
    index += 1
minutes = ("0" + str(index)) if index < 10 else str(index)

print(day_in_week[first_chr], "{0}:{1}".format(hours[second_chr], minutes))
