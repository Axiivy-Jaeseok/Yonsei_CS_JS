module controller (
  input clk,
  input wait_, IR15, AC15, IR14,
  output [21:0] bus_controller
);
  wire [39:0] micro_instructions;
  wire [1:0] muxout;

  reg [3:0] state;
  wire [3:0] next_state;
  
  controllerROM rom(state, micro_instructions);
   // TODO: write codes to implement controller in lecture note, page 59
  
  mux2 mymux1(micro_instructions[39], wait_, IR15, muxout[1]);
  mux2 mymux2(micro_instructions[38], AC15, IR14, muxout[0]);
  
  mux4_4bit mymux3(muxout[0], muxout[1], micro_instructions[37:34], micro_instructions[33:30], micro_instructions[29:26], micro_instructions[25:22], next_state);

  assign bus_controller = micro_instructions[21:0];
  
  always @ (posedge clk) state = next_state;
  
  initial begin
    state = 0;
  end
  
endmodule



