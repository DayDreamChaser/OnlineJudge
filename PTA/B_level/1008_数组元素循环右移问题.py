nums = input() 
L = nums.split(" ")
A, B = int(L[0]), int(L[-1])
B =  B % A

numChars = input().split(" ") 
Array = [ int(i) for i in numChars ] 

if B > 0:
    Array = Array[::-1]
    leftA = Array[:B][::-1]
    rightA = Array[B:][::-1]
    Array = leftA + rightA
    
length= len(Array)
for i in range(length):
    print( Array[i],  end="")
    if i < (length - 1):
        print( " ",  end="")
    i =  i + 1