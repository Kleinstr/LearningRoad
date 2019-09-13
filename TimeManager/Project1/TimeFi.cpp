#pragma warning(suppress : 4996)
#include <iostream>
#include <time.h>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
using namespace std;


void hidden()//���ع��
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = 0;//��1Ϊ��ʾ����0Ϊ����
	SetConsoleCursorInfo(hOut, &cci);

}
		
void gotoxy(int x, int y)//��λ��꣬xΪ������,yΪ������
{
	COORD pos = { x,y };//������  λ�ã��� 
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  //�õ���׼������׼��������� 
	SetConsoleCursorPosition(hOut, pos);
}
class Timer
{
private:
	long int start_time;
	long int pause_time;
	bool is_start;
	bool is_pause;
	bool is_stop;
public:
	Timer();
	bool isPause();
	bool isStop();
	void start();
	void stop();
	void Pause();
	inline long getstarttime() { return start_time; };
	void show();

};
Timer::Timer()
{
	Timer::is_stop = true;
	Timer::is_pause = false;
}

bool Timer::isPause()
{
	if (Timer::is_pause)
		return true;
	else
		return false;

}
bool Timer::isStop()
{
	if (Timer::is_stop)
		return true;
	else
		return false;
}
void Timer::start()
{
	if (Timer::is_stop)
	{
		start_time = time(0);
		is_stop = false;
	}
	if (is_pause)
	{
		start_time += time(0) - pause_time;
		is_pause = false;
	}
}
void Timer::Pause()
{
	if (is_pause || is_stop)
		return;
	else
	{
		is_pause = true;
		pause_time = time(0);
	}
}
void Timer::stop()
{
	if (is_stop)
		return;
	else if (is_pause)
	{
		is_pause = false;
		is_stop = true;
	}
	else if (!is_stop)
	{
		is_stop = true;
	}


}
void Timer::show()
{
	long t = time(0) - start_time;
	gotoxy(35, 12);
	cout << setw(2) << setfill('0') << t / 60 / 60 << ":"
		<< setw(2) << setfill('0') << t / 60 << ":"
		<< setw(2) << setfill('0') << t % 60 << endl;
}
int main()
{
	Timer t;
	char ch;
	hidden();//���ع��
	system("color 02");
	gotoxy(35, 12);
	cout << "00:00:00";
	gotoxy(20, 18);
	cout << "��a��ʼ�����ո���ͣ����sֹͣ";
	while (1)
	{
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
			case 'a':t.start(); break;
			case 's':t.stop(); break;
			case ' ':t.Pause(); break;
			default:break;
			}
		}
		if (!t.isStop() && !t.isPause())
		{
			t.show();
		}
	}


	
}