n=int(input())
L=[]
for i in range(n+n):
    j=str(input())
    if j=="":
        continue
    initial=j.split()
    L.clear()
    if(initial[0].isdigit()==False):
        L.append(int(initial[4])-int(initial[2]))
    else:
        L.append(int(initial[0]))
    if(initial[2].isdigit()==False):
        L.append(int(initial[4])-int(initial[0]))
    else:
        L.append(int(initial[2]))
    if(initial[4].isdigit()==False):
        L.append(int(initial[0])+int(initial[2]))
    else:
        L.append(int(initial[4]))
    print(L[0]," + ",L[1]," = ",L[2],sep="")
