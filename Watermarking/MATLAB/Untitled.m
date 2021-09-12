clc;
clear all;

x='C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep.wav';
[arr,fs]=wavread(x);

x='C:\Users\Emtiaj\Documents\MATLAB\Sound\Beginning of the End.wav';
[arr2,fs]=wavread(x);

% x='C:\Users\Emtiaj\Documents\MATLAB\Sound\Breathing On Another Planet.wav';
% [arr3,fs]=wavread(x);
% 
% x='C:\Users\Emtiaj\Documents\MATLAB\Sound\Thousand Yard Stare.wav';
% [arr4,fs]=wavread(x);

z=3;w=1;


arr = arr(:,1);
dt = 1/fs;
t = 0:dt:(length(arr)*dt)-dt;
subplot(z,w,1);
plot(t,arr); 
title('Original signal');

arr = arr(:,1);
dt = 1/fs;
t = 0:dt:(length(arr)*dt)-dt;
subplot(z,w,2);
plot(t,arr); 
title('Watermarked signal');
ylabel('Amplitude');

arr = arr(:,1);
dt = 1/fs;
t = 0:dt:(length(arr)*dt)-dt;
subplot(z,w,3);
plot(t,arr-arr); 
title('Difference of signal');

% arr = arr(:,1);
% dt = 1/fs;
% t = 0:dt:(length(arr)*dt)-dt;
% subplot(z,w,4);
% plot(t,arr); 
% title('Thousand Yard Stare');

xlabel('Time (s)');