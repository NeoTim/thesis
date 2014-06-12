def process_userid(s):
    while len(s) % 8:
        s.append(0x40)


def process_key(s):
    # replace missing characters in key by EBCDIC spaces (0x40)
    while len(s) % 8 or len(s) == 0:
        s.append(0x40)
    for i in range(0, 8):
        # secret sauce
        s[i] = ((s[i] ^ 0x55) << 1) & 0xff

# truncate password & username and encode to EBCDIC charset
ue = USERNAME[0:8].decode('ascii').encode('EBCDIC-CP-BE')
pe = PASSWORD[0:8].decode('ascii').encode('EBCDIC-CP-BE')
ues = bytearray(ue)
process_userid(ues)
pes = bytearray(pe)
process_key(pes)
pesj = str(pes)
uesj = str(ues)
des = DES.new(pesj, DES.MODE_CBC)

HASH = des.encrypt(uesj)
