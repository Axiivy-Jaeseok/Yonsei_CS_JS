module mux2_4bit(A, I0, I1, Z);
  input A;
  input [3:0] I0, I1;
  output [3:0] Z;
  
  assign Z[3] = (~A & I0[3]) | (A & I1[3]);
  assign Z[2] = (~A & I0[2]) | (A & I1[2]);
  assign Z[1] = (~A & I0[1]) | (A & I1[1]);
  assign Z[0] = (~A & I0[0]) | (A & I1[0]);

endmodule