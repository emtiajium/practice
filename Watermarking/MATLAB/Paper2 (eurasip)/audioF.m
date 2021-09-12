function key3=audioF(arr)

% clc;
% clear all;

I = imread('H.png');
level = graythresh(I);
img = im2bw(I,level);
wtr=int32(img);

% z = 'C:\Users\Emtiaj\Documents\MATLAB\Sound\molten.wav';
% [arr, fs] = wavread(z);
n=length(arr);

% n=1024;
r=512;
smpl=n;
frame=floor(double(smpl/r));

l=1;
inl=1;
finl=512;
for i=1:frame
    m=1;
    for j=inl:finl
        F(l,m)=arr(j);
        m=m+1;
    end
    inl=finl+1;
    finl=finl+512;
    tot=0;
    for k=1:512
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
    for j=1:512
        t=F(i,j);
        F(i,j)=F(xx,j);
        F(xx,j)=t;
    end
end

T=int32(frame/16);

for i=1:T
    key1(i)=i;
end

for i=1:T
    for j=1:512
        x(j)=F(i,j);
    end
    [C,D]=wavedec(x,3,'db1');
    for j=1:D(1)
        yyy(j)=C(j);
    end
    yy=dct(yyy);
    P=yy;
    cum(i)=mean(P.^4)-4*mean(P)*mean(P.^3)-3*mean(P.^2)^2+12*mean(P)^2*mean(P.^2)-6*mean(P)^4;
end

[B,I]=sort(abs(cum),'descend');
P=int32((32*32)/T);

dd=[];
for i=1:P
    dd(i)=cum(i);
    key2(i)=I(i);
end

bp=[];
for i=1:P
    if dd(i)>=0
        bp(i)=1;
    else
        bp(i)=0;
    end
end
bp=int32(bp);

key3=[];
coun=1;
for k=1:T
    for p=1:P
        i=int32(floor(double((k*p+P)/32)));
        i=int32(mod(i,32));
        j=int32(mod(k*p+P,32));
        key3(coun)=bitxor(bp(p),wtr(i+1,j+1));
        coun=coun+1;
    end
end

key3=reshape(key3,32,32);
