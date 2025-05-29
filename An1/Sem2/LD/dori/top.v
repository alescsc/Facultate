module top(input clk,
	input rst,
	input [1:0] cmd,
	output clk_div,
	output [1:0] state,
	output [6:0] hex1, hex2, hex3, hex4
);

wire [5:0] reg_min;
wire [5:0] reg_sec;

clk_div c(
	.clk(clk),
	.rst(rst),
	.clk_div(clk_div)
	);

time_mng t(
	.clk(clk_div),
	.rst(rst),
	.cmd(cmd),
	.min(reg_min),
	.sec(reg_sec),
	.state(state)
	);

hex h1(
	.c(reg_sec[3:0]),
	.hex(hex1)
	);

hex h2(
	.c({2'b0,reg_sec[5:4]}),
	.hex(hex2)
	);

hex h3(
	.c(reg_min[3:0]),
	.hex(hex3)
	);

hex h4(
	.c({2'b0,reg_min[5:4]}),
	.hex(hex4)
	);

endmodule
