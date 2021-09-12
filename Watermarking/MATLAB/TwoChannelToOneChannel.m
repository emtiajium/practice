clc;
clear all;

z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Thousand Yard Stare.wav';
[arr, fs] = audioread(z);
n=length(arr);

for i=1:n
    arr2(i)=arr(i,1);
end

wavwrite(arr2,fs,16,'Thousand Yard Stare.wav');

% sound(arr2, fs);

% subplot(2,1,1);
% plot(arr);
% subplot(2,1,2);
% plot(arr2);
% 
% 
% 
