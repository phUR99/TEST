initloc= [3 0];
initstate = [3 0 1 0];

F = [1, 0, 0.5, 0
     0, 1, 0, 0.5
     0, 0, 1, 0
     0, 0, 0, 1];
% make a matrix that length is 100X1;
t  = 1:1:100;
%1X2 matrix(location of Anchor);

A1=[0, 0]; A2=[10, 10]; A3=[0, 10];

%give a noise to observation;
n1=randn(length(t),1)*0.3;
n2=randn(length(t),1)*0.3;
n3=randn(length(t),1)*0.3;

%give a noise to model
w = randn(length(t), 4);

% matrix of real (x,y);
Xstatesaved = zeros(length(t), 1);
Ystatesaved = zeros(length(t), 1);

%inverse matrix of observation;
distance = [2*(A2(1,1)-A1(1,1)), 2*(A2(1,2)-A1(1,2)) 
            2*(A3(1,1)-A2(1,1)), 2*(A3(1,2)-A2(1,2))];

%matrix of observation (x,y);
Xprediction=zeros(length(t),1); 
Yprediction=zeros(length(t),1); 
%matrix of using kalmanfilter (x,y);
Xpredictionusingfilter=zeros(length(t),1); 
Ypredictionusingfilter=zeros(length(t),1); 


for k=1:length(t)
    
    if (k==1)
    nextstate = F*(initstate')+w(k, :)';
    
    Xstatesaved(k) = nextstate(1,1);
    Ystatesaved(k) = nextstate(2,1);

    r1=norm(A1-[Xstatesaved(k) Ystatesaved(k)])+n1(k);
    r2=norm(A2-[Xstatesaved(k) Ystatesaved(k)])+n2(k);
    r3=norm(A3-[Xstatesaved(k) Ystatesaved(k)])+n3(k);

    % r1^2-r2^2-x1^2+x2^2-y1^2+y2^2
    c = power(r1,2)-power(r2,2)-power(A1(1,1),2)+power(A2(1,1),2)-power(A1(1,2),2)+power(A2(1,2),2);
    % r2^2-r3^2-x2^2+x2^2-y1^2+y2^2
    f = power(r2,2)-power(r3,2)-power(A2(1,1),2)+power(A3(1,1),2)-power(A2(1,2),2)+power(A3(1,2),2);

    predict = inv(distance)*[c f]';

    Xprediction(k)= predict(1,1);
    Yprediction(k)= predict(2,1); 

    else

    nextstate = F*(nextstate)+ w(k, :)';    
    Xstatesaved(k) = nextstate(1,1);
    Ystatesaved(k) = nextstate(2,1);

    r1=norm(A1-[Xstatesaved(k) Ystatesaved(k)])+n1(k);
    r2=norm(A2-[Xstatesaved(k) Ystatesaved(k)])+n2(k);
    r3=norm(A3-[Xstatesaved(k) Ystatesaved(k)])+n3(k);
    % r1^2-r2^2-x1^2+x2^2-y1^2+y2^2
    c = power(r1,2)-power(r2,2)-power(A1(1,1),2)+power(A2(1,1),2)-power(A1(1,2),2)+power(A2(1,2),2);
    % r2^2-r3^2-x2^2+x2^2-y1^2+y2^2
    f = power(r2,2)-power(r3,2)-power(A2(1,1),2)+power(A3(1,1),2)-power(A2(1,2),2)+power(A3(1,2),2);
    predict = inv(distance)*[c f]';

    Xprediction(k)= predict(1,1);
    Yprediction(k)= predict(2,1);

    end
end

measureError = zeros(1000,1);


for i=1:1000
    clear SimpleKalman;
    for k=1:length(t)
        [Xpredictionusingfilter(k), Ypredictionusingfilter(k)]=SimpleKalman([Xprediction(k),Yprediction(k)],i);
 
    end
    dis=format("long");
    dis =0;
    for k=1:length(t)

        dis=dis+1/1000*power(norm([Xstatesaved(k),Ystatesaved(k)]-[Xpredictionusingfilter(k), Ypredictionusingfilter(k)]),2);    
    end
    measureError(i) = dis;
end
[r,j]= find(measureError==min(measureError));
clear SimpleKalman;
    for k=1:length(t)
        [Xpredictionusingfilter(k), Ypredictionusingfilter(k)]=SimpleKalman([Xprediction(k),Yprediction(k)],r);
 
    end

plot(Xstatesaved, Ystatesaved, 'o-'); grid
hold on
plot(Xprediction, Yprediction, 'r-+')
hold on
plot(Xpredict)
hold off