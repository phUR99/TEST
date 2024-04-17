module  MinMaxFinder(
    ReadDataEven, ReadDataOdd, clk, Start, min, Max, Vaild
);
    input [15:0] ReadDataEven, ReadDataOdd;    
    input clk;
    input Start;
    output reg Vaild;
    output reg[15:0] min, Max;
    integer cnt;

    wire [15:0] tmp_min, tmp_max;
    assign tmp_min = (ReadDataEven < ReadDataOdd) ? ReadDataEven : ReadDataOdd;
    assign tmp_max = (ReadDataEven > ReadDataOdd) ? ReadDataEven : ReadDataOdd;


    always @(posedge clk) begin
        if(!Start) begin
            min <= 16'hffff;
            Max <= 16'h0000;
            Vaild <= 0;
            cnt <= 0;
        end   
        else begin                          
            min <= (tmp_min < min) ? tmp_min : min;
            Max <= (tmp_max > Max) ? tmp_max : Max;            
            if(cnt == 4) begin                
                Vaild <= 1;    
            end            
            else begin                                                     
                Vaild <= 0;
            end
            cnt <= cnt + 1;     
        end    
    end


endmodule