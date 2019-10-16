num = int( input() )
A, B, C = 0, 0, 0

for i in range(num):
    numbers = input().split()
    A, B, C = [ int(n) for n in  numbers ]
    print("Case #%d: " % (i+1) , end="") 
    if ( A + B) > C :
        print("true")
    else:
        print("false")
