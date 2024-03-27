A = zeros(9, 2);
B = transpose(A);
C = A * B;
%pseudo inverse matrix
D = pinv([
        1, 0;
        1, 0;
        1, 0;
]);

AP1 = [
    0 , 0;
    0, 20;
    20, 0;
];
AP2 = [
    0 , 0;
    0, 20;
    20, 0;
    20, 20;
];
AP3 = [
    0 , 0;
    0, 20;
    20, 0;
    20, 20;
    15, 25;
];
MS = [8, 9];
