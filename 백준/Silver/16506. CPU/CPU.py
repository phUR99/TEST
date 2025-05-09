import sys

opcode = {
    "ADD": 0,
    "SUB": 1,
    "MOV": 2,
    "AND": 3,
    "OR": 4,
    "NOT": 5,
    "MULT": 6,
    "LSFTL": 7,
    "LSFTR": 8,
    "ASFTR": 9,
    "RL": 10,
    "RR": 11,
}

n = int(sys.stdin.readline().strip())
for i in range(n):
    ins, a, b, c = sys.stdin.readline().strip().split()
    ret = 0
    if ins[-1] == "C":
        ret |= 1 << 11
        ret |= opcode[ins[:-1]] << 12
    else:
        ret |= opcode[ins] << 12

    ret |= int(a) << 7
    ret |= int(b) << 4
    if ret & (1 << 11):
        ret |= int(c)
    else:
        ret |= int(c) << 1
    print(format(ret, "016b"))
