function nc=ncber(a,b)

m=size(a);
n=size(b);
p1=0;p2=0;p3=0;
for i=1:m
    for j=1:n
        p1=p1+a(i,j)*b(i,j);
        p2=p2+a(i,j)^2;
        p3=p3+b(i,j)^2;
    end
end

rr=sqrt(double(p2));
ss=sqrt(double(p3));

nc=double(p1)/rr/ss;
disp(nc);

coun=0;
for i=1:m
    for j=1:n
        if a(i,j)~=b(i,j)
            coun=coun+1;
        end
    end
end
zz=coun/m(1)/n(1);
disp(zz);
