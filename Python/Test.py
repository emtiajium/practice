import os

helloFile = open('blah.html', 'r')
helloWrite = open('blah.txt', 'w')
helloContent = helloFile.read()
helloWrite.write(helloContent)
helloFile.close()
helloWrite.close()
print(helloContent)
