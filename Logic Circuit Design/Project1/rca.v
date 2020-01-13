`timescale 1ps/1ps

module rca(A, B, S_rca, O_rca);
  input [3:0] A, B;
  output O_rca;
  output [3:0] S_rca;
  wire wire0, wire1, wire2, wire3;
  
  FullAdder fa_1(A[0], B[0], 1'b0, wire0, S_rca[0]);
  FullAdder fa_2(A[1], B[1], wire0, wire1, S_rca[1]);
  FullAdder fa_3(A[2], B[2], wire1, wire2, S_rca[2]);
  FullAdder fa_4(A[3], B[3], wire2, wire3, S_rca[3]);

  assign #30 O_rca = wire2 ^ wire3;
endmodule

module FullAdder(A, B, Cin, Cout, S_fa);
  input A, B, Cin;
  output Cout, S_fa;
  wire G1, G2, G3;
  
  assign #45 S_fa = A ^ B ^ Cin;
  assign #20 G1 = A & Cin;
  assign #20 G2 = B & Cin;
  assign #20 G3 = A & B;
  assign #30 Cout = G1 | G2 | G3;

endmodule
