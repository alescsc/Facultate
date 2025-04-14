module test(input A, input B, input C, input D, output f);

assign f = (~A & ~B) | (~A & B & D) | (B & C & D);

endmodule