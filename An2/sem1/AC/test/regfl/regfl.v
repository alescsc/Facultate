module dec #(parameter n = 3)(input [n-1:0]s, input e, output reg [2**n-1:0]o);

always @(*) begin
	o = (2**n{1'b0});
	if(e)
		o = 2**s;
end
endmodule

module rgst #(parameter n = 64)(input ld, clr, clk, rst, input [n-1:0]d, output [n-1:0]q);

always @(posedge clk, negedge rst) begin
	if(rst)
		q <= {n{1'b0}};
	else
		if(clr)
			q <= {n{1'b0}};
			else
				q <= d;
end
endmodule

module regfl(input [63:0]d, input [2:0]s, input we, clk, rst, output [511:0]q);

wire [7:0]w;

dec #(.n(3))reg3(.we(e), .s(s), .w(o));

generate
genvar cnt;
for(cnt = 0; cnt < 8; cnt = cnt + 1)
	begin : vect
	rgst #(.n(64))rgst64(.w(ld), .clk(clk), .rst(rst), .clr(0), .d(d), .q(q[(cnt*64) + 63 : cnt*64]));
	end
endgenerate
endmodule