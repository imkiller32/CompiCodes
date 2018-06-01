i=0
while(i<10):
    s=input()
    r=1
    for j in s:
        if (j=='T'or j=='D'or j=='L'or j=='F'):
            r=r*2
    print(r)
    i+=1
