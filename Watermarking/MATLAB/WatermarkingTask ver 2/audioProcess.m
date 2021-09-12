function B = audioProcess(array)

% clc;
% clear all;
% 

hartleyCoefficient = dht(array); % Heartley coefficients [dht.m]

primeNumbers = primeGenerate(); % Prime numbers [primeGenerate.m]

rowSize = 32; % Since image is 32 X 32
totalSample = 4194304; % discard values for mp3 compression
totalSampleInAframe = rowSize ^ 2;
totalFrame = floor(totalSample / totalSampleInAframe);

x = []; % For original audio it stores keys, and for attacked audio, watermark
temporaryArray = []; % To store each frame values
temporaryArray2 = []; % To store each frame values in a matrix
temporaryArray3 = []; % To store weight matrix in 1-D array

initial = 1;
final = int32(totalFrame);
% Each frame contains 4096 samples

for i = 1:1024
    index = 1;
    for j = initial:final
        temporaryArray(index) = abs(hartleyCoefficient(j));
        index = index + 1;
    end
    initial = final + 1;
    final = initial + totalFrame - 1;
    % First time 1 to 4096, second time 4097 to ....
    % Now to convert in a matrix of size 64 X 64
    xyz = int32(sqrt(index - 1)); % square root of 4096 = 64;
    temporaryArray2 = reshape(temporaryArray, xyz, xyz);
    
    [W, H] = nnmf(temporaryArray2, 8); % 64X64 = 64X8 X 8X64
%     The sub-matrix W contains the NMF basis; 
%     the sub-matrix H contains the associated coefficients (weights).
%     Sometimes the algorithm converges to a solution of lower rank than k,
%     which may indicate that the result is not optimal. # Here k=8;
    
    totalWeightMatrixElements = numel(H);
    temporaryArray3 = reshape(H,1,totalWeightMatrixElements); % 1-D array
    
    total = 0;
    for j = 1:totalWeightMatrixElements
        total = total + temporaryArray3(j);
    end
    total = double(total); % Just did sum of each weighted matrix
    
    yfoo = total- floor(total);
    fractionPart = str2num(strrep(num2str(yfoo),'.',''));
    fractionPart=int32(fractionPart); % extract fraction part
    
    if fractionPart == 0
        fractionPart = 1;
    end
    if fractionPart > 9592
        fractionPart = 9592;
    end
    
    aPrimeNumber = primeNumbers(fractionPart);
    
    modResult = bigmod(fractionPart, aPrimeNumber, 2);
    
    x(i) = modResult;
end

B = reshape(x, rowSize, rowSize);
B = int64(B);
% disp(B);