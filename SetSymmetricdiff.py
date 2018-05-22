n=int(input())
set1=set(input().split())
m=int(input())
set2=set(input().split())

print (len(set1.union(set2))-len(set1.intersection(set2)))
