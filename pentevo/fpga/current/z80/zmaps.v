// This module makes mapping z80 memory accesses into FPGA EABs

`include "../include/tune.v"


module zmaps(

// Z80 controls
	input wire mreq_n,
	input wire wr_n,
	input wire [15:0] a,
	input wire [7:0] d,
	input wire zclk,
	
// config data
	input wire [4:0] fmaddr,
	
// FPRAM data
	output reg [7:0] zmd,
	
// FPRAM controls
	output wire cram_we,
	output wire sfys_we

);


// addresses of files withing zmaps
	localparam CRAM	= 3'b000;
	localparam SFYS	= 3'b001;
	

// control signals
	wire mwr = ~(mreq_n | wr_n);
	wire hit = (a[15:12] == fmaddr[3:0]) & fmaddr[4] & mwr;
	

// write enables
	assign cram_we = (a[11:9] == CRAM) & a[0] & hit;
	assign sfys_we = (a[11:9] == SFYS) & a[0] & hit;

	
// LSB fetching
	always @(posedge zclk)
		if (!a[0] & hit)
			zmd <= d;


endmodule
