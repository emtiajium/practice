% function nc=nccal(p,q)

clc;
clear all;

p=110763130256;
q=110763043796;

x=decimalToBinaryVector(p);
% disp(x);

y=decimalToBinaryVector(q);
% disp(y);


high=max(length(x),length(y));

i=1;
while i<1e100
    j=i^2;
    if j>=high
        break;
    end
    i=i+1;
end

lensx=j-length(x);
lensy=j-length(y);

zx=[];
zy=[];

for i=1:lensx
    zx(i)=0;
end

i=1;
z=length(x)+lensx;
for j=lensx+1:z
    zx(j)=x(i);
    i=i+1;
end

for i=1:lensy
    zy(i)=0;
end
i=1;
z=length(y)+lensy;
for j=lensy+1:z
    zy(j)=y(i);
    i=i+1;
end

len=length(zx);
len=int32(sqrt(double(len)));

a = reshape(zx,len,len);
b = reshape(zy,len,len);

% a=[2,3;6,7];
% b=[1,5;10,20];

m=size(a);
n=size(b);
a1=mean2(a);
b1=mean2(b);
p1=0;p2=0;p3=0;
for i=1:m
    for j=1:n
        g=a(i,j)-a1;
        h=b(i,j)-b1;
        p1=p1+g*h;
        p2=p2+g^2;
        p3=p3+h^2;
    end
end
r=sqrt(double(p2));
s=sqrt(double(p3));

nc=double(p1)/r/s;
disp(nc);

%% Comparison with bulit-in function

val = normxcorr2(a,b);
[max_cc, imax] = max(abs(val(:)));
disp(max_cc);
