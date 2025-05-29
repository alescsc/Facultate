project_new example1 -overwrite

set_global_assignment -name FAMILY MAX10
set_global_assignment -name DEVICE 10M50DAF484C7G

set_global_assignment -name BDF_FILE example1.bdf
set_global_assignment -name VERILOG_FILE ../verilog/clk_div.v
set_global_assignment -name SDC_FILE example1.sdc

set_global_assignment -name TOP_LEVEL_ENTITY clk_div
set_location_assignment -to clk PIN_AH10

#set_location_assignment PIN_C10 -to d[0] ;# SW[0]
#set_location_assignment PIN_C11 -to d[1] ;# SW[0]
#set_location_assignment PIN_D12 -to d[2] ;# SW[0]
#set_location_assignment PIN_C12 -to d[3];
set_location_assignment PIN_B8 -to rst;
set_location_assignment PIN_P11 -to clk;
set_location_assignment PIN_A8 -to clk_div;
set_location_assignment PIN_A9 -to state[0];
set_location_assignment PIN_A10 -to state[1];
set_location_assignment PIN_D12 -to cmd[0];
set_location_assignment PIN_A14-to cmd[1];
set_location_assignment PIN_C14 -to hex0[0];
set_location_assignment PIN_E15 -to hex0[1];
set_location_assignment PIN_C15 -to hex0[2];
set_location_assignment PIN_C16 -to hex0[3];
set_location_assignment PIN_E16 -to hex0[4];
set_location_assignment PIN_D17 -to hex0[5];
set_location_assignment PIN_C17 -to hex0[6];
set_location_assignment PIN_D15 -to hex1[0];
set_location_assignment PIN_C18 -to hex1[1];
set_location_assignment PIN_D18 -to hex1[2];
set_location_assignment PIN_E18 -to hex1[3];
set_location_assignment PIN_B16 -to hex1[4];
set_location_assignment PIN_A17 -to hex1[5];
set_location_assignment PIN_A18 -to hex1[6];
set_location_assignment PIN_B17 -to hex2[0];
set_location_assignment PIN_A16 -to hex2[1];
set_location_assignment PIN_B20 -to hex2[2];
set_location_assignment PIN_A20 -to hex2[3];
set_location_assignment PIN_B19 -to hex2[4];
set_location_assignment PIN_A21 -to hex2[5];
set_location_assignment PIN_B21 -to hex2[6];
set_location_assignment PIN_C22 -to hex3[0];
set_location_assignment PIN_B22 -to hex3[1];
set_location_assignment PIN_A19 -to hex3[2];
set_location_assignment PIN_F21 -to hex3[3];
set_location_assignment PIN_E22 -to hex3[4];
set_location_assignment PIN_E21 -to hex3[5];
set_location_assignment PIN_C19 -to hex3[6];

load_package flow
execute_flow -compile

project_close