//rom에서 data를 읽어와 그 값을 곱해주고 결과를 반환하는 모듈
module rom_multiplier (addr1, addr2, en1, en2, result);
    //8비트의 곱셈 결과는 최대 16비트까지 나올 수 있음
    parameter size = 8, longSize = size*2;
    //주소 1, 주소 2
    input[3:0] addr1, addr2;
    //en 신호가 들어올 때 그 결과를 읽어준다.
    input en1, en2;
    //16비트 결과
    output[longSize-1:0] result;
    //메모리에서 읽은 데이터를 받아줄 wire
    wire [size-1:0] opa, opb;
    reg [longSize-1:0] result;    
    reg [longSize-1:0] shift_opa, shift_opb;
    reg [7:0] rom1[15:0], rom2[15:0];
    //메모리에서 8비트 데이터를 읽어옴
    initial begin
        $readmemh("ROM1.mem", rom1);
        $readmemh("ROM2.mem", rom2);
    end
    //en 신호가 들어올 경우 값을 opa에 설정해줌
    assign opa = (en1) ? rom1[addr1] : 8'h00;
    assign opb = (en2) ? rom2[addr2] : 8'h00;

    always @(opa or opb) begin        
        shift_opa = opa;
        shift_opb = opb;
        result = 0;    
        //size 만큼 shift를 하면서 덧셈을 실행
        repeat (size) begin
            if (shift_opb[0]) begin
                result = result + shift_opa;
            end
            shift_opa = shift_opa << 1;
            shift_opb = shift_opb >> 1;
        end    
    end

endmodule