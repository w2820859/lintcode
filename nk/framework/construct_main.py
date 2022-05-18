import sys
import json
from conf import *

meta = json.load(open(sys.argv[1], "r"))
entry_file = open(sys.argv[2], "w")
entry_file.write('#include "algo.hpp"\n')
entry_file.write('#include "parser.h"\n')
entry_file.write('#include "dumper.h"\n')
entry_file.write('int main(int argc, char** argv) {\n')
entry_file.write('    if (argc - 1 != %s) {\n' % (len(meta['params'])))
entry_file.write('        return -1;\n')
entry_file.write('    }\n')
entry_file.write('    Solution so;\n')
params = []
param_num = 0
for param in meta['params']:
    param_num += 1
    param_name = param[1]
    params.append(param_name)
    entry_file.write('    ' + param[0] + ' ' + param_name + ' = ' + parser[param[0]] % ('argv[' + str(param_num) + ']') + ";\n")
entry_file.write('    ' + meta['ret'][0] + ' ret = so.' + meta['func'] + '(' + ','.join(params) + ');\n')
entry_file.write('    ' + 'cout << ' + dumper[meta['ret'][0]] + ';' + '\n')
entry_file.write('    return true;\n')
entry_file.write('}\n')
entry_file.close()
