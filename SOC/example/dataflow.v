module SRlatch (
    r, s, 
    q, qbar
);
    input r, s;
    output q, qbar;

    assign q = ~(r | qbar);
    assign qbar = ~(s | q);
endmodule

module parity_9_bit (
    x, 
    ep, op
);
    input [8:0] x;
    output ep, op;

    assign ep = ^x;
    assign op = ~ep;
    
endmodule

module allbit_01_detector (
    x, zero, one
);
    input [7:0] x;
    output zero, one;
    
    assign zero = ~|x;
    assign one = &x;    

endmodule

module comparator_4bit (
    Iagtb, Iaeqb, Ialtb,
    a, b,
    Oagtb, Oaeqb, Oaltb
);
    input [3:0] a, b;
    input Iagtb, Iaeqb, Ialtb;

    output Oagtb, Oaeqb, Oaltb;

    assign Oagtb = (a==b) && (Iaeqb == 1);
    assign Oaeqb = (a>b) || ((a==b)&&(Iagtb==1));
    assign Oaltb = (a<b) || ((a==b)&&(Ialtb==1));
endmodule

module comparator_12bit (
    Iagtb, Iaeqb, Ialtb, a, b, Oaeqb, Oagtb, Oaltb
);
    input Iagtb, Iaeqb, Ialtb;
    input [11:0] a, b;

    output Oagtb, Oaeqb, Oaltb;
        

    comparator_4bit bit11_8(w2_1, w2_2, w2_3, a[11:8], b[11:8], Oagtb, Oaeqb, Oaltb);
    comparator_4bit bit7_4(w1_1,  w1_2,   w1_3, a[7:4], b[7:4], w2_1, w2_2, w2_3);
    comparator_4bit bit3_0(Iagtb, Iaeqb, Ialtb, a[3:0], b[3:0], w1_1, w1_2, w1_3);

endmodule

module tri_buf (
    a, b, enable
);
    input a;
    input enable;

    output b;

    assign b = (enable) ? a : 1'bz;
endmodule

module excess3_to_bcd (
    w,x,y,z,a,b,c,d
);
    input w, x, y, z;
    output a, b, c, d;

    assign a = w & x | w & y & z,
           b = w & ~y &z | x & y & z | ~x & ~z,
           c = y ^ z,
           d = ~ z;           

endmodule

module problem_3_11 (
    data, shift, out
);
    parameter N = 8;
    input [N-1:0] data;
    input [1:0] shift;
    output [N-1:0] out;

    assign out = (shift === 0) ? data :
                 (shift === 1) ? {data[N-1], data[N-1:1]} :
                 (shift === 2) ? {{2{data[N-1]}}, data[N-1:2]} :
                 (shift === 3) ? {{3{data[N-1]}}, data[N-1:3]} : 
                                 {N{1'bz}};

endmodule