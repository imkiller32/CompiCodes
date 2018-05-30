t=int(input())
for i in range(1,t+1):
    r=float(input())
    r=r//1
    ans=pow(2*r,2)
    sum=ans+0.25
    print ("Case ",i,": ",sum,sep="")
