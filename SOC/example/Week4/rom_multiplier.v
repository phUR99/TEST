`timescale 1ns / 1ps

module rom_multiplier(addr1, addr2, en1, en2, result);
   parameter SIZE = 8, LongSize = 2*SIZE;
   
   input [3:0] addr1, addr2;
   input en1, en2;
   output [LongSize-1:0] result;
   reg [LongSize-1:0] result;
   wire [SIZE-1:0] opa, opb;
   reg [SIZE-1:0] shift_opa, shift_opb;
   reg [7:0] rom1 [15:0];
   reg [7:0] rom2 [15:0];
   
   initial begin
        $readmemh("rom1.mem",rom1);
        $readmemh("rom2.mem",rom2);
   end
   
    assign opa = en1 ? rom1[addr1] : 8'h00;
    assign opb = en2 ? rom2[addr2] : 8'h00;
    
   
   always @(opa or opb) begin
   shift_opa = opa;
   shift_opb = opb;
   result = 0;
       repeat(SIZE) begin
            if(shift_opb[0])
                result = result + shift_opa;
            
            shift_opa = shift_opa <<1;
            shift_opb = shift_opb >>1; 
       end
   end
endmodule
