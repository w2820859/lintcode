import sys

target_file = open(sys.argv[1])
output_file = open(sys.argv[2])

target_str = target_file.readline().strip();
output_str = output_file.readline().strip();

if target_str == output_str:
    exit(0)
else:
    exit(1)
