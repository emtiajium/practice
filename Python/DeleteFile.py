import os

for filename in os.listdir():
    if filename.endswith('Thumbs.db'):
        os.unlink(filename)
        print(filename)
