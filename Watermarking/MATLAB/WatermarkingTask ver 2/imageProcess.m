function val = imageProcess()

% clc;
% clear all;

I = imread('BN.jpg');
level = graythresh(I);
img = im2bw(I,level);
val = int64(img);

% 
% imshow(img);