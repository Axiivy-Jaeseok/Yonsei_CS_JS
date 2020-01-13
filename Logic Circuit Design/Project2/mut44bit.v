module mux4_4bit(A,B,I0,I1,I2,I3,Z);
  input A,B;
  input [3:0] I0,I1,I2,I3;
  output [3:0] Z;
  wire [3:0] X,Y;
  
  mux2_4bit mymux1(A,I0,I1,X);
  mux2_4bit mymux2(A,I2,I3,Y);
  
  mux2_4bit mymux3(B,X,Y,Z);
endmodule  