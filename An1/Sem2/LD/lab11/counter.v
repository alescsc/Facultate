module counter(
	input clk,
	input rst,
	output reg [5:0] cnt);

always@(posedge clk or posedge rst)

	begin
	if(rst)
		cnt <= 6'b000000;
	else
		if(cnt == 33)
			cnt <= 6'b000000;
		else
			cnt <= cnt + 1;
	end

endmodule
