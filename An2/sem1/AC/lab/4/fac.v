module FAC(input x, y, ci,
		   output reg z, co);

always @(*)
	begin
	assign z = (~x & ~y & ci) | (~x & y & ~ci) | (x & y & ci) | (x & ~y & ~ci);
	assign co = y & ci | x & y | x & ci;
	end
endmodule

module FAC_tb();

reg x_tb, y_tb, ci_tb;
wire co_tb, z_tb;

//initial begin
//	$display("x=%b, y=%b, ci=%b, z=%b, co=%b", x_tb, y_tb, ci_tb, z_tb, co_tb);
//end

FAC UUT(.x(x_tb), .y(y_tb), .ci(ci_tb), .z(z_tb), .co(co_tb));

integer cnt;

initial begin
	for(cnt = 0; cnt<8; cnt=cnt+1) begin
		#10 {x_tb, y_tb, ci_tb} = cnt;
	$display("t=%0t  x=%b y=%b ci=%b | z=%b co=%b",
           $time, x_tb, y_tb, ci_tb, z_tb, co_tb);
    end

end
endmodule