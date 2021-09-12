% function yq=NoiseAdditionm(arr)
clc;
clear all;
% Open standard demo sound that ships with MATLAB.
z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Thousand Yard Stare.wav';
[arr, freq] = audioread(z);

SNR=20;
yq=awgn(arr,SNR);
wavwrite(yq,freq,'Thousand Yard Stare(awgn).wav');

% sound(yq, freq);
% 
% subplot(2,1,1);
% plot(arr);
% subplot(2,1,2);
% plot(yq);
