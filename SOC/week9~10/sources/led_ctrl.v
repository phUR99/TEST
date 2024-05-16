`timescale 1ns / 1ps

module led_ctrl(sig_sel, sig_led);

input [3:0] sig_sel;
output [3:0] sig_led;
wire [3:0] sig_led;

assign sig_led = ~sig_sel;

endmodule
