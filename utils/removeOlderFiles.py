#!/usr/bi/python
''' Program that demonstrates how to remove older files
in a directory, and only defined count remain

Obtained from: http://www.henrykoch.de/en/python-remove-oldest-files-in-a-directory-only-a-defined-count-of-them-remains'''

import os

path ='/home/pi/images/'
#path = 'C:/Users/User/Pictures/images/'

maxFiles = 200

def updateStored(path):
  mtime = lambda f: os.stat(os.path.join(path,f)).st_mtime
  listD = list(sorted(os.listdir(path), key=mtime))
  delList = listD[0:(len(listD)-maxFiles)]
  
  for dFile in delList:
    os.remove(path+dFile)
    
  return
  
updateStored(path)
print('Folder Updated')
  
  
