module mux2(A, I0, I1, Z);
  input A, I0, I1;
  output Z;
  
  assign Z = (~A & I0) | (A & I1);
endmodule


