# -*- coding:UTF-8 -*-
# PTA 1004 成绩排名
print("Please input a integer:")
num = int( input() )
students = []
tags = ('Name', 'Id', 'Score')

while num > 0:
    tmp = {} # init
    info = input()
    items = info.split(" ")
    tmp = { tag:item  for tag, item in zip(tags, items) }
    #print(tmp)
    score = int( tmp[tags[-1]] )
    tmp[tags[-1]] = score # int
    students.append( tmp )
    num -= 1
    
# get all the score
grades = [ student[ tags[-1] ]  for student in students ]
#print("grades", grades)
grades.sort()
#print("grades", grades)

low = grades[0]
high = grades[-1]
grades = [ high, low ] # rellocate
#print("grades", grades)

for i in range( 2 ):
    for d in students:
        #  find the specifc score of correspond student
        if d[ tags[-1] ] == grades[i]:
            print( d[ tags[0] ], d[ tags[1] ], end='' )
            if i == 0:
                print("")    
    
