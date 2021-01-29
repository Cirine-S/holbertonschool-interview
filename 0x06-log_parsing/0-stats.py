#!/usr/bin/python3
"""pqrsing qlgo """
import sys

status = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}
file_size = 0
try:
    for i, line in enumerate(sys.stdin, 1):
        line_splitted = line.split()
        file_size += int(line_splitted[-1])
        if line_splitted[-2] in status:
            status[line_splitted[-2]] += 1
        if i % 10 == 0:
            print("File size: {}".format(file_size))
            for k, v in status.items():
                if status[k] > 0:
                    print("{}: {}".format(k, status[k]))

except KeyboardInterrupt:
    pass
finally:
	print("File size: {}".format(file_size))
	for k, v in status.items():
		if status[k] > 0:
			print("{}: {}".format(k, status[k]))
