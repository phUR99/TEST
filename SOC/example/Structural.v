module fulladder (
    cin, x, y, s, cout
);
    input x, y, cin;
    output s, cout;
    reg s, cout;
        
    always @(*) begin
        {cout, s} = x + y + cin;       
    end
endmodule

module comparator (
    x, y, v, n, z
);

    input [3:0] x, y;
    output v, n, z;
    wire [3:0] S;
    wire [4:1] c;
    reg v, n, z;

    fulladder FA0(1'b1, x[0], ~y[0], S[0], c[1]);
    fulladder FA1(c[1], x[1], ~y[1], S[1], c[2]);
    fulladder FA2(c[2], x[2], ~y[2], S[2], c[3]);
    fulladder FA3(c[3], x[3], ~y[3], S[3], c[4]);

    always @(*) begin
        v = c[4]^c[3];
        n = S[3];
        z = !S;
    end

endmodule

module parity_9_bit (
    x, 
    ep, op

);
    input [8:0] x;
    output ep, op;
    
    wire c, d, e, f, g, h, j;
    xor(c, x[0], x[1]);
    xor(d, x[2], x[3]);
    xor(e, x[4], x[5]);
    xor(f, x[6], x[7]);
    xor(g, c, d);
    xor(h, e, f);
    xor(i, g, h);
    xor(ep, i, x[8]);
    xnor(op, i, x[8]);    

endmodule

module AndOr (
    AandB, AorB, A, B
);
    input A, B;
    output AandB, AorB;

    and #5 (AandB, A, B);
    or #10 (AorB, A, B);    

endmodule

module SRlatch (
    q, qbar, set, rst
);
    input set, rst;
    output q, qbar;

    nor #1(q, qbar, rst);
    nor #1(qbar, q, set);    

endmodule

module compare_2(
    AgtB, AltB, AeqB,
    a0, b0, a1, b1
);
    input a0, b0, a1, b1;
    output AgtB, AltB, AeqB;

    nor(AgtB, AltB, AeqB);
    or(AltB, w1, w2, w3);
    and(AeqB, w4, w5);
    and(w1, w6, b1);
    and(w2, w6, w7, b0);
    and(w3, w7, b0, b1);
    not(w6, a1);
    not(w7, a0);
    xnor(w4, a1, b1);
    xnor(w5, a0, b0);


endmodule

