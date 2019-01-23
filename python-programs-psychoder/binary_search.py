from sys import exit
def bins(a,lb,ub,key):
    mid=int((lb+ub)/2)
    if (lb>ub):
        print('key not found !')
        exit()
    else:
        if(key==a[mid]):
            print('key found at position %d'%(mid+1))
            exit()
        elif(key<a[mid]):
            bins(a,lb,mid-1,key)
        elif(key>a[mid]):
            bins(a,mid+1,ub,key)

def binary_search() :
    print('Enter the list elements:')
    a= list(map(int,input().split()))
    print('Enter key: ')
    key=int(input())
    a.sort()
    print('Sorted list:')
    print(*a)
    bins(a,0,len(a)-1,key)
print('{0:*^30}'.format('Binary Search'))
binary_search()
