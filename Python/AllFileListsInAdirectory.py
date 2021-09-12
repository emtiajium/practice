import os, subprocess

allFiles =  os.listdir(os.getcwd())
temp = ''
for file in allFiles:
    temp += file + '\n'
path = os.getcwd() + '\\fileList.txt'
helloFile = open('fileList.txt', 'w')
helloFile.write(str(temp))
helloFile.close()
subprocess.Popen(['start', path], shell = True)
