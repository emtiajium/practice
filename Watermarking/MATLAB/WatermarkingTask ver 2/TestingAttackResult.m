clc;
clear all;

location = 'D:\PROGRAMMINGtASK\Watermarking\MATLAB\Sound\';
soundFile = 'Citizen, Go Back to Sleep';
attackedSoundFile = 'Citizen, Go Back to Sleep(echo)';

soundExtension = extractExtension(soundFile);
attackedSoundExtension = extractExtension(attackedSoundFile);
z = strcat(location, strcat(soundFile, soundExtension));
zz = strcat(location, strcat(attackedSoundFile, attackedSoundExtension));


[array, fs] = audioread(z); % works with updated Matlab

watermark = imageProcess();

audioData = audioProcess(array);

arraySize = size(watermark);

for i = 1:arraySize(1)
    for j = 1:arraySize(2)
        key(i, j) = bitxor(watermark(i, j), audioData(i, j));
    end
end

% Attacked sound processing
[array, fs] = audioread(zz);

attackedAudioData = audioProcess(array);

for i = 1:arraySize(1)
    for j = 1:arraySize(2)
        restoredWatermark(i, j) = bitxor(key(i, j), attackedAudioData(i, j));
    end
end

zzz = logical(restoredWatermark);
imshow(zzz);
% imwrite(zzz,'filename.png');

val = ncber(watermark, restoredWatermark);
