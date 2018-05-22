#No idea (hackerRank)
#Link- https://www.hackerrank.com/challenges/no-idea/problem

x=str(input()).split()
# print (n)
n=int(x[0])
m=int(x[1])
#print(n,m,sep=",")
set1=list(map(int,input().split()))
print (set1)
set2=set(map(int,input().split()));
set3=set(map(int,input().split()))
happy=0
for i in set1:
    if i in set2:
        happy+=1
    elif i in set3:
        happy-=1
print (happy)
