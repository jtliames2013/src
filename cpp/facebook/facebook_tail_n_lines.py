import os
import sys

def get_last_n_lines(file_name, N):
    res=[]
    with open(file_name, 'rb') as fd:
        # Move the cursor to the end of the file
        fd.seek(0, os.SEEK_END)
        buffer = bytearray()
        pos = fd.tell()
        while pos>=0:
            fd.seek(pos)
            byte = fd.read(1)
            pos -= 1
            if byte == b'\n':
                res.append(buffer.decode()[::-1])
                if len(res) == N: return list(reversed(res))
                buffer = bytearray()
            else:
                buffer.extend(byte)

    if len(buffer) > 0:
        res.append(buffer.decode()[::-1])

    return list(reversed(res))

if __name__ == "__main__":
    file_name = sys.argv[1]
    N = int(sys.argv[2])
    lines = get_last_n_lines(file_name, N)
    for line in lines:
        print(line)