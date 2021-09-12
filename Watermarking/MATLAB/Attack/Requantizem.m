% function yq=Requantizem(arr)
clc;
clear all;

[arr, fs, bits] = wavread('C:\Users\Emtiaj\Documents\MATLAB\Sound\Thousand Yard Stare.wav');

wavwrite(arr,fs,8,'Thousand Yard Stare.wav');
[arr2,fs,bt2]=wavread('C:\Users\Emtiaj\Documents\MATLAB\Attack\Thousand Yard Stare.wav');

wavwrite(arr2,fs,16,'Thousand Yard Stare(requantized).wav');
[arr3,fs,bt3]=wavread('C:\Users\Emtiaj\Documents\MATLAB\Attack\Thousand Yard Stare(requantized).wav');
 
% subplot(2,1,1);
% plot(arr);
% subplot(2,1,2);
% plot(arr3);
