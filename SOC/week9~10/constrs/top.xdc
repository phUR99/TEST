# Clock, Reset
#set_property -dict {PACKAGE_PIN R4 IOSTANDARD LVCMOS33} [get_ports ]
#set_property -dict {PACKAGE_PIN U7 IOSTANDARD LVCMOS33} [get_ports ]

# 7-Segment Pin Mapping (0-7)
#set_property -dict {PACKAGE_PIN U17  IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN V17  IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN W17  IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN R18  IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN T18  IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN U18  IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN V18  IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN P19  IOSTANDARD LVCMOS33} [get_ports {}]

# Digit Pin Mapping (0-7)
#set_property -dict {PACKAGE_PIN P14  IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN R14  IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN P15  IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN P16  IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN R16 IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN N17 IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN P17  IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN R17 IOSTANDARD LVCMOS33} [get_ports {}]

# LED Pin Mapping (0-15)
set_property -dict {PACKAGE_PIN Y18  IOSTANDARD LVCMOS33} [get_ports {sig_led[0]}]
set_property -dict {PACKAGE_PIN AA18  IOSTANDARD LVCMOS33} [get_ports {sig_led[1]}]
set_property -dict {PACKAGE_PIN AB18  IOSTANDARD LVCMOS33} [get_ports {sig_led[2]}]
set_property -dict {PACKAGE_PIN W19  IOSTANDARD LVCMOS33} [get_ports {sig_led[3]}]
set_property -dict {PACKAGE_PIN Y19  IOSTANDARD LVCMOS33} [get_ports {sig_led[4]}]
set_property -dict {PACKAGE_PIN AA19  IOSTANDARD LVCMOS33} [get_ports {sig_led[5]}]
set_property -dict {PACKAGE_PIN W20  IOSTANDARD LVCMOS33} [get_ports {sig_led[6]}]
set_property -dict {PACKAGE_PIN AA20  IOSTANDARD LVCMOS33} [get_ports {sig_led[7]}]
set_property -dict {PACKAGE_PIN AB20 IOSTANDARD LVCMOS33} [get_ports {sig_led[8]}]
set_property -dict {PACKAGE_PIN W21 IOSTANDARD LVCMOS33} [get_ports {sig_led[9]}]
#set_property -dict {PACKAGE_PIN Y21  IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN AA21  IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN AB21  IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN W22  IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN Y22  IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN AB22  IOSTANDARD LVCMOS33} [get_ports {}]

# Push Switch Pin Mapping
#UP
#set_property -dict {PACKAGE_PIN M20  IOSTANDARD LVCMOS33} [get_ports {sig_sel[0]}]    
#LEFT
#set_property -dict {PACKAGE_PIN N20  IOSTANDARD LVCMOS33} [get_ports {sig_sel[1]}]  
#MID  
#set_property -dict {PACKAGE_PIN M21  IOSTANDARD LVCMOS33} [get_ports ]       
#RIGHT        
#set_property -dict {PACKAGE_PIN M22  IOSTANDARD LVCMOS33}  [get_ports {sig_sel[2]}]
#DOWN
#set_property -dict {PACKAGE_PIN N22  IOSTANDARD LVCMOS33}  [get_ports {sig_sel[3]}]    

# Slide Switch Pin Mapping (0-15)
set_property -dict {PACKAGE_PIN J4   IOSTANDARD LVCMOS15} [get_ports {sig_sel[0]}]  
set_property -dict {PACKAGE_PIN L3   IOSTANDARD LVCMOS15} [get_ports {sig_sel[1]}]
set_property -dict {PACKAGE_PIN K3   IOSTANDARD LVCMOS15} [get_ports {sig_sel[2]}]
set_property -dict {PACKAGE_PIN M2   IOSTANDARD LVCMOS15} [get_ports {sig_sel[3]}]
set_property -dict {PACKAGE_PIN K6   IOSTANDARD LVCMOS15} [get_ports {sig_sel[4]}]
set_property -dict {PACKAGE_PIN J6   IOSTANDARD LVCMOS15} [get_ports {sig_sel[5]}]
set_property -dict {PACKAGE_PIN L5   IOSTANDARD LVCMOS15} [get_ports {sig_sel[6]}]
set_property -dict {PACKAGE_PIN L4   IOSTANDARD LVCMOS15} [get_ports {sig_sel[7]}]
set_property -dict {PACKAGE_PIN R19  IOSTANDARD LVCMOS33} [get_ports {sig_sel[8]}]
set_property -dict {PACKAGE_PIN V19 IOSTANDARD LVCMOS33} [get_ports {sig_sel[9]}]
#set_property -dict {PACKAGE_PIN T20 IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN U20 IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN V20 IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN T21 IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN U21 IOSTANDARD LVCMOS33} [get_ports {}]
#set_property -dict {PACKAGE_PIN V22 IOSTANDARD LVCMOS33} [get_ports {}]
