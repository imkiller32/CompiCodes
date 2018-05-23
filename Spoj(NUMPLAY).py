dp1=[]
dp3=[]
dp5=[]
dp7=[]
dp1.append(0),dp3.append(0),dp5.append(0),dp7.append(0)
dp1.append(1),dp3.append(1),dp5.append(1),dp7.append(1)
for i in range(2,10001):
    dp1.append(int(dp3[i-1]))
    dp3.append(int(dp1[i-1]+dp5[i-1]))
    dp5.append(int(dp7[i-1]))
    dp7.append(int(dp5[i-1]+dp3[i-1]))

t=int(input())
for i in range(t):
    n=int(input())
    answer=0
    if n:
        answer=dp1[n]+dp3[n]+dp5[n]+dp7[n]
    print (answer)
    
