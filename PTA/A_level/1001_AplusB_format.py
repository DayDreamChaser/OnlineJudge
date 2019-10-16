""" Programs for PTA(advance)-1001 A+B Format """

nums = input()
a, b = [ int(num) for num in nums.split() ]

sum_of_nums  = a + b
if sum_of_nums  < 0:
    print("-", end = "")

def output( nums_sum ):
    # output three digits with a commas
    length = len( nums_sum )
    if length < 4:
        print( nums_sum )
    else:
        for cha in nums_sum:
            print( cha, end = "")
            length -= 1
            if (length % 3) == 0 and length >= 3:
                print( ',', end = "")
                
sum_of_nums = abs( sum_of_nums )
output( str(sum_of_nums) )
