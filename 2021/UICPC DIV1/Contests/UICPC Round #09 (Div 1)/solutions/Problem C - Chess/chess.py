def out_of_access(a, b, x, y):
    # chack if two position are out of access from each other, in other words they're two tile with different colors
    # just check difference between x and y shows us each position is black or white:
    # odd difference means it's white and even means it's black
    # difference sum of two odd and two even numbers is even and shows they have same color.
    return (abs(a-b) + abs(x-y)) % 2


def solve(a, b, x, y):
    if (a, b) == (x, y):
        # if start and end position are the same with tuple comparing
        print(0, chr(ord('A')+a-1), b)
    elif a != x and abs(b-y)/abs(a-x) == 1:
        # if two positions are on a diagonal and accessible by one move
        # it works by calculating absolute slope of their straight line
        print(1, chr(ord('A')+a-1), b, chr(ord('A')+x-1), y)
    else:
        # solve this equation:
        # Y - y = 1 * (X - x), Y - b = -1 * (X - a)
        cx = (a + b + x - y)//2
        cy = cx - x + y
        # solve this equation:
        # Y - y = -1 * (X - x), Y - b = 1 * (X - a)
        dx = (x + y + a - b) // 2
        dy = dx - a + b
        # we calculate two other point of a rectangle our first positions made
        if 1 <= cx <= 8 and 1 <= cy <= 8:
            # if first point is in the chessboard answer that's the middle point between our positions,
            # otherwise second point work as above
            print(2, chr(ord('A') + a - 1), b, chr(ord('A') + cx - 1), cy, chr(ord('A') + x - 1), y)
        else:
            print(2, chr(ord('A') + a - 1), b, chr(ord('A') + dx - 1), dy, chr(ord('A') + x - 1), y)


if __name__ == '__main__':
    n = int(input())
    while n:
        n -= 1
        a, b, x, y = input().split()
        a = ord(a)-ord('A')+1
        b = int(b)
        x = ord(x)-ord('A')+1
        y = int(y)
        if out_of_access(a, b, x, y):
            print('Impossible')
        else:
            solve(a, b, x, y)
