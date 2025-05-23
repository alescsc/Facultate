module automat_tb(output reg clk, output reg rst, output reg in, output o, output [1:0]state);

automat UUT(.clk(clk), .rst(rst), .in(in), .o(o), .state(state));

initial begin
	clk = 0;
	forever #5 clk = ~clk;
end

initial begin
	rst = 1; #2 rst = 0;
end

initial begin
	in = 0; #7
	in = 1; #7
	in = 1; #11
	in = 0;
end

endmodule