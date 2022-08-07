primes = []
sieve = [True] * 100000
for p in range(2, len(sieve)):
  if sieve[p]:
    primes.append(p)
    for j in range(2*p,len(sieve),p):
      sieve[j] = False

def decomposition(n):
  global primes
  res = dict()
  for p in primes:
    if n % p == 0:
      res[p] = 0
      while n % p == 0:
        res[p] += 1
        n //= p
  if n != 1:
    res[n] = 1
  return res

def divisors(n):
  decomp = decomposition(n)
  nb = 1
  for p in decomp:
    nb *= decomp[p]+1
  result = []
  for i in range(nb):
    act = 1
    for p in decomp:
      act *= p ** (i % (decomp[p]+1))
      i //= decomp[p]+1
    result.append(act)
  return result

def gcd(a, b):
  if a < b:
    return gcd(b, a)
  if a % b == 0:
    return b
  return gcd(b, a%b)

for _ in range(int(input())):
  w, l = map(int, input().split())
  s = [1,2]
  s += divisors(gcd(w-1, l-1))
  s += divisors(gcd(w-2, l))
  s += divisors(gcd(w, l-2))
  s = sorted(list(set(s)))
  print(len(s), " ".join(map(str, s)))
  
