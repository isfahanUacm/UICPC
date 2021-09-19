n = int(input())
mp = {}
li = []
for i in range(n):
    name, family, course = map(str, input().split())
    if course not in mp:
        mp[course] = set()
        li.append(course)
    mp[course].add(name + ' ' + family)
li.sort()
for course in li:
    print(course, len(mp[course]))
