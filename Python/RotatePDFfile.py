import PyPDF2, os

##Make a folder
##Copy RotatePDFfile.py and all PDF files you want to rotate
##Click F5

pdfFiles = []
for fileName in os.listdir(os.getcwd()):
    baseName = fileName[0:len(fileName)-4]
    extension = fileName[len(fileName)-4:len(fileName)].lower()
    fileName = baseName + extension
    if fileName.endswith('.pdf'):
        pdfFiles.append(fileName)
##        print(fileName)

for fileIndex in range(len(pdfFiles)):
    fileName = pdfFiles[fileIndex]
    blahFile = open(fileName, 'rb')
    pdfReader = PyPDF2.PdfFileReader(blahFile)
    pdfWriter = PyPDF2.PdfFileWriter()
    for pageNum in range(pdfReader.numPages):
        page = pdfReader.getPage(pageNum)
        page.rotateClockwise(90) # Rotation degree
        pdfWriter.addPage(page)
    resultPdfFile = open('Rotated ' + fileName, 'wb')
    pdfWriter.write(resultPdfFile)
    resultPdfFile.close()
    blahFile.close()

print('Rotated. Happy?')
