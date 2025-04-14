module test_tb;
  reg A, B, C, D;
  wire f;

  test UUT(.A(A), .B(B), .C(C), .D(D), .f(f));

  initial begin
    A = 0; B = 0; C = 0; D = 0; #10;
    A = 0; B = 0; C = 0; D = 1; #10;
    A = 0; B = 0; C = 1; D = 0; #10;
    A = 0; B = 0; C = 1; D = 1; #10;
  end
endmodule