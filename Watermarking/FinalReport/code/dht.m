function output=dht(arr)

n = length(arr);

for k = 0 : n - 1
    s = 0;
    for t = 0 : n - 1  
        x = 2 * pi * t * k / n;
        s = s + arr(t + 1) * (cos(x) + sin(x));
    end
    output(k + 1) = s;
end
