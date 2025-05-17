module count_seven(input clk, input rst, output reg [6:0]out);


wire [3:0]cnt_seven;

counter UUT1(.clk(clk), .rst(rst), .cnt(cnt_seven));

seven_seg_decoder UUT2(.in(cnt_seven), .seg(out));


endmodule
