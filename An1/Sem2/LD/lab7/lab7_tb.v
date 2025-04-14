module lab7_tb(output reg D, output reg clk, output reg rst, input Q);

lab7 UUT(.D(D), .clk(clk), .rst(rst), .Q(Q));

initial begin
	clk = 0;
	forever #5 clk = ~clk;
	D = 1;
end

initial begin
	rst = 1; #5
	rst = 0; #13
	rst = 1; #12
	rst = 0;
end

initial begin
	D = 0; #5
	D = 1; #20
 	D = 0; #2
	D = 1; #5
	D = 0; #15
	D = 1;
end

endmodule