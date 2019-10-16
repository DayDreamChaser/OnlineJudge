# -*- coding:UTF-8 -*-

def contain_pat( S ):
    num_P = S.count("P")
    num_T = S.count("T")
    sum = S.count("A") + num_P + num_T 
    if ( sum == len(S) and sum >= 3 ) and ( num_P == num_T == 1 ):
        return True  # just contain PAT
    else:
        return False

def is_right( S ):
    if contain_pat( S ):
        lens = len(S)
        pos_p = S.index("P")
        pos_t = S.index("T")
        count_a = len( S[:pos_p] ) # xPATx ==  aPATc --> xPAATxx
        if ( pos_p == 0 and pos_t == lens-1 ) and S.count('A') <= 2:
            return True  # PAT PAAT 
        elif "PAT" in S and ( count_a*2 == lens-3 ):
            return True  # APATA AAPATAA
        elif "PAAT" in S and ( count_a*3 == lens-4 ):
            return True  # APAATAA AAPAATAAAA
        elif pos_p * ( pos_t - pos_p - 1 ) == (lens - 1 -pos_t):
            if pos_p != 0:
                return True
            else:
                return False
        else:
            return False
    else:
        return False
        
num = int( input() )    
for i in range(num):
    formatStr = input()
    if is_right(formatStr):
        print("YES")
    else :
        print("NO")
    