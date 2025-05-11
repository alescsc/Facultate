module D_flip_flop(input D, input clk, input rst, output reg Q);

always @(posedge clk or posedge rst)
begin

if(rst)
	Q <= 0;
else
	Q <= D;
end

endmodule