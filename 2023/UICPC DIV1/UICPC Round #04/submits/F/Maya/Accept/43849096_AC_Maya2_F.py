s = [0, 0, 0, 0, 0]
s[0] = input()
s[1] = input()
s[2] = input()
s[3] = input()
s[4] = input()

n = max([len(i) for i in s])
nn = int(n / 4) + (n % 4 != 0)

nums = []
for i in range(8):
    if (nn > i):
        nums.append('')
        for j in range(5):
            nums[i] = nums[i] + s[j][i * 4: i * 4 + 3];

number = 0
for i in range(8):
    if (nn > i):
        number *= 10
        if (nums[i] == '**** ** ** ****'):
            number += 0
        elif (nums[i] == '  *  *  *  *  *'):
            number += 1
        elif (nums[i] == '***  *****  ***'):
            number += 2
        elif (nums[i] == '***  ****  ****'):
            number += 3
        elif (nums[i] == '* ** ****  *  *'):
            number += 4
        elif (nums[i] == '****  ***  ****'):
            number += 5
        elif (nums[i] == '****  **** ****'):
            number += 6
        elif (nums[i] == '***  *  *  *  *'):
            number += 7
        elif (nums[i] == '**** ***** ****'):
            number += 8
        elif (nums[i] == '**** ****  ****'):
            number += 9
        else:
            print('BOOM!!')
            exit(0)

if (number % 6 == 0):
    print('BEER!!')
else:
    print('BOOM!!')
