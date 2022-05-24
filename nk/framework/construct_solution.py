import sys
import json
from conf import *

meta = json.load(open(sys.argv[1], "r"))

code_file = open(sys.argv[2], "w")
code_file.write('class Solution {\n')
code_file.write('public:\n')
#code_file.write('    Solution() {}\n')
#code_file.write('    ~Solution() {}\n')
comments = []
for param in meta['params']:
    if param[2] != "":
        code_file.write('    // %s: %s\n' % (param[1], param[2]))
if meta['ret'][1] != "":
    code_file.write('    // ret: %s\n' % (meta['ret'][1]))
params = []
for param in meta['params']:
    params.append('%s %s' % (param[0], param[1]))
code_file.write('    %s %s(%s) {\n' % (meta['ret'][0], meta['func'], ", ".join(params)))
code_file.write('    }\n')
code_file.write('};\n')
code_file.close()
