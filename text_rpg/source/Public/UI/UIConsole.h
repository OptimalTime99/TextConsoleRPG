#pragma once
#include "Windows.h"
#include "conio.h"

class UIConsole
{
public:
    // 콘솔창 이름, 크기, 커서에 대한 세팅 함수
    void SetConsole();

    // 텍스트의 색깔 변경 함수
    void textcolor(int color_number);

    // 커서의 위치 조정에 대한 함수
    void gotoxy(int x, int y);
};