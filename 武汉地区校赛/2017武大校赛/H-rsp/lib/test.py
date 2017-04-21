import CC17
import os

seq = [0]
seq_res = []
pat = []

for i in range(1, 524288 * 2):
    seq.append((seq[i - 1] * 65973 + 28411) % 524288)
for i in range(0, 524288 * 2):
    seq_res.append(seq[i] % 3)
for i in range(0, 524288 * 2):
    seq[i] = (3 - seq[i] % 3) % 3
for i in range(0, 480):
    pat.append((CC17.rps(0) + 3) % 3)
for i in range(0, 524288):
    flg = True
    sol = False
    for j in range(0, 480):
        flg = flg and (pat[j] == seq[j + i])
        if not flg:
            break
    if flg:
        sol = True
        for k in range(0, 1500):
            cur = i + 480 + k
            show = (seq_res[cur] + 1) % 3
            res = CC17.rps(show)
            if res == 100:
                break
    if sol:
        break
