#include <windows.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct ProcessorData {
   int affinityMask;                /* affinity mask of this processor (just one bit set) */
   PROCESS_INFORMATION processInfo; /* process currently running on this processor */
   int running;                     /* 1 when this processor is running a task, 0 otherwise */
} ProcessorData;

/* function prototypes */
void printError(char* functionName);

int main(int argc, char *argv[])
{
    HANDLE *processHandles;
    int processorCount =0;
    int jobsCount =argc -1;
    
    STARTUPINFO startInfo;      
        ZeroMemory(&startInfo, sizeof(startInfo));
        startInfo.cb = sizeof(startInfo);
   
    HANDLE pHandle = GetCurrentProcess();
    PDWORD_PTR dwProcessAffinityMask;
    PDWORD_PTR dwSystemAffinityMask;
   
    GetProcessAffinityMask(
        pHandle,
        &dwProcessAffinityMask,
        &dwSystemAffinityMask
    );
   
    HANDLE *processHandles;
    processHandles = malloc(processHandles * sizeof(ProcessorData));
    processHandles = malloc(handleCount * sizeof(ProcessorData));

    if (argc < 3)
    {
        fprintf(stderr, "usage, %s  SCHEDULE_TYPE  SECONDS...\n", argv[0]);
        fprintf(stderr, "Where: SCHEDULE_TYPE = 0 means \"first come first serve\"\n");
        fprintf(stderr, "       SCHEDULE_TYPE = 1 means \"shortest job first\"\n");
        fprintf(stderr, "       SCHEDULE_TYPE = 2 means \"longest job first\"\n");
        return 0;
    }
    
    DWORD affinityProcessorCount = (DWORD) lpProcessAffinityMask;
    if(affinityProcessorCount >>0 &1) { processorCount += 1; } 
    if(affinityProcessorCount >>1 &1) { processorCount += 1; } 
    if(affinityProcessorCount >>2 &1) { processorCount += 1; }
    if(affinityProcessorCount >>3 &1) { processorCount += 1; }
    if(affinityProcessorCount >>4 &1) { processorCount += 1; }
    if(affinityProcessorCount >>5 &1) { processorCount += 1; }
    if(affinityProcessorCount >>6 &1) { processorCount += 1; }
    if(affinityProcessorCount >>7 &1) { processorCount += 1; }
    if(affinityProcessorCount >>8 &1) { processorCount += 1; }
    if(affinityProcessorCount >>9 &1) { processorCount += 1; }
    if(affinityProcessorCount >>10 &1) { processorCount += 1; }
    if(affinityProcessorCount >>11 &1) { processorCount += 1; }
    if(affinityProcessorCount >>12 &1) { processorCount += 1; }
    if(affinityProcessorCount >>13 &1) { processorCount += 1; }
    if(affinityProcessorCount >>14 &1) { processorCount += 1; }
    if(affinityProcessorCount >>15 &1) { processorCount += 1; }
    if(affinityProcessorCount >>16 &1) { processorCount += 1; }
    
    ProcessorData (*processorPool)[processorCount];
    ProcessorData *processorPool;                
    processorPool = malloc( processorCount * sizeof(ProcessorData));
    
    for(int i=0; i < processorCount; i++)
    {
        processorPool[i].affinityMask = 0b00000001<<i; //affinity mask of this processor 
        processorPool[i].processInfo; // process currently running on this processor 
        processorPool[i].running = 0;
    }
   
    int p = 0;
    while(p < processorCount) {
        printf("At index: %d, the processorPool affinity mask is: %d\n", p, processorPool[p].affinityMask);
        p++;
    }
   
    int maxIndex=0;
    if( jobsCount > processorCount){ maxIndex =processorCount;}
    if( jobsCount <= processorCount){ maxIndex =jobsCount;}

    char *programName = "computeProgram_64.exe";
    int indexStart = 1;
    char launch[300];
    
    for(int i=0; i <argc-1; i++)
    {
        sprintf(launch, "%s %s", programName, argv[indexStart]);
        sprintf(launch,  "%s",  argv[indexStart]);
   
        if(!CreateProcess(programName, launch, NULL, NULL, TRUE,
                                CREATE_SUSPENDED | CREATE_NEW_CONSOLE,
                                NULL, NULL, &startInfo, &processorPool[i].processInfo))
        {
            printError("CreateProcess");
        }
         
        else
        {
            printf("\nStarted program with pid = %d\n\n",  (int)processorPool[i].processInfo.dwProcessId);
            SetProcessAffinityMask(processorPool[i].processInfo.hProcess, processorPool[i].affinityMask); 
            
            //update processor
            ResumeThread(processorPool[i].processInfo.hThread) ;
            processorPool[i].running = 1;
            indexStart++;
        }
    }//First come first serve
    
    if(argv[1] == 1){ exit(0);}

    for(int i =2; i <argc ; i++)
    {
        min = array[i];
        for(int j = i+1; j < argc ; j++)
        {
            if(argv[j] < argv[i])
            {
                min = array[j];
                int temp = argv[i];
                argv[i] =  argv[j];
                argv[j] = temp;
                swap(argv[i], argv[j]);
            }
         
        }
       
    }

    for(int i =argv[2]; i <argv ; i++)
    {
        printf("%d \n", argv[i]);
    }

    /* wait for each child process to end */
    for (int i = 0; i < argc; i++)
    {
        WaitForSingleObject(processInfo[i].hProcess, INFINITE);
    }
    for (i = 0; i < argc; i++)
    {
        /* close all the handles */
        CloseHandle(processInfo[i].hThread);
        CloseHandle(processInfo[i].hProcess);
    }
    /* Repeatedly wait for a process to finish and then,
      if there are more jobs to run, run a new job on
      the processor that just became free. */
    while (1)
    {
        DWORD result;
        int handleCount = 0;
      
        /* get, from the processor pool, handles to the currently running processes */
        /* put those handles in an array */
        /* use a parallel array to keep track of where in the processor pool each handle came from */
        for(int i=0; i < processorCount; i++)
        {
            if(processorPool[i].running ==1)
            {
                handleCount++;
                printf("received handle for %d \n" , i );
            }
        }
   
        processHandles[i] = processorPool[i].processInfo.hProcess;
        printf("the handle count is %d \n",handleCount);
   
        processHandles = malloc(handleCount * sizeof(ProcessorData));

        processHandles[i] = processorPool[i].processInfo.hProcess;
        /* check that there are still processes running, if not, quit */
        
        if(handleCount == 0){ exit(0); }
      
        /* wait for one of the running processes to end */
        if(handleCount != 0) 
        {
            if (WAIT_FAILED == (result = WaitForMultipleObjects(handleCount, processHandles, FALSE, INFINITE)))
                printError("WaitForMultipleObjects"); 
        }

        /* translate result from an index in processHandles[] to an index in processorPool[] */

        /* close the handles of the finished process and update the processorPool array */
        int index = (int)result;
    
        CloseHandle(processHandles[index]);
        CloseHandle(processHandles[index]);
           
        // loop thru the processPool array and find the index of the handle that MATCHES the handle in the handle array that just finished. save that index into handleToCPUIndex
        for(int i=0; i<processorCount; i++) 
        {
            if(processHandles[index] == processorPool[i].processInfo.hProcess) 
            {
                processorPool[i].running = 0;
            }
        }
   }
   return 0;
}

/****************************************************************
   The following function can be used to print out "meaningful"
   error messages. If you call a Windows function and it returns
   with an error condition, then call this function right away and
   pass it a string containing the name of the Windows function that
   failed. This function will print out a reasonable text message
   explaining the error.
*/

void printError(char* functionName)
{
    LPVOID lpMsgBuf;
    int error_no;
    error_no = GetLastError();
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
        NULL,
        error_no,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), /* default language */
        (LPTSTR) &lpMsgBuf,
        0,
        NULL
    );
    /* Display the string. */
    fprintf(stderr, "\n%s failed on error %d: ", functionName, error_no);
    fprintf(stderr, (const char*)lpMsgBuf);
    /* Free the buffer. */
    LocalFree( lpMsgBuf );
