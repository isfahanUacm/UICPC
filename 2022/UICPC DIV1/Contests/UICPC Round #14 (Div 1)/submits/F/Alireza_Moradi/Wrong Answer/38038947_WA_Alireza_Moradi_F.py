A= list(input('Enter letters: ').lower())
B = list(input('Enter letters: ').lower())
output = []
result = 0
if (len(A) == len(B)):
    if ((A[0] == B[0]) and (A[-1] == B[-1])):
        del A[0], A[-1], B[0], B[-1]
        others = len(A)
        if ((A[0] == B[0]) and (A[-1] == B[-1])):
            result = others // 2
            print(result)
    elif ((A[0] == B[0])): 
        del A[0],B[0]
        others = len(A)
        result = others // 2
        print(result)