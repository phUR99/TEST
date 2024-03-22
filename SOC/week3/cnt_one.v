`ifndef __TEST_V__
`define __TEST_V__

module cnt_one(rega, count);
    input [3:0] rega;
    output [2:0] count;
    reg [3:0] temp_reg;
    reg [2:0] count;
    
    always @(rega) begin
        count    = 0;
        temp_reg = rega;
        while (temp_reg) begin
            if (temp_reg[0]) begin
                count = count +1;
            end
            temp_reg = temp_reg >> 1;
        end
    end
endmodule
    
 `endif /* __TEST_V__ */
