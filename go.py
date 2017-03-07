def factorial(a,n,r):
    b=0
    l=1
    f=1
    d=1
    ex=1
    while b<n:
        ex=ex*a[b];
        f=ex
        while f>=10:
            f=f/10
        d=f
        b=r*l
        l=l+1
    ex=ex%mod;
    return ex,d;
n=int(input())
no=n
while no!= 0:
    n = n - 1
    mod=1000000007
    arr= array('i', [0] * n+5)
    for i in range(n): 
        arr[i]=int(input())
    n=int(input())
    while q != 0:
        q = q - 1
        flag=int(input())
        if flag==1:
            i=int(input())
            arr[i-1]=int(input())
        if flag==2:
            r=int(input())
            arr[i-1]=int(input())
            ex,d=factorial(arr,n,r)
            print(ex)
            print(d)
