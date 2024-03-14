`timescale 1ns / 1ps


// seq. ckt blk1
// 순차회로 or latch를 모델링하는 always -> nonblocking 
// 조합논리회로를 모델링하는 always -> blocking 
module blk1(clk, d, q3); 
    input clk;
    input d;
    output q3;
    reg q0, q1, q2, q3;
    //동일한 always block에서 순차회로와 조합논리회로를 함께 표현하는 경우에는 nonblocking 할당문 활용
    always @(posedge clk) begin //다수의 always block에서 동일한 reg 변수에 값을 할당하지 않는다
    q0 = d; //blocking 구문을 이용해서 값을 update하는 형태
    q1 = q0;
    q2 = q1;
    q3 = q2;
    end
 
endmodule
// seq. ckt blk2
// 
module blk2(clk, d, q3);
    input clk;
    input d;
    output q3;
    reg q0,q1,q2,q3;
    always @(posedge clk) begin
    q3 =q2;
    q2 =q1;
    q1 =q0;
    q0 =d;
    end

endmodule






//seq. ckt non_blk1(clk,d,q3);
module non_blk1(clk, d, q3);
    input clk;
    input d;
    output q3;
    reg q0,q1,q2,q3;
    
    always @(posedge clk) begin
    q0 <= d; 
    q1 <= q0;
    q2 <= q1;
    q3 <= q2;
    end
 endmodule 
 
 
 
 
 
 
 
 
 module non_blk2(clk, d, q3);
    input clk;
    input d;
    output q3;
    reg q0,q1,q2,q3;
    
    always @(posedge clk) begin
    q3 <=q2;
    q2 <=q1;
    q1 <=q0;
    q0 <=d;
    end
 endmodule 
