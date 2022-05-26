rows, cols = (11,11)
rocks = [['-' for x in range(cols)] for y in range(rows)] 


rocks[0][1] = 'R'
rocks[1][1] = 'B'
rocks[1][0] = 'L'

for r in range(rows):
    for c in range(cols):
        if r > 0 and rocks[r-1][c] == '-':
            rocks[r][c] = 'L'
            rocks[c][r] = 'R'
        if c > 0 and rocks[r][c-1] == '-':
            rocks[r][c] = 'r'
            rocks[c][r] = 'l'
        if c * r > 0 and rocks[r-1][c-1] == '-':
            rocks[r][c] = 'B'

print(rocks[2][0]=='-')
print('.',*list(range(rows)))
for r in range(rows):
    print(r,' '.join(rocks[r]))