project_new example1 -overwrite

set_global_assignment -name FAMILY MAX10
set_global_assignment -name DEVICE 10M50DAF484C7G 

set_global_assignment -name BDF_FILE example1.bdf
set_global_assignment -name VERILOG_FILE count_seven.v
set_global_assignment -name SDC_FILE example1.sdc

set_global_assignment -name TOP_LEVEL_ENTITY count_seven


set_location_assignment PIN_C11 -to clk   ;# SW[0]
set_location_assignment PIN_C10 -to rst   ;# SW[0]


set_location_assignment PIN_C14  -to out[0]  ;# LED[0]
set_location_assignment PIN_E15  -to out[1]  ;# LED[1]
set_location_assignment PIN_C15  -to out[2]  ;# LED[2]
set_location_assignment PIN_C16  -to out[3]  ;# LED[3]
set_location_assignment PIN_E16  -to out[4]  ;# LED[4]
set_location_assignment PIN_D17  -to out[5]  ;# LED[5]
set_location_assignment PIN_C17  -to out[6]  ;# LED[6]

load_package flow
execute_flow -compile

project_close
