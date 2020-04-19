#include <windows.h>
#include <stdio.h>
#include "lab3.h"



#define THREADCOUNT 13


HANDLE Threads[THREADCOUNT];
HANDLE sem1,sem2,sem3,sem4,sem5,sem6;


DWORD WINAPI ThreadA(LPVOID name);
DWORD WINAPI ThreadB(LPVOID name);
DWORD WINAPI ThreadC(LPVOID name);
DWORD WINAPI ThreadD(LPVOID name);
DWORD WINAPI ThreadE(LPVOID name);
DWORD WINAPI ThreadG(LPVOID name);
DWORD WINAPI ThreadF(LPVOID name);
DWORD WINAPI ThreadH(LPVOID name);
DWORD WINAPI ThreadK(LPVOID name);
DWORD WINAPI ThreadM(LPVOID name);
DWORD WINAPI ThreadN(LPVOID name);
DWORD WINAPI ThreadP(LPVOID name);
DWORD WINAPI ThreadI(LPVOID name);


DWORD ThreadID;


DWORD WINAPI ThreadA(LPVOID name)
{



    UNREFERENCED_PARAMETER(name);

    DWORD dwWaitResult;
    UINT bContinue = 0;

    while (bContinue != 3)
    {

        dwWaitResult = WaitForSingleObject(sem2, INFINITE);

        switch (dwWaitResult)
        {
       
        case WAIT_OBJECT_0:

            std::cout << 'a' << std::flush;
            bContinue += 1;

            computation();

            if (!ReleaseSemaphore(sem1, 1, NULL))    
            {
                printf("ReleaseSemaphore error: %d\n", GetLastError());
            }
            break;


        case WAIT_TIMEOUT:
            printf("Thread %d: wait timed out\n", GetCurrentThreadId());
            break;
        }
    }
    return TRUE;

  

};


DWORD WINAPI ThreadC(LPVOID name)
{

    for (size_t i = 0; i < 3; ++i)
    {
        std::cout << 'c' << std::flush;
        computation();
    }

    return TRUE;

};

DWORD WINAPI ThreadB(LPVOID name)
{

    for (size_t i = 0; i < 3; ++i)
    {
        std::cout << 'b' << std::flush;
        computation();
    }

    return TRUE;


};


DWORD WINAPI ThreadG(LPVOID name)
{

    for (size_t i = 0; i < 3; ++i)
    {
        std::cout << 'g' << std::flush;
        computation();
    }

    return TRUE;

};


DWORD WINAPI ThreadD(LPVOID name)
{

    UNREFERENCED_PARAMETER(name);
    DWORD dwWaitResult;
    UINT bContinue = 0;

    while (bContinue != 3)
    {

        dwWaitResult = WaitForSingleObject(sem1, INFINITE);//catch

        switch (dwWaitResult)
        {

        case WAIT_OBJECT_0:

            std::cout << 'd' << std::flush;
            bContinue += 1;

            computation();

            if (!ReleaseSemaphore(sem2, 1, NULL)) { //increment next
                printf("ReleaseSemaphore error: %d\n", GetLastError());
            }
            break;


        case WAIT_TIMEOUT:
            printf("Thread %d: wait timed out\n", GetCurrentThreadId());
            break;
        }
    }

    WaitForSingleObject(Threads[0], INFINITE);

    Threads[2] = CreateThread(NULL, 0, ThreadC, NULL, 0, &ThreadID);
    Threads[3] = CreateThread(NULL, 0, ThreadB, NULL, 0, &ThreadID);
    Threads[4] = CreateThread(NULL, 0, ThreadG, NULL, 0, &ThreadID);
    Threads[5] = CreateThread(NULL, 0, ThreadH, NULL, 0, &ThreadID);

    for (size_t i = 0; i < 3; ++i)
    {
        std::cout << 'd' << std::flush;
        computation();
    }

    WaitForSingleObject(Threads[2], INFINITE);
    WaitForSingleObject(Threads[3], INFINITE);
    WaitForSingleObject(Threads[4], INFINITE);

    Threads[6] = CreateThread(NULL, 0, ThreadE, NULL, 0, &ThreadID);
    Threads[7] = CreateThread(NULL, 0, ThreadF, NULL, 0, &ThreadID);
    Threads[8] = CreateThread(NULL, 0, ThreadI, NULL, 0, &ThreadID);
    Threads[9] = CreateThread(NULL, 0, ThreadK, NULL, 0, &ThreadID);

    bContinue = 0;
    while (bContinue != 3)
    {

        dwWaitResult = WaitForSingleObject(sem1, INFINITE);//catch

        switch (dwWaitResult)
        {

        case WAIT_OBJECT_0:

            std::cout << 'd' << std::flush;
            bContinue += 1;

            computation();

            if (!ReleaseSemaphore(sem2, 1, NULL)) { //increment next
                printf("ReleaseSemaphore error: %d\n", GetLastError());
            }
            break;


        case WAIT_TIMEOUT:
            printf("Thread %d: wait timed out\n", GetCurrentThreadId());
            break;
        }
    }

    return 0;

};
 
