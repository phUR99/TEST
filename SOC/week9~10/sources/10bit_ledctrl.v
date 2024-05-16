module led_ctrl_10bit(
    input [9:0] sig_sel,
    output [9:0] sig_led
);    
    assign sig_led = sig_sel;

endmodule