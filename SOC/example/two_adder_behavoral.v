module adder(x, y, cin, sum, cout);

input [3:0] x, y;
input cin;
//always 구문 내에 들어가는 lvalue 에는 reg가 들어가야 함.
output reg[3:0] sum;
output reg cout;
reg [3:0] t;

always @(*) begin
    // 비트 연산은 비트 수를 맞춰줘야 함.    
    t= y ^{4{cin}};
    {cout, sum} = x + t + cin;
end
    
endmodule