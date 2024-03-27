function viterbi_path = viterbi_algorithm(y, p)

    % 2-state HMM
    % State Transition Matrix
    A = [0.975, 0.025; 
         0.025, 0.975];
    % Measurement Matrix
    B = [1-p, p; 
         p, 1-p];
    % initial probability, z1 = 0
    pi = [1, 0];
    delta_arr = zeros(2, 100);
    psai_arr = zeros(2, 100);
    delta_arr(:, 1) = [pi(1) * B(1, y(1)); pi(2) * B(2, y(1))];
    psai_arr(:, 1) = [1; 1];
    
    % forward direction
    for i = 2:100
        for j = 1:2
            delta_list = [delta_arr(1, i-1) * A(1, j) * B(j, y(i)); 
                          delta_arr(2, i-1) * A(2, j) * B(j, y(i))];
            [delta, psai] = max(delta_list);
            
            delta_arr(j, i) = delta;
            psai_arr(j, i) = psai;
        end
    end
    
    % backward direction
    viterbi_path = zeros(1, 100);
    [~, best_idx] = max(delta_arr(:, 100));
    for i = 100:-1:1
        viterbi_path(i) = best_idx;
        best_idx = psai_arr(best_idx, i);
    end
    
end