//8비트 카운터 (while문 이용해서 구현)
module cnt_one(rega, count);
    //input
    input [7:0] rega;
    //output
    output [3:0] count;
    //output의 현재 값을 담아줄 reg
    reg [7:0] temp_reg;
    //count를 reg로 선언해서 값을 저장하게 했다.
    reg [3:0] count;
    
    always @(rega) begin
        //count를 0으로 초기화
        count    = 0;
        //temp_reg를 rega로 초기화
        temp_reg = rega;
        //temp_reg가 0이라면 종료하는 while 구문
        while (temp_reg) begin
            //temp_reg[0]가 0이 아니라면 
            if (temp_reg[0]) begin
                //count에 1을 더해준다.
                count = count +1;
            end
            //temp_reg를 1비트 오른쪽으로 shift한다.
            temp_reg = temp_reg >> 1;
        end
    end
endmodule
