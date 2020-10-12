#!/bin/python

import copy

# list of all folders
path_list = [ "./C", "./C-Plus-Plus", "./C#", "./Go", "./Java", 
						"./Javascript", "./Kotlin", "./PHP", "./Python", "./Scala"]

# checking all files
for path in path_list :
  path+="/readme.md"

  lines=[]
  format_line=[]

  with open(path) as f:
    for i,line in enumerate(f):
      if line == '\n' :
        continue

      # taking first 2 line as it is
      if i < 2 :
        format_line.append(line)
        continue

      # taking all other lines
      lines.append(line)

  # creating a copy for check
  test = copy.deepcopy(lines) 
  test.sort()

  # if sorted copy is as same as file no need to change
  if test == lines :
    continue

  # if different then sorted rewite whole file
  else:
    with open(path,"w") as f:
      f.write("".join(format_line))
      f.write("\n".join(test))
    # outputting which file is arranged
    print("ARRANGED "+path) 
  print("_"*100)
