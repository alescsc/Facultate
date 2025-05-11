module shift_serial_in_tb(output reg serial_in, output reg clk, output reg rst, output reg shift, output [3:0]Q);

shift_serial_in UUT(.shift(shift), .serial_in(serial_in), .clk(clk), .rst(rst), .Q(Q));

initial begin
	clk = 0;
	forever #7 clk = ~clk;
end

initial begin
	rst = 1; #2 rst = 0;
end

initial begin
	shift = 1;
	serial_in = 0; #5
	serial_in = 1; #12
	serial_in = 0; #1
	serial_in = 1; #3
end

endmodule