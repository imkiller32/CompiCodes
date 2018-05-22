n=int(input())
set1=set(map(int,input().split()))
m=int(input())
for i in range(m):
    x=str(input()).split()
    newSet=set(map(int,input().split()))
    if x[0]=='intersection_update':
        set1.intersection_update(newSet)
    elif x[0]=='update':
        set1.update(newSet)
    elif x[0]=='symmetric_difference_update':
        set1.symmetric_difference_update(newSet)
    elif x[0]=='difference_update':
        set1.difference_update(newSet)
print (sum(set1))
