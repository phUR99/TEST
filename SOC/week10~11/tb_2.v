`timescale 1ns / 1ps

module OZODetector_tb;

    // 모듈의 입력 핀을 정의합니다.
    reg clk;
    reg rstb;
    reg PUSH_SW_LEFT;
    reg PUSH_SW_RIGHT;

    // 모듈의 출력 핀을 정의합니다.
    wire LED;

    // RisingEdgeDetector 모듈을 인스턴스화합니다.
    OZOdetector UUT (
        .clk(clk),
        .rstb(rstb),
        .PUSH_SW_LEFT(PUSH_SW_LEFT),
        .PUSH_SW_RIGHT(PUSH_SW_RIGHT),
        .LED(LED)
    );

    // 클럭을 생성합니다.
    always begin
        #5 clk = ~clk; // 5ns 주기로 클럭을 토글합니다.
    end

    // 초기화 과정을 설정합니다.
    initial begin
        // 초기 입력값 설정
        clk = 0;
        rstb = 0;
        PUSH_SW_LEFT = 0;
        PUSH_SW_RIGHT = 0;

        // 초기화 후 대기
        #10 rstb = 1;

        // 테스트 시나리오 시작
        #10 PUSH_SW_LEFT = 1; // PUSH_SW_LEFT를 누름
        #10 PUSH_SW_LEFT = 0; // PUSH_SW_LEFT를 놓음
        #10 PUSH_SW_LEFT = 0; // PUSH_SW_LEFT를 놓음
        #10 PUSH_SW_RIGHT = 1; // PUSH_SW_RIGHT를 누름
        #10 PUSH_SW_RIGHT = 0; // PUSH_SW_RIGHT를 놓음
        #10 PUSH_SW_RIGHT = 1; // PUSH_SW_RIGHT를 누름
        #10 PUSH_SW_RIGHT = 0; // PUSH_SW_RIGHT를 놓음
        #10 PUSH_SW_LEFT = 1; // PUSH_SW_LEFT를 누름
        #10 PUSH_SW_LEFT = 0; // PUSH_SW_LEFT를 놓음
        #10 PUSH_SW_RIGHT = 1; // PUSH_SW_RIGHT를 누름
        #10 PUSH_SW_RIGHT = 0; // PUSH_SW_RIGHT를 놓음
        #10 PUSH_SW_LEFT = 1; // PUSH_SW_LEFT를 누름
        #10 PUSH_SW_LEFT = 0; // PUSH_SW_LEFT를 놓음
        #10 PUSH_SW_RIGHT = 1; // PUSH_SW_RIGHT를 누름
        #10 PUSH_SW_RIGHT = 0; // PUSH_SW_RIGHT를 놓음

        // 종료
        #100 $finish;
    end

endmodule
