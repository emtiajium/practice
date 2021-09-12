clc;
clear all;

I = imread('BN.jpg');
level = graythresh(I);
img = im2bw(I,level);
% img=int32(img);
img2=reshape(img,1,1024);
x2 = random('Poisson',1:1024,1,1024);
x2=int32(x2);
for i=1:1024
    x2(i)=mod(x2(i),2);
end
j=1; 
k=2;
wtr=[];
for i=1:1024
    wtr(j)=img2(i);
    wtr(k)=x2(i);
    j=j+2;
    k=k+2;
end

wtr=int32(wtr);

z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep.wav';
[arr, fs] = wavread(z);

q=audioF(arr);

key=[];
for i=1:2048
   key(i)=bitxor(q(i),wtr(i));
end

z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep(awgn).wav';
[arr, fs] = wavread(z);

s=audioF(arr);

wbar=[];
for i=1:2048
   wbar(i)=bitxor(s(i),key(i));
end

disp('awgn');
val=ncber(wtr,wbar);


z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep(resampling).wav';
[arr, fs] = wavread(z);

s=audioF(arr);

wbar=[];
for i=1:2048
   wbar(i)=bitxor(s(i),key(i));
end

disp('resampling');
val=ncber(wtr,wbar);

z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep(lpf).wav';
[arr, fs] = wavread(z);

s=audioF(arr);

wbar=[];
for i=1:2048
   wbar(i)=bitxor(s(i),key(i));
end

disp('lpf');
val=ncber(wtr,wbar);

z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep(requantized).wav';
[arr, fs] = wavread(z);

s=audioF(arr);

wbar=[];
for i=1:2048
   wbar(i)=bitxor(s(i),key(i));
end

disp('requantized');
val=ncber(wtr,wbar);

z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep(echo).wav';
[arr, fs] = wavread(z);

s=audioF(arr);

wbar=[];
for i=1:2048
   wbar(i)=bitxor(s(i),key(i));
end

disp('echo');
val=ncber(wtr,wbar);

z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep(reverse).wav';
[arr, fs] = wavread(z);

s=audioF(arr);

wbar=[];
for i=1:2048
   wbar(i)=bitxor(s(i),key(i));
end

disp('reverse');
val=ncber(wtr,wbar);

z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep(32).mp3';
[arr, fs] = audioread(z);

s=audioF(arr);

wbar=[];
for i=1:2048
   wbar(i)=bitxor(s(i),key(i));
end

disp('32');
val=ncber(wtr,wbar);

z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep(64).mp3';
[arr, fs] = audioread(z);

s=audioF(arr);

wbar=[];
for i=1:2048
   wbar(i)=bitxor(s(i),key(i));
end

disp('64');
val=ncber(wtr,wbar);

z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep(128).mp3';
[arr, fs] = audioread(z);

s=audioF(arr);

wbar=[];
for i=1:2048
   wbar(i)=bitxor(s(i),key(i));
end

disp('128');
val=ncber(wtr,wbar);