#!/usr/bin/env python


import sys



env_file=sys.argv[1] #".env"
compose_file=sys.argv[2] #"docker-compose_templeate.yml"
#out_file=sys.argv[3]

replacements = {}


for env_line in open(env_file):
    e_li=env_line.strip()
    if not e_li.startswith("#") and e_li:
        env_name, env_val = env_line.split("=")
        replacements[env_name] = env_val.rstrip()
        #print env_name+':'+env_val
            
#print replacements       

with open(compose_file) as infile, open('out.yml', 'w') as outfile:
    for line in infile:
        for src, target in replacements.iteritems():
            line = line.replace('${'+src+'}', target)
        if line:
            outfile.write(line)
        
        

