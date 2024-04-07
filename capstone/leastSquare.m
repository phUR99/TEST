%앵커의 개수에 따른 RMSE 구해보기
%RMSE 구해서 plot으로 추가하기
AP = [
    0,   0;
    0,  20;
    20,  0;
    20, 20;
    15, 25;
     
];
MS = [8, 9];
trial_size = 10000;
RMSE = zeros(3, 1); 
for i = 3 : 5 
    A = AP(1:i, :);  
    scatter_data = zeros(trial_size, 2);
    figure;
    for j = 1 : trial_size
        K = sum(A.^2, 2);
        R = (MS  - A).^2;        
        R = sum(R, 2);   
        R = (sqrt(R) + randn(size(R))).^2;             
        pointZero = R(1);        
        R = R(2:end);
        K = K(2:end);
        H = A(2:end,  :);
        pH = (transpose(H) * H) \ transpose(H);
        b = (K - R + pointZero) / 2;
        xhat = pH*b;        
        scatter_data(j, :) = xhat';

    end
    subplot(1, 3, 1)
    plot(MS(1), MS(2), 'bx'); hold on
    scatter(scatter_data(:,1), scatter_data(:,2), 'ro'); 
    xlabel('X 좌표'); 
    ylabel('Y 좌표');    
    title (['앵커가 ', num2str(i) '개 일 때 추정 위치, 시도 횟수 : ', num2str(trial_size)]);
    grid on;

    error_scatter = sqrt(sum((scatter_data - MS).^2, 2));       
    subplot(1, 3, 2)
    plot(error_scatter);
    xlabel('시도 순서');     
    title ('거리 오차의 값');
    grid on;

    subplot(1, 3, 3)
    pd = fitdist(error_scatter, 'Kernel', 'Kernel', 'normal');  
    x_values = linspace(min(error_scatter), max(error_scatter), 100);
    plot(x_values, pdf(pd, x_values), 'LineWidth', 2);
    xlabel('오차의 거리');
    ylabel('밀도');
    title(['앵커가 ', num2str(i), '개 일 때의 오차 거리 분포']);
    grid on;
    RMSE(i-2) = sqrt(mean(sum((scatter_data - repmat(MS, trial_size, 1)).^2, 2)));
end  

figure
plot(3:5, RMSE, '-o', 'LineWidth', 2);
xlabel('앵커 개수');
ylabel('RMSE');
title('앵커 개수에 따른 RMSE');
text(3:5, RMSE, num2str(RMSE, '%.4f'), 'HorizontalAlignment','left', 'VerticalAlignment','bottom');
grid on;
