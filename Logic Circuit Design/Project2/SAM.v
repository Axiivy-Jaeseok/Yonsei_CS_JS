`timescale 1ns/1ps

module SAM();
  reg clk;

// TODO: you may alter the type of registers to wire (e.g. reg RW -> wire RW) if necessary
  reg [15:0] PC;
  reg [15:0] AC, MAR, MBR, IR;
  reg [15:0] ABUS, RBUS, MBUS;
  reg [15:0] ADDRESS_BUS, DATA_BUS;
  reg RW, REQUEST;
  wire WAIT;

  reg [15:0] ALU_A, ALU_B;
  reg ALU_ADD, ALU_PASS_B;
  reg [15:0] ALU_RESULT;

  wire [21:0] b;
  controller my_controller(clk, WAIT, IR[15], AC[15], IR[14], b);

  wire [15:0] data_bus_t;
  always @ ( RW ) if (RW) DATA_BUS = data_bus_t;
  Memory my_memory(ADDRESS_BUS, REQUEST, RW, WAIT, DATA_BUS, data_bus_t);

  // initial settings
  // TODO : add any initialization process if required (not necessary)
  initial begin
    clk = 0;
    AC = 0;
    IR = 0;
    ADDRESS_BUS = 0;
  end
  always begin
    clk = ~clk; #1;
  end

  // ALU implementation
  always @ (ALU_ADD or ALU_PASS_B or ALU_A or ALU_B )begin
    if (ALU_ADD) ALU_RESULT = ALU_A + ALU_B;
    else if (ALU_PASS_B) ALU_RESULT = ALU_B;
  end

  always @ ( negedge clk ) begin
    // TODO: refer to lecture note, page 46
    if(b[21]) ABUS = PC; // PC to ABUS
    if(b[20]) ABUS = IR; // IR to ABUS
    if(b[19]) ABUS = MBR; // MBR to ABUS
    if(b[1]) RBUS = AC; // AC to RBUS
    if(b[0]) RBUS = ALU_RESULT; // ALU Result to RBUS
    if(b[18]) AC = RBUS; // RBUS to AC
    if(b[13]) ADDRESS_BUS = MAR; 
    if(b[12]) DATA_BUS = MBR;  
    RW = b[3];
    REQUEST = b[2];
    if(b[11]) IR = ABUS;
    if(b[10]) MAR[13:0] = ABUS[13:0];
    if(b[8]) MBR = RBUS;
    if(b[6]) PC[13:0] = 0;
    if(b[5]) PC[13:0] = PC[13:0] + 2;
    if(b[4]) PC[13:0] = ABUS[13:0];
  end

  always @ (b or AC or MBUS) begin
    if(b[7]) MBUS = MBR;
    if(b[17]) ALU_A = AC;
    if(b[16]) ALU_B = MBUS;
    ALU_ADD = b[15];
    ALU_PASS_B = b[14];
  end
  
  always @ (b or DATA_BUS) begin
    if(b[9]) MBR = DATA_BUS;
  end


/* Example 3. wire-based
  assign ABUS = b[21] ? PC : (b[20] ? IR : (b[19] ? MBR : 'bz));
  Note that you need to change ABUS's type as wire in this case (wire ABUS)
*/
endmodule