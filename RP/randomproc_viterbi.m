clear;clc;
Aver_of_1st=zeros(1,10);Aver_of_2nd=zeros(1,10);Aver_of_3rd=zeros(1,10);
%p=0.01
for j=1:10
    errorNum1=0;
    for i=1:1000
        [hidden_states, observed_states] = HMM(0.01);
        decoded_states = viterbi_algorithm(observed_states, 0.01);
        %disp(sum(hidden_states==decoded_states)/100);
        for k=1:100
            if (hidden_states(1,k)~=decoded_states(1,k))
                errorNum1 = errorNum1+1;
                break;
            end    
        end     
        
    end
    errorProb1 = errorNum1*0.001;
    Aver_of_1st(j)=errorProb1;
end

%p=0.05
for j=1:10
    errorNum2=0; 
    for i=1:1000
        [hidden_states, observed_states] = HMM(0.05);
        decoded_states = viterbi_algorithm(observed_states, 0.05);
        %disp(sum(hidden_states==decoded_states)/100);
        for k=1:100
            if (hidden_states(1,k)~=decoded_states(1,k))
                errorNum2 = errorNum2+1;
                break;
            end    
        end    
    end
    errorProb2 = errorNum2*0.001;
    Aver_of_2nd(j)=errorProb2;
end    
%p=0.1
for j=1:10
    errorNum3=0;
    for i=1:1000
        [hidden_states, observed_states] = HMM(0.1);
        decoded_states = viterbi_algorithm(observed_states, 0.1);
        %disp(sum(hidden_states==decoded_states)/100);
        for k=1:100
            if (hidden_states(1,k)~=decoded_states(1,k))
                errorNum3 = errorNum3+1;
                break;
            end    
        end     
    end
    errorProb3 = errorNum3*0.001;
    Aver_of_3rd(j)=errorProb3;
end

% display on console
disp("average of probAverage of p =0.01:");disp(mean(Aver_of_1st));
disp("average probAverage of p =0.05:");disp(mean(Aver_of_2nd));
disp("average of probAverage of p =0.1:");disp(mean(Aver_of_3rd));
