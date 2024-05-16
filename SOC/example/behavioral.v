module adder (
    x, y, cin,
    sum, cout
);
input [3:0] x, y;
input cin;
output [3:0] sum;
output cout;

reg [3:0] sum, t;
reg cout;

always @(x, y, cin) begin
    t = y ^ {4{cin}};
    {cout, sum} = x + t + cin;
end

endmodule

module FF (
    q, din, clk, rst
);
    input din, clk, rst;
    output reg q;
    
always @(posedge clk or negedge rst) begin
    if (rst == 0) q <= 0;
    else q <= din;
end    

endmodule

module MUX4to1 (
    i0, i1, i2, i3,
    s1, s0,
    out
);
input i0, i1, i2, i3, s1, s0;
output reg out;

always @(i0 or i1 or i2 or i3 or s0 or s1)
begin
    case ({s1, s0})
        2'b00 : out = i0;
        2'b01 : out = i1;
        2'b10 : out = i2;
        2'b11 : out = i3;        
        default: out = 1'bx;        
    endcase
end    
endmodule

module DECODER3_6 (
    a, en, y
);
input en;
input [3:0] a;
output [5:0] y;

reg [5:0] y;
always @(en or a)
    begin
       case({en, a}) 
        4'b1000 : y = 6'b000001;
        4'b1001 : y = 6'b000010;
        4'b1010 : y = 6'b000100;
        4'b1011 : y = 6'b001000;
        4'b1100 : y = 6'b010000;
        4'b1101 : y = 6'b100000;
        default : y = 6'b0;
       endcase
    end

endmodule

module xyz (
    din, dout
);
input [1:0] din;
output reg[3:0] dout;

always @(din) begin
    dout = {{3{1'b0}}, 1'b1} << din;
end
endmodule

module customCounter (
    data, out
);
input [7:0] data;
output reg out;
reg [3:0] sum;

always @(data) begin
    sum = data[7] + data[6] + data[5] + data[4] + data[3] + data[2] + data[1] + data[0];
    if (sum > 4) out = 1'b1;
    else out = 1'b0;
end

endmodule

module FFwithComb (
    clk, a, b, c, d, e, y
);
input clk;
input a, b, c, d , e;
output y;

reg m, n;
reg y;
always @(c or d) n = c | d;

always @(posedge clk)
    begin
        m <= !(a&b);
        y <= !(n |m |e);
    end

endmodule

module example_dff (
    clk, x1, x2, x3, f, g
);
input clk;
input x1, x2, x3;
output reg f, g;

always @(posedge clk) begin
    f <= (x1 & x2);
    g <= (x3 | f );
end

endmodule

module rom (
    address, data, read_en, ce
);
input [7:0] address;
output [7:0] data;
input read_en;
input ce;
reg[7:0] mem[0:255];

assign data =(ce && read_en) ? mem[address] : 8'b0;

endmodule

module ram (
    clk,
    address,
    data,
    cs,
    we,
    oe
);

parameter data_width = 8;
parameter addr_width = 8;
parameter ram_width = 8;

input clk;
input [addr_width-1 :0] address;
input cs;
input we;
input oe;

inout [data_width-1:0] data;

reg[data_width-1:0] data_out;
reg[data_width-1:0] mem[0:ram_width-1];

assign data = (cs && oe && !we) ? data_out : 8'bz;

always @(posedge clk) begin : MEM_WRITE
    if(cs && we) mem[address]  = data;
end

always @(posedge clk) begin : MEM_READ

    if(cs && !we && oe) data_out = mem[address];
end

endmodule