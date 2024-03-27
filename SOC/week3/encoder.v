//들어오는 8비트를 3비트로 인코딩하는 인코더(casex문 활용)
module encoder (i, e);
    //input 8비트
    input[7:0] i;
    //output 8비트
    output[2:0] e;
    //reg로 선언
    reg [2:0] e;
    //i가 들어올 경우 always 구문이 시작
    always @(*) begin
        //lSB -> MSB로 진행하면서 만나는 1에 따라서 e를 결정하고 반환
        casex (i)
            8'bxxxxxxx1: e = 3'b000;
            8'bxxxxxx10: e = 3'b001;
            8'bxxxxx100: e = 3'b010;
            8'bxxxx1000: e = 3'b011;
            8'bxxx10000: e = 3'b100;
            8'bxx100000: e = 3'b101;
            8'bx1000000: e = 3'b110;
            8'b10000000: e = 3'b111;
            // 0일 경우에는 don't care를 반환
            default: e = 3'bxxx;
        endcase
    end

endmodule