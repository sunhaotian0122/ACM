import CC17

for i in range(0, 3000):
    res = CC17.rps(i % 3)
    if res == 100:
        break
