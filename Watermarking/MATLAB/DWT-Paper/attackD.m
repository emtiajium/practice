clc;
clear all;

z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep.wav';
[arr, fs] = wavread(z);

I = imread('BN.jpg');
level = graythresh(I);
img = im2bw(I,level);
wtr=int64(img);
% disp(wtr);

q=audioD(arr);
% disp(q);

sz=size(wtr);

for i=1:sz(1)
    for j=1:sz(2)
        key(i,j)=bitxor(wtr(i,j),q(i,j));
    end
end

% disp(key);

zz = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep(awgn).wav';
[yq, fs] = audioread(zz);

s=audioD(yq);
% disp(s);

for i=1:sz(1)
    for j=1:sz(2)
        wbar(i,j)=bitxor(key(i,j),s(i,j));
    end
end

disp('awgn');
val=ncber(wtr,wbar);

zz = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep(resampling).wav';
[yq, fs] = audioread(zz);

s=audioD(yq);
% disp(s);

for i=1:sz(1)
    for j=1:sz(2)
        wbar(i,j)=bitxor(key(i,j),s(i,j));
    end
end

disp('resamplingh');
val=ncber(wtr,wbar);

zz = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep(lpf).wav';
[yq, fs] = audioread(zz);

s=audioD(yq);
% disp(s);

for i=1:sz(1)
    for j=1:sz(2)
        wbar(i,j)=bitxor(key(i,j),s(i,j));
    end
end

disp('lpf');
val=ncber(wtr,wbar);

zz = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep(requantized).wav';
[yq, fs] = audioread(zz);

s=audioD(yq);
% disp(s);

for i=1:sz(1)
    for j=1:sz(2)
        wbar(i,j)=bitxor(key(i,j),s(i,j));
    end
end

disp('requantized');
val=ncber(wtr,wbar);

zz = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep(echo).wav';
[yq, fs] = audioread(zz);

s=audioD(yq);
% disp(s);

for i=1:sz(1)
    for j=1:sz(2)
        wbar(i,j)=bitxor(key(i,j),s(i,j));
    end
end

disp('echo');
val=ncber(wtr,wbar);

zz = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep(reverse).wav';
[yq, fs] = audioread(zz);

s=audioD(yq);
% disp(s);

for i=1:sz(1)
    for j=1:sz(2)
        wbar(i,j)=bitxor(key(i,j),s(i,j));
    end
end

disp('reverse');
val=ncber(wtr,wbar);

zz = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep(32).mp3';
[yq, fs] = audioread(zz);

s=audioD(yq);
% disp(s);

for i=1:sz(1)
    for j=1:sz(2)
        wbar(i,j)=bitxor(key(i,j),s(i,j));
    end
end

disp('32');
val=ncber(wtr,wbar);

zz = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep(64).mp3';
[yq, fs] = audioread(zz);

s=audioD(yq);
% disp(s);

for i=1:sz(1)
    for j=1:sz(2)
        wbar(i,j)=bitxor(key(i,j),s(i,j));
    end
end

disp('64');
val=ncber(wtr,wbar);

zz = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\Citizen, Go Back to Sleep(128).mp3';
[yq, fs] = audioread(zz);

s=audioD(yq);
% disp(s);

for i=1:sz(1)
    for j=1:sz(2)
        wbar(i,j)=bitxor(key(i,j),s(i,j));
    end
end

disp('128');
val=ncber(wtr,wbar);