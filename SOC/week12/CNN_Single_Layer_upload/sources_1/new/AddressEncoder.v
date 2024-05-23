`timescale 1ns / 1ps

module AddressEncoder(AddrIn, AddrOut);
    
    input [14:0] AddrIn;
    output reg [3:0]AddrOut;
    
    // 코드 작성
    always @(*) begin
        case (AddrIn)
            15'b100_0000_0000_0000: AddrOut = 4'h0;
            15'b000_0000_0000_0001: AddrOut = 4'h1;
            15'b000_0000_0000_0010: AddrOut = 4'h2;
            15'b000_0000_0000_0100: AddrOut = 4'h3;
            15'b000_0000_0000_1000: AddrOut = 4'h4;
            15'b000_0000_0001_0000: AddrOut = 4'h5;
            15'b000_0000_0010_0000: AddrOut = 4'h6;
            15'b000_0000_0100_0000: AddrOut = 4'h7;
            15'b000_0000_1000_0000: AddrOut = 4'h8;
            15'b000_0001_0000_0000: AddrOut = 4'h9;
            15'b000_0010_0000_0000: AddrOut = 4'ha;
            15'b000_0100_0000_0000: AddrOut = 4'hb;
            15'b000_1000_0000_0000: AddrOut = 4'hc;
            15'b001_0000_0000_0000: AddrOut = 4'hd;
            15'b010_0000_0000_0000: AddrOut = 4'he;
            default: AddrOut = 0;
        endcase
    end

    
endmodule
