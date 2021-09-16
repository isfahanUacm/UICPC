di = [3,6,6,2,4,0,2,5,1,3,6,1]
day = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday'] 
d, m = map(int, input().split())
print(day[(d+di[m-1]-1)%7 ])