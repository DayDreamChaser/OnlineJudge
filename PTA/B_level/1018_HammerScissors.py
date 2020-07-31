# # python3
# cnt = input()
# Alpha = [0, 0, 0]  # 甲乙
# Beta = [0, 0, 0]

# # count the succeed hand
# Suc_Alpha = []
# Suc_Beta = []

# states = [(1, -1), (-1, 1), (0, 0)] # >, <, =

# Table = [[("C", "J"), states[0]], [("C", "B"), states[1]],
         # [("J", "C"), states[1]], [("B", "C"), states[0]],
         # [("B", "J"), states[1]], [("J", "B"), states[0]]]


# def jCB(a, b):
    # if a == b:
        # return states[2]
    # else:
        # for i in range(len(Table)):
            # if a == Table[i][0][0] and b == Table[i][0][1]:
                # return Table[i][1]

# def maxNum(j, c, b):
    # # no equal condition
    # if j > b and j > c:
        # return "J"
    # elif c > j and c > b:
        # return "C"
	 # # elif b > c and b > j:		
    # else:
        # return "B"

# def sucessGeture(suc):
    # #
    # j, c, b = [suc.count(G) for G in ["J", "C", "B"]]
    # if j == b == c:
        # return "B"
    # elif j == c:
        # if b > j:
            # return "B"
        # else:
            # return "C"
    # elif c == b:
        # if j > c:
            # return "J"
        # else:
            # return "B"
    # elif j == b:
        # if c > j:
            # return "C"
        # else:
            # return "B"
    # else:
        # return MaxNum(j, c, b)

# def myPrint(array):
    # length= len(array)
    # for i in range(length):
        # print(array[i],  end="")
        # if i < (length - 1):
            # print(" ",  end="")
    # print("")

# for j in range(int(cnt)):
    # Gestures = input()
    # A, B = Gestures[0], Gestures[2]
    # # 1 0 -1
    # Ans_a, Ans_b = jCB(A, B)[0], jCB(A, B)[1]
    # # succeed
    # if Ans_a == 1:
        # Alpha[0] += 1
        # Beta[2] += 1
        # Suc_Alpha.append(A)  # count success gesture
    # elif Ans_b == 1:
        # Beta[0] += 1
        # Alpha[2] += 1      # failed
        # Suc_Beta.append(B)
    # # equal
    # elif Ans_a == 0:
        # Alpha[1] += 1
        # Beta[1] += 1

# myPrint(Alpha)
# myPrint(Beta)
# print(sucessGeture(Suc_Alpha), sucessGeture(Suc_Beta))

# python3
def jCB(a, b):
    if a == b:
        return states[2]
    else:
        return Table[(a, b)]

def sucessGeture(suc):
	max_cnt = max(list(suc.values()))
	max_gess = [key for key in suc.keys() if suc[key] == max_cnt]
	return sorted(max_gess)[0]

def myPrint(array):
	print("{} {} {}".format(array[0], array[1], array[2]))

cnt = input()
Alpha, Beta  = [0, 0, 0], [0, 0, 0]  # 甲乙
Suc_Alpha = {ges:0 for ges in ["J", "C", "B"]}  # count the succeed hand
Suc_Beta = {ges:0 for ges in ["J", "C", "B"]}


states = [(1, -1), (-1, 1), (0, 0)] # >, <, =
Table = { ("C", "J"):states[0], ("C", "B"):states[1],
         ("J", "C"):states[1], ("B", "C"):states[0],
         ("B", "J"):states[1], ("J", "B"):states[0]} 

for j in range(int(cnt)):
    Gestures = input()
    A, B = Gestures[0], Gestures[2]
    Ans_a, Ans_b = jCB(A, B)[0], jCB(A, B)[1]  # 1 0 -1
    if Ans_a == 1:
        Alpha[0] += 1      # succeed
        Beta[2] += 1
        Suc_Alpha[A] += 1   # count success gesture
    elif Ans_b == 1:
        Beta[0] += 1       # failed
        Alpha[2] += 1      
        Suc_Beta[B] += 1
    elif Ans_a == 0:        # equal
        Alpha[1] += 1
        Beta[1] += 1

myPrint(Alpha)
myPrint(Beta)
print(sucessGeture(Suc_Alpha), sucessGeture(Suc_Beta))
