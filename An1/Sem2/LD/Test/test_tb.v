module test_tb(ouput reg A, output reg B, output reg C, output reg D, output f)

UUT test(A(.A), B(.B), C(.C), D(.D));

A = 0; B = 0; C = 0; D = 0; #10
A = 0; B = 0; C = 0; D = 1; #10
A = 0; B = 0; C = 1; D = 0; #10
A = 0; B = 0; C = 1; D = 1; 

endmodule
