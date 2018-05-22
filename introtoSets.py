def average(array):
    # your code goes here
    new=set(array)
    sum=0
    for i in new:
        sum+=i
    r=sum/len(new)
    return r
