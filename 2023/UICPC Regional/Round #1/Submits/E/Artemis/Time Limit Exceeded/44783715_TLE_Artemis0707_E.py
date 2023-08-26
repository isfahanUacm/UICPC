import fnmatch

def ls(pattern, filenames):
  matching_files = []
  for filename in filenames:
    if fnmatch.fnmatchcase(filename, pattern):
      matching_files.append(filename)

  return matching_files


pattern = input()
filenames = []
for _ in range(int(input())):
    filenames.append(input())

matching_files = ls(pattern, filenames)

for filename in matching_files:
    print(filename)
