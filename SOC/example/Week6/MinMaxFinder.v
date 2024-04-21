`timescale 1ns / 1ps

module MinMaxFinder(
clk,
rst,
Start,
ReadDataEven,
ReadDataOdd,
Max,
Min,
Valid
    );
    input clk;
    input rst;
    input Start;
    input [15:0] ReadDataEven;
    input [15:0] ReadDataOdd;
    output reg Valid;
    output reg [15:0] Min;
    output reg [15:0] Max;
    
    reg [15:0] bigger;
    reg [15:0] smaller;
    reg [2:0] count;
    wire en;
    reg postStart;



    always @(posedge clk or negedge rst) begin 
       if(!rst) 
          postStart <= 0;
       else
          postStart <= Start;
    end 
    assign en = (Start && (!postStart))? 1:0; //en: the first cycle of Start


    always @(posedge clk or negedge rst) begin 
       if(!rst)  
           count <= 0;
       else begin
            if (Start) count <= count + 1;
       end
    end 


   always @(*) begin //check1: input pair check
        if (ReadDataEven < ReadDataOdd) begin
            bigger  = ReadDataOdd;
            smaller = ReadDataEven;
        end
        else begin
            bigger  = ReadDataEven;
            smaller = ReadDataOdd;
        end
   end

   always @(posedge clk or negedge rst) begin //check2: compare to previous value
      if(!rst)  begin
            Min <= 16'hFF;
            Max <= 16'h0;
      end
      else begin
        if (en) begin //����
            Min <= smaller;
            Max <= bigger;       
        end
        else if (count) begin
	    if(smaller < Min) Min <= smaller;
	    if(bigger  > Max) Max <= bigger;
        end
    end
end
    

    always @(posedge clk or negedge rst) begin //4 times comparison--> done
       if(!rst) 
          Valid <= 0;
       else
          if (count == 4) Valid <= 1;
          else            Valid <= 0;
    end 
    
   
endmodule
