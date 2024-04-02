
AP = [
    0, 0;
    0, 20;
    20, 0;
    20, 20;
    15, 25;
];
MS = [8, 9];
trial_size = 100;


for i = 1 : 3 
    A = AP(1:i+2, :);  
    scatter_data = zeros(trial_size, 2);
    figure;
    for j = 1 : trial_size
        K = sum(A.^2, 2);
        R = (MS  - A).^2;        
        R = sum(R, 2);   
        R = (sqrt(R) + randn(size(R))).^2;             
        pointZero = R(1);
        H = A(2:end,  :);
        R = R(2:end);
        K = K(2:end);
        pH = pinv(H);
        b = (K - R + pointZero) / 2;
        xhat = pH*b;        
        scatter_data(j, :) = xhat';

    end
    subplot(1, 3, 1)
    plot(MS(1), MS(2), 'bx'); hold on
    scatter(scatter_data(:,1), scatter_data(:,2), 'ro'); 
    xlabel('X 좌표'); 
    ylabel('Y 좌표');    
    title (['앵커가 ', num2str(i+2) '개 일 때 추정 위치, 시도 횟수 : ', num2str(trial_size)]);

    error_scatter = sqrt(sum((scatter_data - MS).^2, 2));       
    subplot(1, 3, 2)
    plot(error_scatter);
    xlabel('시도 순서');     
    title ('거리 오차의 값');
     
    subplot(1, 3, 3)
    histogram(error_scatter, 'BinEdges', min(error_scatter):0.25:max(error_scatter));
    %swarmchart(error_scatter);
    xlabel('오차의 거리');     
    ylabel('빈도');
    title('오차 거리의 빈도의 히스토그램');

end

