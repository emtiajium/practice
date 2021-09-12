import PyPDF2, os

pdfFiles = []
for fileName in os.listdir(os.getcwd()):
    baseName = fileName[0:len(fileName)-4]
    extension = fileName[len(fileName)-4:len(fileName)].lower()
    fileName = baseName + extension
    if fileName.endswith('.pdf'):
        pdfFiles.append(fileName)
##        print(fileName)

pdfFiles.sort()

pdfWriter = PyPDF2.PdfFileWriter()
resultPdfFile = open('Combined.pdf', 'wb')
for fileIndex in range(len(pdfFiles)):
    fileName = pdfFiles[fileIndex]
    blahFile = open(fileName, 'rb')
    pdfReader = PyPDF2.PdfFileReader(blahFile)
    for pageNum in range(pdfReader.numPages):
        page = pdfReader.getPage(pageNum)
        pdfWriter.addPage(page)
    pdfWriter.write(resultPdfFile)
    blahFile.close()
resultPdfFile.close()
