n=int(input())
val1=set(input().split())
m=int(input())
val2=set(input().split())

val3=val1.union(val2)

print (len(val3))
