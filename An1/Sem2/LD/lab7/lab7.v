module lab7(input D, input clk, input rst, output reg Q);

always @(posedge clk)
begin

if(rst)
	Q <= 0;
else
	Q <= D;

end
endmodule