#!/usr/bin/env python

import sys
import subprocess

def mdx_run(shell_commands):
    #print('in mdx_run')
    #print('shell_commands: {}'.format(shell_commands))
    out_list = list()
    out_list.append('Output:\n\n')
    out_list.append('```\n')
    for c in shell_commands:
        out_list.append('$ {}'.format(c))
        print('# executing: {}'.format(c[:-1]))
        try:
            out = subprocess.check_output(c[:-1] + '; exit 0',shell=True,stderr=subprocess.STDOUT)
        except subprocess.CalledProcessError as e:
            out = e.output
        out_list.append(out)
        #print('c: {}'.format(c))
    out_list.append('```\n')
    return out_list

def mdx_include(include_file, include_type):
    include_list = list()
    # open file
    try:
        finc = open(include_file,'r')
    except:
        print('Problem openning include file: {}'.format(include_file))
        sys.exit()
    # read lines
    include_list.append('`{}`:\n\n'.format(include_file))
    include_list.append('```{}\n'.format(include_type))
    include_list.extend(finc.readlines())
    include_list.append('```\n')
    # all done
    finc.close()
    return include_list

def mdx_process(infile,outfile):
    # open files and check
    try:
        fi = open(infile,'r')
    except:
        print('Problem openning input file.')
        sys.exit()
    try:
        fo = open(outfile,'w')
    except:
        print('Problem openning output file.')
        sys.exit()
    # list of lines for output
    in_list = fi.readlines()
    out_list = list()
    while True:
        if len(in_list) == 0:
            break
        line = in_list.pop(0)
        #print('line: {}'.format(line))
        if line.lower().startswith('!include'):
            # process include
            t = line.split()
            include_file = t[1]
            include_type = t[2]
            out_list.extend(mdx_include(include_file,include_type))
        elif line.lower().startswith('!run'):
            # process run
            # run shell commands and collect output
            shell_output = mdx_run(in_list[0:in_list.index('!end\n')])
            # append shell output to output list
            out_list.extend(shell_output)
            # get rid of lines
            in_list = in_list[in_list.index('!end\n')+1:]
        else:
            out_list.append(line)
    # write lines
    fo.writelines(out_list)
    # close files
    fi.close()
    fo.close()

if __name__ == '__main__':
    # call function
    print(' input file: {}'.format(sys.argv[1]))
    print('output file: {}'.format(sys.argv[2]))
    mdx_process(sys.argv[1], sys.argv[2])
