module operation;

parameter delay = 10;
reg[15:0] a, b;
reg[15:0] op1, op2, op3;

always @(a or b) bitwise_oper(op1, op2, op3, a, b);

task automatic bitwise_oper;

output [15:0] ab_and, ab_or, ab_xor;

input [15:0] a, b;

begin
    #delay
    ab_and = a & b;
    ab_or = a | b;
    ab_xor = a ^ b;
end    

endtask

function  calc_parity;
input[31:0] address;
begin
    calc_parity = ^address;
end            
endfunction

function automatic [15:0] fact;
input[7:0] N;

if (N==1) begin
    fact = 1;
end
else fact = N* fact(N-1);
endfunction


endmodule