def decode_message(encoded):
    n = len(encoded)
    side_length = int(n ** 0.5)
    
    matrix = [[''] * side_length for _ in range(side_length)]
    
    index = 0
    for i in range(side_length):
        for j in range(side_length):
            matrix[i][j] = encoded[index]
            index += 1
    
    rotated = []
    for j in range(side_length - 1, -1, -1):
        for i in range(side_length):
            rotated.append(matrix[i][j])
    
    decoded = ''.join(rotated)
    return decoded

num_test_cases = int(input())

for _ in range(num_test_cases):
    encoded_message = input()
    decoded_message = decode_message(encoded_message)
    print(decoded_message)