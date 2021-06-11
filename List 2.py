L=[]
L2=[]
n=(int)(input('Enter words in sentence'))
for i in range (0,n,1):
 L.append(input())
c=int(input('Enter size of word to be removed'))
for i in L:
    if len(i)==c:
        continue
    else:
        L2.append(i)
s=""
for i in L2:
    s=s+" "+i
print(s)