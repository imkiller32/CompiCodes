m=int(input())
val=input()
nList=val.split()
mySet1=set()

for i in nList:
    mySet1.add(int(i))
    
n=int(input())
val=input()
nList=val.split()
mySet2=set()

for i in nList:
    mySet2.add(int(i))
  
newSet1=mySet1.union(mySet2)
newSet2=mySet1.intersection(mySet2)
ans=newSet1.difference(newSet2)
myList=[]
for i in ans:
    myList.append(int(i))
myList.sort()
for i in myList:
    print (i)
