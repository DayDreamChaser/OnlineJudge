""" PTA-A 1015德才论"""
nums = input()
N, L, H = [ int(n) for n in nums.split() ]
saint = []
gentleman = []
fools= []
villian = []

cnt = N
for i in range(N):
    info = input()
    id, ethic, talent = [ int(i) for i in info.split() ]
    person = [ id, ethic, talent ]
    if ethic < L or talent < L:
        cnt -= 1
        continue
    # both ethic and talent large than H
    elif ethic >= H and talent >= H:
        saint.append( person )
    # ethic is bigger than talent
    elif ethic >= H and  H > talent >= L:
        gentleman.append( person )
    # lower type of both ethic and talent
    elif H > ethic >= L  and  H > talent >= L and ethic > talent:
        fools.append( person )
    else:
        villian.append( person )

def print_info( people ):
    for p in people:
        print( p[0], p[1], p[2] )
        
# sort at local
people = []    
print( cnt )  
people.extend( sorted(saint, key=lambda x:x[1]+x[2], reverse=True) )
people.extend( sorted(gentleman, key=lambda x:x[1]+x[2], reverse=True) )
people.extend( sorted( fools, key=lambda x:x[1]+x[2], reverse=True) )
people.extend( sorted( villian, key=lambda x:x[1]+x[2], reverse=True) )
print_info( people ) 
