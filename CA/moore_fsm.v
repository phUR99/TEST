`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/04/30 21:02:42
// Design Name: 
// Module Name: moore_fsm
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module moore_fsm(
    input clk, rst, bypass,
    output reg[1:0] out
    );
    parameter ST0 = 2'b00,
              ST1 = 2'b01,
              ST2 = 2'b10,
              ST3 = 2'b11;
    reg[1:0] state, next;
    always @(posedge clk or negedge rst) begin 
        if(!rst) state <= ST0;
        else state <= next;
    end    
    
    always @(state or bypass) begin
        next = 2'bx;
        case(state)
            ST0 : next = ST1;
            ST1 :  if(bypass) next = ST3;
                   else  next = ST2;
            ST2 : next = ST3;
            ST3 : next = ST0; 
         endcase 
    end
    always @(posedge clk or negedge rst) begin 
           assign out = state;  
    end
endmodule

module mealy_fsm(clk, rst, din_bit, dout_bit);
    input clk, rst, din_bit;
    output dout_bit; reg[2:0] state, next;        
    parameter       start =3'b000,st1=3'b001,st2=3'b010,st3=3'b011,st4=3'b100; 
    always @(posedge clk or negedge rst) begin
        if(rst ==0) state <= start; else state <= next;        
    end
    always @(state or din_bit) begin
        next= 3'bx;
        case(state)
            start : if (din_bit==0) next = st1;
                    else if (din_bit==1) next = start; else next = start;                                      
            st1   : if (din_bit==0) next = st1;
                    else if (din_bit==1) next = st2; else next = start;                                      
            st2   : if (din_bit==0) next = st1;
                    else if (din_bit==1) next = st3; else next = start;                                     
            st3   : if (din_bit==0) next = st4;
                    else if (din_bit==1) next = start; else next = start;                                     
            st4   : if (din_bit==0) next = st1;
                    else if (din_bit==1) next = st2; else next = start;
                    
            default next =state;
          endcase         
    end    
       assign dout_bit = (next == st4 & din_bit==0) ? 1 : 0;
 endmodule 
