import re

def matches_pattern(pattern, filename):
    regex_pattern = pattern.replace('.', r'\.').replace('*', r'.*')
    
    return re.fullmatch(regex_pattern, filename) is not None

def list_matching_files(pattern, files):
    matching_files = []
    for filename in files:
        if matches_pattern(pattern, filename):
            matching_files.append(filename)
    return matching_files

pattern = input()
n = int(input())
files = [input() for _ in range(n)]

matching_files = list_matching_files(pattern, files)

for filename in matching_files:
    print(filename)
