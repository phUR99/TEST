function [hidden_states, observed_states] = HMM(p)
    % length of observated states and hidden states
    T = 100;
    % make matrixes of hidden states and observed states
    hidden_states = zeros(1, T);
    observed_states = zeros(1, T);
    % State Transition Matrix
    A = [0.975, 0.025; 
         0.025, 0.975];
    % Measurement Matrix
    B = [1-p, p; 
         p, 1-p];
    % choose the 1st state of hidden states using init.state prob
    initial_state_prob = [1, 0];
    current_state = find(rand() <= cumsum(initial_state_prob, 1));
    
    % make hidden states and observed states
    for t = 1:T
        % Add current hidden state to hidden states
        hidden_states(t) = current_state;
        % Determine observed state based on current hidden state
        observed_state = find(rand() <= cumsum(B(current_state, :)), 1);
        % Choose the next hidden state
        current_state =  find(rand() <= cumsum(A(current_state, :)), 1);                     
        % Add the current observed state to the observed state sequence
        observed_states(t) = observed_state;
    end
    
end