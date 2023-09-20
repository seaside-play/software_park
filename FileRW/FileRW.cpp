// FileRW.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
#include <string>
#include <chrono>

volatile int count{ 0 };
std::mutex mtx;

const std::string file_folder{ "C:\\Users\\wisechip\\Desktop\\workspace\\temp\\" };
const std::string file_name{ "test.txt" };
const std::string file_path{ file_folder + file_name };

const int kWriteCountOnce = 1000;
const int kReadCountOnce = 10000;

void WriteFunc()
{
    std::lock_guard<std::mutex> clock_guard(mtx);
    //mtx.lock();
    std::ofstream f;
    f.open(file_path, std::ios::app);
    if (f)
    {
        for (int i = 0; i < kWriteCountOnce; ++i)
        {
            std::this_thread::sleep_for(std::chrono::microseconds(1));

            ++count;
            f << count << std::endl;
        }
        f.close();
    }
    //mtx.unlock();
}

void ReadFunc()
{
    while (count < kReadCountOnce)
    {
        char buffer[256];
        std::ifstream f;
        f.open(file_path, std::ios_base::in);
        if (f)
        {
            std::lock_guard<std::mutex> clock_guard(mtx);
            while (!f.eof())
            {
                f.getline(buffer, 100);
                std::cout << buffer << std::endl;
            }
            f.close();
        }
        else
        {
            std::cout << "no open" << std::endl;
        }

    }
}



int main()
{
    std::thread write_threads[10];
    std::thread read_thread;

    read_thread = std::thread(ReadFunc);

    for (int i = 0; i < 10; ++i)
    {
        write_threads[i] = std::thread(WriteFunc);
    }

    for (auto& th : write_threads)
        th.join();
    read_thread.join();

    system("pause");
    return 0;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
