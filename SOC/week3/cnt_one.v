`ifndef __TEST_V__
`define __TEST_V__

module cnt_one(rega, count);
    input [7:0] rega;
    output [3:0] count;
    reg [7:0] temp_reg;
    reg [3:0] count;
    
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
