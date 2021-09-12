clc;
clear all;

% x='C:\Users\Emtiaj\Documents\MATLAB\Sound\Beginning of the End.wav';
[arr,fs]=audioread('blah.wav');

z=4; w=4;


arr = arr(:,1);
dt = 1/fs;
t = 0:dt:(length(arr)*dt)-dt;
subplot(z,w,1);
plot(t,arr); 

arr = arr(:,1);
dt = 1/fs;
t = 0:dt:(length(arr)*dt)-dt;
subplot(z,w,2);
plot(t,arr); 

arr = arr(:,1);
dt = 1/fs;
t = 0:dt:(length(arr)*dt)-dt;
subplot(z,w,3);
plot(t,arr); 

arr = arr(:,1);
dt = 1/fs;
t = 0:dt:(length(arr)*dt)-dt;
subplot(z,w,4);
plot(t,arr); 