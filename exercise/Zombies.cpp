#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <iostream>
using namespace std;

int main()
{
    //找到内存
    HWND game_window = FindWindowA(NULL, _T("Plants vs. Zombies"));
    if (game_window == NULL)
    {
        printf("没有找到游戏！\n");
        system("pause");
        return 0;
    }
    //根据窗口打开进程id
    unsigned long pwId = 0;
    GetWindowThreadProcessId(game_window, &pwId);
    if (pwId == 0)
    {
        printf("没有找到pid");
        system("pause");
        return 0;
    }
    //根据pid获取游戏进程句柄
    HANDLE game_process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pwId);
    if (game_process == NULL)
    {
        printf("打开游戏失败");
        system("pause");
        return 0;
    }
    //读取内存
    unsigned long pw_baseaddress = 0x755f28;
    unsigned long pw_address_value = 0;
    SIZE_T pw_size;

    if (FALSE == ReadProcessMemory(
                     game_process,
                     (void *)pw_baseaddress,
                     &pw_address_value,
                     sizeof(unsigned long),
                     &pw_size))
    {
        printf("获取静态变量失败，错误代码%s\n", GetLastError());
        system("pause");
        return 0;
    }

    //进行第一次偏移
    unsigned long pw_sunshineoff = 0x868;
    unsigned long pw_sunshineoff_value = 0;
    if (FALSE == ReadProcessMemory(
                     game_process,
                     (void *)(pw_address_value + pw_sunshineoff),
                     &pw_sunshineoff_value,
                     sizeof(unsigned long),
                     &pw_size))
    {
        printf("一级偏移失败，错误代号%d", GetLastError());
        system("pause");
        return 0;
    }

    //进行二次偏移
    unsigned long pw_sunshineoff_two = 0x5578;
    unsigned long pw_sun_value = 0;
    if (FALSE == ReadProcessMemory(
                     game_process,
                     (void *)(pw_sunshineoff_value + pw_sunshineoff_two),
                     &pw_sun_value,
                     sizeof(unsigned long),
                     &pw_size))
    {
        printf("读取失败");
        system("pause");
        return 0;
    }
    
    DWORD set_memory = pw_sunshineoff_value + pw_sunshineoff_two;//修改内存时使用的变量
    while (1)
    {
        system("cls");
        int n;
        cout << "请输入阳光值:" << endl;
        cin >> n;
        WriteProcessMemory(
            game_process,
            (LPVOID)set_memory,
            &n,
            sizeof(unsigned long),
            &pw_size);
        cout<<(LPVOID)set_memory<< endl;

        Sleep(1000);
    }

    system("pause");
    return 0;
}