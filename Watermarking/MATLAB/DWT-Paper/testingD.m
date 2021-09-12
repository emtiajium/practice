clc;
clear all;

I = imread('BN.jpg');
level = graythresh(I);
img = im2bw(I,level);
wtr=int64(img);

z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep.wav';
[arr, fs] = wavread(z);

q=audioD(arr);

sz=size(wtr);

for i=1:sz(1)
    for j=1:sz(2)
        key(i,j)=bitxor(wtr(i,j),q(i,j));
    end
end


zz = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep(requantized).wav';
[yq, fs] = audioread(zz);

s=audioD(yq);
% disp(s);

for i=1:sz(1)
    for j=1:sz(2)
        wbar(i,j)=bitxor(key(i,j),s(i,j));
    end
end

val=ncber(wtr,wbar);
