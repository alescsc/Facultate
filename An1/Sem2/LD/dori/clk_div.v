module clk_div(input clk, rst,
output clk_div);

reg clk_div_next, clk_div_reg;
reg[24:0] cnt_reg, cnt_next;

always@(posedge clk or negedge rst)
begin
if (rst == 0)
begin
cnt_reg <= 0;
clk_div_reg <= 0;
end
else
begin
cnt_reg <= cnt_next;
clk_div_reg <= clk_div_next;

end
end

always@(cnt_reg,clk_div_reg)
begin
if(cnt_reg == 25000000)
begin
cnt_next = 0;
clk_div_next = ~clk_div_reg;
end
else
begin
cnt_next = cnt_reg + 1;
clk_div_next = clk_div_reg;
end

end
assign clk_div = clk_div_reg;

endmodule
