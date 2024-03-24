`ifndef __TEST_V__
`define __TEST_V__

module encoder (i, e);
    input[7:0] i;
    output[2:0] e;
    reg [2:0] e;

    always @(*) begin
        casex (i)
            8'bxxxxxxx1: e = 3'b000;
            8'bxxxxxx10: e = 3'b001;
            8'bxxxxx100: e = 3'b010;
            8'bxxxx1000: e = 3'b011;
            8'bxxx10000: e = 3'b100;
            8'bxx100000: e = 3'b101;
            8'bx1000000: e = 3'b110;
            8'b01000000: e = 3'b111;
            default: e = 3'bxxx;
        endcase
    end

endmodule

 `endif /* __TEST_V__ */