`define INIT 2'b00
`define START 2'b01
`define STOP 2'b10
`define STOP_RESET 2'b11

module time_mng(input clk, rst,
		input [1:0] cmd,
		output [1:0] state,
		output [5:0] min, sec);

reg [1:0] state_reg, state_next;
reg [5:0] sec_reg, sec_next;
reg [5:0] min_reg, min_next;


always @(posedge clk or negedge rst)
begin
	if (rst == 0)
	begin
		state_reg <= 0;
		sec_reg <= 0;
		min_reg <= 0;
	end

	else
	begin
		state_reg <= state_next;
		sec_reg <= sec_next;
		min_reg <= min_next;
	end
end


always @(state_reg, cmd, sec_reg, min_reg)
begin
	sec_next = sec_reg;
	min_next = min_reg;
	state_next = state_reg;

case (state_reg)
	`INIT: begin
		if (cmd == 1) state_next = `START;
		min_next = 0;
		sec_next = 0;
		end

	`START: begin
		sec_next = sec_reg + 1;
		if (sec_reg == 59)
		begin
			sec_next = 0;
			min_next = min_reg + 1;
		end	

		if (cmd == 2) state_next = `STOP;
		if (cmd == 3) state_next = `STOP_RESET;
		end

	`STOP: begin
		if (cmd == 1) state_next = `START;
		if (cmd == 3) state_next = `STOP_RESET;
		end

	`STOP_RESET: begin
		     state_next =`INIT;
		     end


endcase
end

assign state = state_reg;
assign sec = sec_reg;
assign min = min_reg;


endmodule
