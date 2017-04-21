n = input()

ans = 0
if n == 0:
    ans = 1
while n > 0:
    x = n % 16
    n /= 16
    if x == 0 or x == 4 or x == 6 or x == 9 or x == 10 or x == 13:
        ans += 1
    else:
      if x == 8 or x == 11:
          ans += 2

print ans