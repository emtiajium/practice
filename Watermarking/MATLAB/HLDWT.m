function key3=audioF(arr)

% clc;
% clear all;
% 
% z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\flute.wav';
% [arr, fs] = wavread(z);
n=length(arr);

% n=1024;
frame=int32(floor(double(n/512)));

l=1;
inl=1;
% disp(smpl);disp(frame);
finl=512;
% disp(inl);disp(finl);
zx=finl;

for i=1:frame
    m=1;
    for j=inl:finl
        F(l,m)=arr(j);
        m=m+1;
    end
    inl=finl+1;
    finl=inl+zx-1;
    tot=0;
    for k=1:zx
        tot=tot+F(l,k)^2;
    end
    e(l)=tot;
    l=l+1;
end

l=size(F);

[B,I]=sort(e,'descend');

ll=length(B);

for i=1:ll
    xx=I(i);
    for j=1:zx
        t=F(i,j);
        F(i,j)=F(xx,j);
        F(xx,j)=t;
    end
end

T=int32(32);

for i=1:T
    key1(i)=i;
end

zz=[];
ll=1;

for i=1:T
    for j=1:zx
        x(j)=F(i,j);
    end
    [C,D]=wavedec(x,3,'db1');
    for j=1:D(1)
        yyy(j)=C(j);
    end
    yy=dct(yyy);
    nn=length(yy);
    k=1;
    for i=k:nn
        zz(ll)=yy(k);
        ll=ll+1;
    end
end
disp(zz);

ll=length(zz);
for i=1:ll
    if zz(i)>=0
        bp(i)=1;
    else
        bp(i)=0;
    end
end
bp=int32(bp);
