function [Xpos, Ypos] = SimpleKalman(z,r)
%
%
persistent A H Q R 
persistent x P
persistent firstRun


if isempty(firstRun)
  %4X4  
  A = [1, 0, 0.5, 0
       0, 1, 0, 0.5
       0, 0, 1, 0
       0, 0, 0, 1];
  %2X4  
  H = [1, 0, 0, 0
       0, 1, 0, 0];
  
  Q = eye(4);
  %2X2  
   
  R = r*eye(2);
  
  %4X1
  x = [3 0 1 0]';
  %4X4
  P = eye(4);
  firstRun = 1;  
end
 
  
xp = A*x;
Pp = A*P*A' + Q;

K = Pp*H'*inv(H*Pp*H' + R);

x = xp + K*(z' - H*xp);
P = Pp - K*H*Pp; 


Xpos = x(1);
Ypos = x(2);
end