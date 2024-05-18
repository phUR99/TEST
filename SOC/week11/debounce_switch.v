`timescale 1ns / 1ps

module debounce_switch (
    input   i_clk,
    input   i_switch,
    output  o_switch
);
    parameter PUSHED = 1;
    parameter RELEASED = 0;
    parameter FALSE = 0;
    parameter TRUE = 1;
	parameter DEBOUNCE_LIMIT = 500_000; // 10ms as 100MHz
	
    reg [32:0] r_count = 0;
	
    reg r_prevState = RELEASED;
	reg retValue = FALSE;
	
    assign o_switch = retValue;

    always @(posedge i_clk ) begin
        if ( ((i_switch == PUSHED) && (r_prevState == RELEASED)) && (r_count < DEBOUNCE_LIMIT) ) begin
			r_count = r_count+1;
			retValue = FALSE;
		end
		else if ( ((i_switch == PUSHED) && (r_prevState == RELEASED)) && (r_count == DEBOUNCE_LIMIT) ) begin
            r_count = 0;
			r_prevState = PUSHED;
			retValue = FALSE;
		end
        else if ( ((i_switch == RELEASED) && (r_prevState == PUSHED)) && (r_count < DEBOUNCE_LIMIT) ) begin
			r_count = r_count+1;
			retValue = FALSE;
		end
		else if ( ((i_switch == RELEASED) && (r_prevState == PUSHED)) && (r_count == DEBOUNCE_LIMIT) ) begin
			r_count = 0;
            r_prevState = RELEASED;
			retValue = TRUE;
		end
		else begin
		    r_count = 0; 
            retValue = FALSE;
		end
    end

endmodule


