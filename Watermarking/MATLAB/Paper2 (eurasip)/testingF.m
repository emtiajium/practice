clc;
clear all;

I = imread('HB.png');
level = graythresh(I);
img = im2bw(I,level);
wtr=int32(img);

z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Breathing On Another Planet.wav';
[arr, fs] = wavread(z);

q=audioF(arr);

z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Breathing On Another Planet(awgn).wav';
[arr, fs] = wavread(z);

s=audioF(arr);

disp('awgn');
val=ncber(wtr,s);


z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Breathing On Another Planet(resampling).wav';
[arr, fs] = wavread(z);

s=audioF(arr);

disp('resampling');
val=ncber(wtr,s);

z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Breathing On Another Planet(lpf).wav';
[arr, fs] = wavread(z);

s=audioF(arr);

disp('lpf');
val=ncber(wtr,s);

z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Breathing On Another Planet(requantized).wav';
[arr, fs] = wavread(z);

s=audioF(arr);

disp('requantized');
val=ncber(wtr,s);

z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Breathing On Another Planet(echo).wav';
[arr, fs] = wavread(z);

s=audioF(arr);

disp('echo');
val=ncber(wtr,s);

z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Breathing On Another Planet(reverse).wav';
[arr, fs] = wavread(z);

s=audioF(arr);

disp('reverse');
val=ncber(wtr,s);

z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Breathing On Another Planet(32).mp3';
[arr, fs] = audioread(z);

s=audioF(arr);

disp('32');
val=ncber(wtr,s);

z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Breathing On Another Planet(64).mp3';
[arr, fs] = audioread(z);

s=audioF(arr);

disp('64');
val=ncber(wtr,s);

z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Breathing On Another Planet(128).mp3';
[arr, fs] = audioread(z);

s=audioF(arr);

disp('128');
val=ncber(wtr,s);