DWORD WINAPI ThreadH(LPVOID name)
{
    UNREFERENCED_PARAMETER(name);

    for (size_t i = 0; i < 3; ++i)
    {
        std::cout << 'h' << std::flush;
        computation();
    }

    
    DWORD dwWaitResult;
    UINT bContinue = 0;

    while (bContinue != 3)
    {

        dwWaitResult = WaitForSingleObject(sem6, INFINITE);//catch

        switch (dwWaitResult)
        {

        case WAIT_OBJECT_0:

            std::cout << 'h' << std::flush;
            bContinue += 1;

            computation();

            if (!ReleaseSemaphore(sem1, 1, NULL)) { //increment next
                printf("ReleaseSemaphore error: %d\n", GetLastError());
            }
            break;


        case WAIT_TIMEOUT:
            printf("Thread %d: wait timed out\n", GetCurrentThreadId());
            break;
        }
    }

    return TRUE;

   



    return TRUE;

};
 
DWORD WINAPI ThreadK(LPVOID name)
{

    UNREFERENCED_PARAMETER(name);
    DWORD dwWaitResult;
    UINT bContinue = 0;

    while (bContinue != 3)
    {

        dwWaitResult = WaitForSingleObject(sem5, INFINITE);//catch

        switch (dwWaitResult)
        {

        case WAIT_OBJECT_0:

            std::cout << 'k' << std::flush;
            bContinue += 1;

            computation();

            if (!ReleaseSemaphore(sem6, 1, NULL)) { //increment next
                printf("ReleaseSemaphore error: %d\n", GetLastError());
            }
            break;


        case WAIT_TIMEOUT:
            printf("Thread %d: wait timed out\n", GetCurrentThreadId());
            break;
        }
    }

    return TRUE;

};
 
DWORD WINAPI ThreadI(LPVOID name)
{

    UNREFERENCED_PARAMETER(name);
    DWORD dwWaitResult;
    UINT bContinue = 0;

    while (bContinue != 3)
    {

        dwWaitResult = WaitForSingleObject(sem4, INFINITE);//catch

        switch (dwWaitResult)
        {

        case WAIT_OBJECT_0:

            std::cout << 'i' << std::flush;
            bContinue += 1;

            computation();

            if (!ReleaseSemaphore(sem5, 1, NULL)) { //increment next
                printf("ReleaseSemaphore error: %d\n", GetLastError());
            }
            break;


        case WAIT_TIMEOUT:
            printf("Thread %d: wait timed out\n", GetCurrentThreadId());
            break;
        }
    }

    return TRUE;

};
 
DWORD WINAPI ThreadF(LPVOID name)
{

    UNREFERENCED_PARAMETER(name);
    DWORD dwWaitResult;
    UINT bContinue = 0;

    while (bContinue != 3)
    {

        dwWaitResult = WaitForSingleObject(sem3, INFINITE);//catch

        switch (dwWaitResult)
        {

        case WAIT_OBJECT_0:

            std::cout << 'f' << std::flush;
            bContinue += 1;

            computation();

            if (!ReleaseSemaphore(sem4, 1, NULL)) { //increment next
                printf("ReleaseSemaphore error: %d\n", GetLastError());
            }
            break;


        case WAIT_TIMEOUT:
            printf("Thread %d: wait timed out\n", GetCurrentThreadId());
            break;
        }
    }

    return TRUE;

};
 
DWORD WINAPI ThreadE(LPVOID name)
{

    UNREFERENCED_PARAMETER(name);
    DWORD dwWaitResult;
    UINT bContinue = 0;
    while (bContinue != 3)
    {

        dwWaitResult = WaitForSingleObject(sem2, INFINITE);//catch

        switch (dwWaitResult)
        {

        case WAIT_OBJECT_0:

            std::cout << 'e' << std::flush;
            bContinue += 1;

            computation();

            if (!ReleaseSemaphore(sem3, 1, NULL)) { //increment next
                printf("ReleaseSemaphore error: %d\n", GetLastError());
            }
            break;


        case WAIT_TIMEOUT:
            printf("Thread %d: wait timed out\n", GetCurrentThreadId());
            break;
        }
    }


    //

    

    bContinue = 0;
    while (bContinue != 3)
    {

        dwWaitResult = WaitForSingleObject(sem2, INFINITE);//catch

        switch (dwWaitResult)
        {

        case WAIT_OBJECT_0:

            std::cout << 'e' << std::flush;
            bContinue += 1;

            computation();

            if (!ReleaseSemaphore(sem3, 1, NULL)) { //increment next
                printf("ReleaseSemaphore error: %d\n", GetLastError());
            }
            break;


        case WAIT_TIMEOUT:
            printf("Thread %d: wait timed out\n", GetCurrentThreadId());
            break;
        }
    }

    return TRUE;

};

