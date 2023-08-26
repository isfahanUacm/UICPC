def BAPC_interpreter(program, n, input_list):
    output_list = input_list
    
    for command in program:
        if command == 'R':
            output_list.reverse()
        elif command == 'D':
            if len(output_list) == 0:
                return "error"
            output_list.pop(0)
    
    return output_list

# Read the number of test cases
num_test_cases = int(input())

# Process each test case
for _ in range(num_test_cases):
    program = input().strip()
    n = int(input())
    input_list = list(input()[1:-1].split(',')) 

    if n <= 0:
      input_list = []
    else:
      input_list = list(map(int, input_list))
        
    
    result = BAPC_interpreter(program, n, input_list)
    
    if result == "error":
        print("error")
    else:
        print('[{}]'.format(','.join(map(str, result))))