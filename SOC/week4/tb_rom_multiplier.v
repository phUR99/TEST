module tb_rom_multipier;
    reg[3:0] addr1, addr2;
    reg en1, en2;
    wire [15:0] data;
    
    rom_multiplier uut(addr1, addr2, en1, en2, data);
    //100 이후 en1와 en2를 설정
    initial begin
        addr1 = 4'd0;
        addr2 = 4'd0;
        en1 = 1'b0;
        en2 = 1'b0;
        #100 
        en1 = 1'b1;
        en2 = 1'b1;
    end 
    //주소를 20마다 증가시켜줌
    always begin
        #20
        addr1 = addr1 + 4'd1;
        addr2 = addr2 + 4'd2;
    end


endmodule