#pragma once
#include "Windows.h"
#include "conio.h"
#include "Types/ColoredText.h"
#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <chrono> 
#include <deque>

class UIHelper
{
public:
    // 콘솔창 이름, 크기, 커서에 대한 세팅 함수
    void SetConsoleSetting();

    void ConsoleClear(int x, int y, int mx, int my);

    // 텍스트의 색깔 변경 함수
    void textcolor(int color_num);

    // 커서의 위치 조정에 대한 함수
    void gotoxy(int x, int y);

    // 박스형태의 창을 출력하는 기능.
    void BoxUI(int x, int y, int sx, int sy, int color_num);

    // 원하는 위치에 문자를 출력
    void Draw(int x, int y, const std::string spr);

    //.txt 파일 내용 출력.
    void PrintFile(int x, int y, const std::string& filename, int color_num);

    // 10칸짜리 Bar형태의 UI를 출력하기 위한 함수. bar의 색 정도는 정할 수 있음.
    void DrawBar(int x, int y, int barsize, double currentvalue, double Maxvalue, int color_num);   

    // 메시지 출력 함수. 속도 조정 가능.
    void PrintLine(const std::string& msg, int color_num, int speed);

    std::deque<ColoredText>& GetLog();

    // 유저 선택 함수. xy는 위치 n은 선택지 개수. 선택지 번호를 반환.
    int UserSelection(int x, int y, int n);

    int CountSelection(int x, int y, const int max);

    // 로그 입력
    void PushLog(const std::string& log, int color_num);

    // 로그 출력
    void Printlog(int x, int y, std::deque<ColoredText>& log);

private:
    const int WIDTH_ = 1600;
    const int HEIGHT_ = 900;

    //로그 덱
    std::deque<ColoredText> Log_;
};