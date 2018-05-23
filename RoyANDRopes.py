t=int(input())
while t>0:
    len=int(input())
    u=[]
    l=[]
    u=str(input()).split()
    l=str(input()).split()
    maxi=0
    for i in range(len-1):
                if int(u[i])<(len-i-1):
                    u[i]='0'
                else:
                    val=int(u[i])-(len-1-i)
                    u[i]=str(val)
                if int(l[i])<(len-i-1):
                    l[i]='0'
                else:
                    val=int(l[i])-(len-1-i)
                    l[i]=str(val)
                maxi=max(maxi,max(int(l[i]),int(u[i])))
    print (maxi+len)
    t-=1
