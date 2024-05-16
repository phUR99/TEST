module led_ctrl_10bit_case(
    input [9:0] sig_sel,
    output [9:0] sig_led
);    
    //전부 1이거나 전부 0일 경우 반전시켜줌
    assign sig_led = (sig_sel == 10'b1111111111 || sig_sel == 10'b0000000000) ? ~sig_sel : sig_sel;

endmodule