DWORD WINAPI ThreadM(LPVOID name)
{

    UNREFERENCED_PARAMETER(name);
    DWORD dwWaitResult;
    UINT bContinue = 0;
    while (bContinue != 3)
    {

        dwWaitResult = WaitForSingleObject(sem3, INFINITE);//catch

        switch (dwWaitResult)
        {

        case WAIT_OBJECT_0:

            std::cout << 'm' << std::flush;
            bContinue += 1;

            computation();

            if (!ReleaseSemaphore(sem1, 1, NULL)) { //increment next
                printf("ReleaseSemaphore error: %d\n", GetLastError());
            }
            break;


        case WAIT_TIMEOUT:
            printf("Thread %d: wait timed out\n", GetCurrentThreadId());
            break;
        }
    }

    return TRUE;

};

DWORD WINAPI ThreadN(LPVOID name)
{

    UNREFERENCED_PARAMETER(name);
    DWORD dwWaitResult;
    UINT bContinue = 0;
    while (bContinue != 3)
    {

        dwWaitResult = WaitForSingleObject(sem1, INFINITE);//catch

        switch (dwWaitResult)
        {

        case WAIT_OBJECT_0:

            std::cout << 'n' << std::flush;
            bContinue += 1;

            computation();

            if (!ReleaseSemaphore(sem2, 1, NULL)) { //increment next
                printf("ReleaseSemaphore error: %d\n", GetLastError());
            }
            break;


        case WAIT_TIMEOUT:
            printf("Thread %d: wait timed out\n", GetCurrentThreadId());
            break;
        }
    }


    WaitForSingleObject(Threads[11], INFINITE);

    Threads[12] = CreateThread(NULL, 0, ThreadP, NULL, 0, &ThreadID);

    bContinue = 0;
    while (bContinue != 3)
    {

        dwWaitResult = WaitForSingleObject(sem1, INFINITE);//catch

        switch (dwWaitResult)
        {

        case WAIT_OBJECT_0:

            std::cout << 'n' << std::flush;
            bContinue += 1;

            computation();

            if (!ReleaseSemaphore(sem2, 1, NULL)) { //increment next
                printf("ReleaseSemaphore error: %d\n", GetLastError());
            }
            break;


        case WAIT_TIMEOUT:
            printf("Thread %d: wait timed out\n", GetCurrentThreadId());
            break;
        }
    }



    return TRUE;

};

DWORD WINAPI ThreadP(LPVOID name)
{

    UNREFERENCED_PARAMETER(name);
    DWORD dwWaitResult;
    UINT bContinue = 0;
    while (bContinue != 3)
    {

        dwWaitResult = WaitForSingleObject(sem2, INFINITE);//catch

        switch (dwWaitResult)
        {

        case WAIT_OBJECT_0:

            std::cout << 'p' << std::flush;
            bContinue += 1;

            computation();

            if (!ReleaseSemaphore(sem1, 1, NULL)) { //increment next
                printf("ReleaseSemaphore error: %d\n", GetLastError());
            }
            break;


        case WAIT_TIMEOUT:
            printf("Thread %d: wait timed out\n", GetCurrentThreadId());
            break;
        }
    }


    return 0;

};



unsigned int lab3_thread_graph_id() 
{
    return 15;
}

const char* lab3_unsynchronized_threads()
{
    return "bcdgh";
}

const char* lab3_sequential_threads()
{
    return "emn";
}

int lab3_init()
{
    


    sem1 = CreateSemaphore(NULL, 1, 1, NULL);

    if (sem1 == NULL)
    {   printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    
    sem2 = CreateSemaphore(
        NULL,           
        0,  
        1,  
        NULL); 

    if (sem2 == NULL)
    {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }

    sem3 = CreateSemaphore(NULL, 0, 1, NULL);
    if (sem3 == NULL)
    {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }

    sem4 = CreateSemaphore(NULL, 0, 1, NULL);
    if (sem4 == NULL)
    {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }

    sem5 = CreateSemaphore(NULL, 0, 1, NULL);
    if (sem5 == NULL)
    {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }

    sem6 = CreateSemaphore(NULL, 0, 1, NULL);
    if (sem6 == NULL)
    {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }

   Threads[0] = CreateThread(NULL, 0, ThreadA, NULL, 0, &ThreadID);
   Threads[1] = CreateThread(NULL, 0, ThreadD, NULL, 0, &ThreadID);

   WaitForSingleObject(Threads[1], INFINITE);

   WaitForSingleObject(Threads[5], INFINITE);


   Threads[10] = CreateThread(NULL, 0, ThreadN, NULL, 0, &ThreadID);
   Threads[11] = CreateThread(NULL, 0, ThreadM, NULL, 0, &ThreadID);
   WaitForSingleObject(Threads[10], INFINITE);
   
   WaitForMultipleObjects(THREADCOUNT, Threads, TRUE, INFINITE);

   for (int i = 0; i < THREADCOUNT; i++)
       CloseHandle(Threads[i]);

   CloseHandle(sem1);
   CloseHandle(sem2);
   CloseHandle(sem3);
   CloseHandle(sem4);
   CloseHandle(sem5);
   CloseHandle(sem6);


    return 0;
}
