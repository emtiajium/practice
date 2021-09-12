function r=bigmod(b,p,m)

b=int64(b);
p=int64(p);
m=int64(m);

r=1;
b=mod(b,m);

while p~=0
    c = bitand(p,1);
    if c~=0
        r=mod(r*b,m);
    end
    b=mod(b*b,m);
    p=bitsra(p,1);
end

end
