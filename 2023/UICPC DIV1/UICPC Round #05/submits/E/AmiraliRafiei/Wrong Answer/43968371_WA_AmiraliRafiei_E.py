def is_palindrome(number):
    return str(number) == str(number)[::-1]

N = int(input())

for _ in range(N):
    number = int(input())

    # Find the closest palindromic number
    diff = 0
    while True:
        smaller = number - diff
        larger = number + diff
        
        if is_palindrome(smaller):
            closest_palindrome = smaller
            break
        elif is_palindrome(larger):
            closest_palindrome = larger
            break
        
        diff += 1
    
    print(closest_palindrome)
