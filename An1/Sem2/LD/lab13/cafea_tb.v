module cafea_tb(output reg clk, output reg rst, output reg credit05, output reg credit10, output reg [1:0] coffee, output [2:0] current_state, output exprr, output expr_l, output capp);

cafea_tb UUT(.clk(clk), .rst(rst), .credit05(credit05), .credit10(credit10), .coffee(coffee), .current_state(current_state), .exprr(exprr), .expr_l(expr_l), .capp(capp));

initial begin
	clk = 0;
	forever #5 clk = ~clk;
end

initial begin
	rst = 1; #2 rst = 0;
end

initial begin
	credit05 = 1; #6
	credit05 = 1; #4
	credit10 = 1; #6
	coffee = 2'b11;
end

endmodule