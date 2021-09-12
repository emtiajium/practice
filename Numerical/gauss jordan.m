clear
row=input('input dimension');
for i=1:row
    for j=1:row
        arr(i,j)=input('input value ');
    end
    arrb(i)=input('input value ');
end
for i=1:row
    c=abs(arr(i,i));
    d=i;
    for j=i:row
        if abs(arr(j,i))>c
            c=abs(arr(j,i));
            d=j;
        end
    end
    if(c==0)
        break
    end
    for j=1:row
        e=arr(i,j);
        arr(i,j)=arr(d,j);
        arr(d,j)=e;
    end
    e=arrb(i);
    arrb(i)=arrb(d);
    arrb(d)=e;
    c=arr(i,i);
    e=(c-1)/c;
    for j=1:row
        arr(i,j)=arr(i,j)-e*arr(i,j);
    end
    arrb(i)=arrb(i)-e*arrb(i);
    c=arr(i,i);
    for j=1:row
        if(j==i)
            continue
        end
        d=arr(j,i)/c;
        for k=1:row
            arr(j,k)=arr(j,k)-d*arr(i,k);
        end
        arrb(j)=arrb(j)-d*arrb(i);
    end
    arr
end
if (c==0)
    disp('Not Possible')
else    
    b
end