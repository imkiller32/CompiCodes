def GCD(a,b):
    if(b==0):
        return a
    return GCD(b,a%b)

a=int(input())
b=int(input())
c=int(input())
d=GCD(a,b)
print(GCD(d,c))
