L=[]
PrefixSum=[]
m=1298074214633706835075030044377087
L.append(int(1))
PrefixSum.append(int(1))
L.append(int(2))
PrefixSum.append(int(3))
L.append(int(4))
PrefixSum.append(int(7))
for i in range(3,501):
    j=(2*L[i-1])%m
    L.append(j)
    PrefixSum.append(int((PrefixSum[i-1]+j)%m))

test=int(input())
for i in range(test):
    n=int(input())
    print(PrefixSum[n])
