module shift_serial_in(input shift, input serial_in, input clk, input rst, output [3:0]Q);

wire [3:0]D;
wire [3:0]Q_w;

assign D[0] = shift ? serial_in : Q_w[0];
assign D[1] = Q_w[0] ? serial_in : Q_w[1];
assign D[2] = Q_w[1] ? serial_in : Q_w[2];
assign D[3] = Q_w[2] ? serial_in : Q_w[3];

D_flip_flop dff0(.D(D[0]), .clk(clk), .rst(rst), .Q(Q_w[0]));
D_flip_flop dff1(.D(D[1]), .clk(clk), .rst(rst), .Q(Q_w[1]));
D_flip_flop dff2(.D(D[2]), .clk(clk), .rst(rst), .Q(Q_w[2]));
D_flip_flop dff3(.D(D[3]), .clk(clk), .rst(rst), .Q(Q_w[3]));

assign Q = Q_w;
endmodule