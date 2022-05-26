rows, cols = (11,11)
rocks = [['--' for x in range(cols)] for y in range(rows)] 

rocks[0][:4] = ['--', '01', '02', '03']
rocks[1][:3] = ['10', '11', '12']
rocks[2][:2] = ['20', '21']
rocks[3][0] = '30'


for r in range(rows):
    for c in range(r,cols):
        if r == 0 and c == 8:
            pass
        if r + c > 4:
            for dr in range(0,4):
                for dc in range(0,4):
                    if 0 < dr + dc < 4 and dr <= r and dc <= c and rocks[r-dr][c-dc] == '--':
                        rocks[r][c] = f"{dr}{dc}"
                        rocks[c][r] = f"{dc}{dr}"
                        break
                if rocks[r][c] != '--':
                    break

print('--','  '.join([f"{i}" for i in range(rows)]))
for r in range(rows):
    print(r,' '.join(rocks[r]))