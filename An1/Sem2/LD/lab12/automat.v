`define INIT 2'b00
`define S1 2'b01
`define S2 2'b10
`define S3 2'b11

module automat(input clk, input rst, input in, output reg o, output [1:0]state);

reg [1:0] state_next, state_reg;

always @(posedge clk or posedge rst)
begin
	if(rst)
		state_reg <= 0;
	else
		state_reg <= state_next;
end

always @(state_reg, in)
begin
	state_next = state_reg;
	o = 0;
	case(state_reg)
		`INIT:begin
			o = 0;
			state_next = `S1;
			if(in)
				state_next = `INIT;
		end
		`S1:begin
			o = 0;
			state_next = `INIT;
			if(in)
				state_next = `S2;
		end
		`S2:begin
			o = 0;
			state_next = `INIT;
			if(in)
				state_next = `S3;
		end
		`S3:begin
			state_next = `INIT;
			if(in)
				o = 0;
			else
				o = 1;
		end
	endcase
end

assign state = state_reg;

endmodule