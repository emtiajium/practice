function soundExtension = extractExtension(soundFile)

soundFileLength = length(soundFile);
if soundFile(soundFileLength) == ')' && soundFile(soundFileLength - 1) == '2' 
    soundExtension = '.mp3';
elseif soundFile(soundFileLength) == ')' && soundFile(soundFileLength - 1) == '4' 
    soundExtension = '.mp3';
elseif soundFile(soundFileLength) == ')' && soundFile(soundFileLength - 1) == '8' 
    soundExtension = '.mp3';
else
    soundExtension = '.wav';
end