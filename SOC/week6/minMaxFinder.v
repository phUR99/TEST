module  MinMaxFinder(
    ReadDataEven, ReadDataOdd, clk, Start, min, Max, Vaild
);
    input [15:0] ReadDataEven, ReadDataOdd;    
    input clk;
    input Start;
    output Vaild;
    output reg[15:0] min, Max;
    
    reg [5:0] cnt;
    wire [15:0] tmp_min, tmp_max;
    // cnt의 6번째 비트를 vaild로 한다.
    assign Vaild = cnt[5];
    // 둘 중 의 최대 최소를 tmp_min과 tmp_max로 받는다.
    assign tmp_min = (ReadDataEven < ReadDataOdd) ? ReadDataEven : ReadDataOdd;
    assign tmp_max = (ReadDataEven > ReadDataOdd) ? ReadDataEven : ReadDataOdd;


    always @(posedge clk) begin
        // start가 들어오지 않으면 초기화
        if(!Start) begin
            min <= 16'hxxxx;
            Max <= 16'hxxxx;            
            cnt <= 1;
        end   
        // 초기값일 경우에는 min과 max를 비교하지 않고 바로 넘어간다
        // 아닐 경우에는 tmp_min과 min을 비교하고 둘 중 작은값으로
        // tmp_max와 max를 비교하고 둘 중 큰값으로 정한다.
        // cnt를 1비트 shift한다.
        else begin                          
            min <= (cnt == 1) ? tmp_min : (tmp_min < min) ? tmp_min : min;
            Max <= (cnt == 1) ? tmp_max : (tmp_max > Max) ? tmp_max : Max;
            cnt <= cnt << 1;
        end    
    end


endmodule