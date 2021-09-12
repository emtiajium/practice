function B=audioD(arr)

% clc;
% clear all;
% 
% z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\speech.wav';
% [arr, fs] = audioread(z);
n=length(arr);
% n=524288;

k=32;
r=k^2;
smpl=n;
q=floor(smpl/r);
x=[];
inl=1;
finl=int32(q);
for i=1:r
	m=1;
    for j=inl:finl
        x(m)=arr(j);
        m=m+1;
    end
    inl=finl+1;
    finl=inl+q-1;
    [C,L] = wavedec(x,3,'db1');
    t=0;
    t2=0;
    for j=1:L(1)
        t=t+C(j)^2*j;
        t2=t2+C(j)^2;
    end
    t=double(t);
    t2=double(t2);
    s(i)=mod(floor(t/t2),2);
end

B=reshape(s,k,k);
B = int64(B);