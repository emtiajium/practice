function val=imageP()

I = imread('HB.png');
level = graythresh(I);
img = im2bw(I,level);
val=int64(img);

end