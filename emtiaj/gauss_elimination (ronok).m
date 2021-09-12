clear
m=input('Enter dimensions of the martix : ');
for i=1:m
    for j=1:m
        a(i,j)=input('Enter a value: ');
    end
    b(i)=input('Enter a value: ');
end

a
for i=1:m-1
    c=abs(a(i,i));
    d=i;
    for j=i:m
        if abs(a(j,i))>c
            c=abs(a(j,i));
            d=j;
        end
    end
    if(c==0)
        break
    end
    for j=1:m
        e=a(i,j);
        a(i,j)=a(d,j);
        a(d,j)=e;
    end
    e=b(i);
    b(i)=b(d);
    b(d)=e;
    c=a(i,i);
    for j=i+1:m
        d=a(j,i)/c;
        for k=1:m
            a(j,k)=a(j,k)-d*a(i,k);
        end
        b(j)=b(j)-d*b(i);
    end
end
if (c==0)
    disp('Not Possible')
else    
    a
    b
    for i=m:-1:1
        answer(i)=b(i);
        for j=i+1:m
            c=answer(j)*a(i,j);
            answer(i)=answer(i)-c;
        end
        answer(i)=answer(i)/a(i,i);
    end
    answer
end

        

