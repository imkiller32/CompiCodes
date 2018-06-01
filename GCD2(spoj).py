def GCD(a,b):
    if(b==0):
        return a
    return GCD(b,a%b)

n=int(input())
for i in range(n):
    L=list(map(int,input().split()))
    a=L[0]
    b=L[1]
    print(GCD(a,b))
