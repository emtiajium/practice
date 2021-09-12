clear
a(1,1)=input('Enter a1: ');
a(1,2)=input('Enter b1: ');
a(1,3)=input('Enter c1: ');
a(1,4)=input('Enter d1: ');
a(2,1)=input('Enter a2: ');
a(2,2)=input('Enter b2: ');
a(2,3)=input('Enter c2: ');
a(2,4)=input('Enter d2: ');
a(3,1)=input('Enter a3: ');
a(3,2)=input('Enter b3: ');
a(3,3)=input('Enter c3: ');
a(3,4)=input('Enter d3: ');
ACC=0.0001;
if ( (abs(a(1,1))>abs(a(1,2))+abs(a(1,3))) && (abs(a(2,2))>abs(a(2,1))+abs(a(2,3))) && (abs(a(3,3))>abs(a(3,1))+abs(a(3,2))))
    prevx=0;
    prevy=0;
    prevz=0;
    x=0;
    y=0;
    z=0;
    while(1)
        x=(a(1,4)-a(1,2)*y-a(1,3)*z)/a(1,1);
        y=(a(2,4)-a(2,1)*x-a(2,3)*z)/a(2,2);
        z=(a(3,4)-a(3,1)*x-a(3,2)*y)/a(3,3);
        if(abs(x-prevx)<ACC && abs(y-prevy)<ACC && abs(z-prevz)<ACC)
            break;
        end
        prevx=x;
        prevy=y;
        prevz=z;
    end
    x
    y
    z
else
    disp('Not possible');
end