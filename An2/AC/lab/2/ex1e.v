module ex1e (
	input a, b, c, d,
	output f5
);
	assign f5 = ~(~(~a & b) & ~(~b & d) & ~(a & b & ~d));
endmodule

module ex1e_tb;
	reg a, b, c, d;
	wire f5;

	ex1e ex1e_i (.a(a), .b(b), .c(c), .d(d), .f5(f5));

	integer k;
	initial begin
		$display("Time\ta\tb\tc\td\tabcd_10\tf5");
		$monitor("%0t\t%b\t%b\t%b\t%b\t%0d\t%b", $time, a, b, c, d, {a,b,c,d}, f5);
		{a, b, c, d} = 0;
		for (k = 1; k < 16; k = k + 1)
			#10 {a, b, c, d} = k;
	end
endmodule