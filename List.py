L1=[]
for i in range (0,4,1):
    L1.append(input())
L2=[]
c=0
for word in L1:
    if word[0] == word[-1] :
        L2.append(word)
        c+=1
print(L2)
print(c)