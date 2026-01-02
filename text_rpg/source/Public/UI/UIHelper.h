#pragma once
#include "Windows.h"
#include "conio.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono> 

class UIHelper
{
public:
    // 콘솔창 이름, 크기, 커서에 대한 세팅 함수
    void SetConsoleSetting();

    // 텍스트의 색깔 변경 함수
    void textcolor(int color_num);

    // 커서의 위치 조정에 대한 함수
    void gotoxy(int x, int y);

    void BoxUI(int x, int y, int sx, int sy, int color_num);

    // 원하는 위치에 문자를 출력
    void Draw(int x, int y, const std::string spr);

    // 10칸짜리 Bar형태의 UI를 출력하기 위한 함수. bar의 색 정도는 정할 수 있음.
    void DrawBar(int x, int y, double currentvalue, double Maxvalue, int color_num);

    // 메시지 출력 함수. 속도 조정 가능.
    void PrintLine(const std::string& msg, int color_num, int speed);

    // 유저 선택 함수. xy는 위치 n은 선택지 개수. 선택지 번호를 반환.
    int UserSelection(int x, int y, int n);
private:
    const int WIDTH_ = 1600;
    const int HEIGHT_ = 900;
};