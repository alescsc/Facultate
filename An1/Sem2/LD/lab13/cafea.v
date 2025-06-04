`define INIT 3'b000
`define C05 3'b001
`define C10 3'b010
`define C15 3'b011
`define C20 3'b100
`define Expr 3'b101
`define ExprL 3'b110
`define Cap 3'b111

module cafea(input clk, input rst, input credit05, input credit10, input [1:0] coffee, output [2:0] current_state, output reg exprr, output reg expr_l, output reg capp);

reg [2:0] state_next, state_reg;

reg exprr_reg, exprr_next, expr_l_reg, expr_l_next, capp_reg, capp_next;

always @(posedge clk or posedge rst)
	begin
	if(rst)
		begin
			state_reg <= 0;
			exprr_reg <= 0;
			expr_l_reg <= 0;
			capp_reg <= 0;
		end
	else
		begin
			state_reg <= state_next;
			exprr_reg <= exprr_next;
			expr_l_reg <= expr_l_next;
			capp_reg <= capp_next;
		end
	end

always @(state_reg, coffee, credit05, credit10)
	begin
		state_next = state_reg;
		exprr_next = 0;
		expr_l_next = 0;
		case(state_reg)
			`INIT:begin
				state_next = `INIT;
				exprr_next = 0;
				expr_l_next = 0;
				capp_next = 0;
				if(credit05)
					state_next = `C05;
				if(credit10)
					state_next = `C10;
			end
			`C05:begin
				state_next = `C05;
				exprr_next = 0;
				expr_l_next = 0;
				capp_next = 0;
				if(credit05)
					state_next = `C10;
				if(credit10)
					state_next = `C15;
			end
			`C10:begin
				state_next = `C10;
				exprr_next = 0;
				expr_l_next = 0;
				capp_next = 0;
				if(credit05)
					state_next = `C15;
				if(credit10)
					state_next = `C20;
			end
			`C15:begin
				state_next = `C15;
				exprr_next = 0;
				expr_l_next = 0;
				capp_next = 0;
				if(credit05)
					state_next = `C20;
				if(credit10)
					state_next = `C20;
			end
			`C20:begin
				state_next = `C20;
				if(coffee == 2'b01)
					state_next = `Expr;
				if(coffee == 2'b10)
					state_next = `ExprL;
				if(coffee == 2'b11)
					state_next = `Cap;
			end
			`Expr:begin
				state_next = `Expr;
				exprr = 1;
				state_next = `INIT;
			end
			`ExprL:begin
				state_next = `ExprL;
				expr_l = 1;
				state_next = `INIT;
			end
			`Cap:begin
				state_next = `Cap;
				capp = 1;
				state_next = `INIT;
			end
		endcase
	end
assign current_state = state_reg;

endmodule
			
				