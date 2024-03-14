`timescale 1ns / 1ps


module Memory(
    input reset, clk,
    
    input Ctl_MemtoReg_in, Ctl_RegWrite_in, Ctl_MemRead_in, Ctl_MemWrite_in, Ctl_Branch_in,
    output reg Ctl_MemtoReg_out,Ctl_RegWrite_out,
    //bypass
    input [4:0] Rd_in,
    output reg [4:0] Rd_out,
    
    input jal_in, jalr_in,
    
    input Zero_in,
    input [31:0] Write_Data, ALUresult_in, PCimm_in, PC_in,
    output PCSrc,
    
    output reg jal_out, jalr_out,
    output reg [31:0] Read_data, ALUresult_out, PC_out,
    output [31:0] PCimm_out
    );
    
    wire branch;
    
    or(branch, jalr_in, jal_in, Zero_in);    
    and(PCSrc, Ctl_Branch_in, branch);
    

    //DMEM
    parameter RAM_size =1024;
    reg [31:0] RAM[0:RAM_size-1];
    integer i;
    initial begin
     /* for (i=0; i!=RAM_size; i=i+1) begin
            RAM[i] = 32'b0;
        end */
        $readmemh("darksocv.ram.mem", RAM);
    end
    always @(posedge clk) begin
        if (Ctl_MemWrite_in)
            RAM[ALUresult_in>>2] <=Write_Data;
        if (reset)
            Read_data <= 32'b0;
        else       
            Read_data <=  RAM[ALUresult_in>>2];
     end       
//    always @(posedge clk, posedge reset) begin
//        if (reset) begin
//             for( i=0; i<1024; i=i+1) begin //Can be statically unrolled
//                mem[i]  <= 32'b0 ;
//             end

//        end
//		else if(!Ctl_MemWrite_in && Ctl_MemRead_in)      
//			Read_data <=  mem[ALUresult_in] ;        
//		else if(Ctl_MemWrite_in && !Ctl_MemRead_in) 
//			mem[ALUresult_in] <= Write_Data;
//	    else begin
//		      Read_data <= 32'b0;
//	    end
        
//    end
    
    always @(posedge clk) begin
        Ctl_MemtoReg_out <= Ctl_MemRead_in;
        Ctl_RegWrite_out <= Ctl_RegWrite_in;
		ALUresult_out <= ALUresult_in;
		
		Rd_out <= Rd_in;
		
		jalr_out <= (reset) ? 1'b0 : jalr_in;
		jal_out  <= (reset) ? 1'b0 : jal_in;
		PC_out   <= (reset) ? 1'b0 : PC_in;
    end
    
   assign PCimm_out = (jalr_in) ? ALUresult_in : PCimm_in;
    
endmodule
