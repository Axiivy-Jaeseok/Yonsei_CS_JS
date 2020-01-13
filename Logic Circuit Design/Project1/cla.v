`timescale 1ps/1ps

module cla(A, B, S_cla, O_cla);
  input [3:0] A, B;
  output O_cla;
  output [3:0] S_cla;
  wire [3:0] G, P;
  wire C0, C1, C2, C3, C4;
  wire T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20;

  assign #20 G[0] = A[0] & B[0];
  assign #20 G[1] = A[1] & B[1];
  assign #20 G[2] = A[2] & B[2];
  assign #20 G[3] = A[3] & B[3];

  assign #30 P[0] = A[0] ^ B[0];
  assign #30 P[1] = A[1] ^ B[1];
  assign #30 P[2] = A[2] ^ B[2];
  assign #30 P[3] = A[3] ^ B[3];

  assign C0 = 1'b0;

  assign #20 T1 = C0 & P[0];
  assign #20 C1 = T1 | G[0];

  assign #30 T2 = C0 & P[0] & P[1];
  assign #20 T3 = G[0] & P[1];
  assign #30 C2 = T2 | T3 | G[1];

  assign #20 T4 = C0 & P[0];
  assign #20 T5 = P[1] & P[2];
  assign #20 T6 = T4 & T5;
  assign #30 T7 = G[0] & P[1] & P[2];
  assign #20 T8 = G[1] & P[2];
  assign #20 T9 = T6 | T7;
  assign #20 T10 = T8 | G[2];
  assign #20 C3 = T9 | T10;

  assign #30 T11 = C0 & P[0] & P[1];
  assign #20 T12 = P[2] & P[3];
  assign #20 T13 = T11 & T12;
  assign #20 T14 = G[0] & P[1];
  assign #20 T15 = P[2] & P[3];
  assign #20 T16 = T14 & T15;
  assign #30 T17 = G[1] & P[2] & P[3];
  assign #20 T18 = G[2] & P[3];
  assign #30 T19 = T13 | T16 | T17;
  assign #20 T20 = T18 | G[3];
  assign #20 C4 = T19 | T20;
  assign #30 O_cla = C3 ^ C4;

  assign #30 S_cla[0] = P[0] ^ C0;
  assign #30 S_cla[1] = P[1] ^ C1;
  assign #30 S_cla[2] = P[2] ^ C2;
  assign #30 S_cla[3] = P[3] ^ C3;
  
endmodule 
