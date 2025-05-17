module counter_tb(output reg clk,
	output reg rst,
	output [5:0] cnt);


counter UUT(.clk(clk), .rst(rst), .cnt(cnt));


initial begin 
	clk = 0;
	forever #5 clk =~clk;
end

initial begin 
	rst = 0; #30
	rst = 1; #25
	rst = 0; #10
	rst = 0; #23
	rst = 1; #44
	rst = 0; 
end


endmodule
