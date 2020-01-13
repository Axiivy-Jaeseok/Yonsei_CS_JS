`timescale 1ns/1ns

module testbench_prj1();
	reg [3:0] a,b; 		// 4-bit inputs
	wire [3:0] s_rca,s_cla; // 4-bit sum outpus
	wire o_rca, o_cla;	// 1-bit overflow flags
	
	rca my_rca(a,b,s_rca,o_rca);
	cla my_cla(a,b,s_cla,o_cla);

	initial begin
		a=5;b=3; #1;	// s=8(-8), o=1
		a=4;b=-2; #1;	// s=2, o=0
		a=7;b=6; #1;	// s=13(-3), o=1
		a=8;b=9; #1;	// s=1, o=1
	end

endmodule

