L1=[1,2,3,4,5]
L2=[4,5,6,7,8]
U=L1
I=[]
flag=0
for x in L2:
    flag=0
    for y in L1:
        if x==y:
            flag+=1
    if flag==1:    
        I.append(x)
    else:
        U.append(x)
print(U)
print(I)
