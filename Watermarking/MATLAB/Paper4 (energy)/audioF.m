function key3=audioF(arr)

% clc;
% clear all;
% 
% z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\flute.wav';
% [arr, fs] = wavread(z);
n=length(arr);

% n=1024;
r=n/2048;
smpl=n;
frame=int32(floor(double(smpl/r)));

l=1;
inl=1;
% disp(smpl);disp(frame);
finl=int32(double(smpl)/double(frame))-1;
% disp(inl);disp(finl);
zx=finl;
ev=0;
F=[;];
for i=1:frame
    m=1;
    for j=inl:finl
        F(l,m)=arr(j);
        m=m+1;
    end
    inl=finl+1;
    finl=inl+zx-1;
%         disp(finl-inl);
%     disp(inl);disp(finl);
    tot=0;
    for k=1:zx
        tot=tot+F(l,k)^2;
    end
    fe(l)=tot;
    ev=ev+fe(l);
    l=l+1;
end

l=size(F);
ev=ev/frame;
for i=1:frame
    if fe(i)>ev
        bp(i)=1;
    else
        bp(i)=0;
    end
end

key3=int32(bp);