 `ifndef __TEST_V__
 `define __TEST_V__

module test(
	// output pins
	output wand x,
	output wor y,

	// input pins
	input a, b, c, d, e, f, g, h, i
	);

	// calculate x
	assign x = a;
	assign x = b;
	assign x = c;
	assign x = d;
	assign x = e;
	assign x = f;
	assign x = g;
	assign x = h;
	assign x = i;

	// calculate y
	assign y = a;
	assign y = b;
	assign y = c;
	assign y = d;
	assign y = e;
	assign y = f;
	assign y = g;
	assign y = h;
	assign y = i;

endmodule

`endif /* __TEST_V__ */