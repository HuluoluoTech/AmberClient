// Fill out your copyright notice in the Description page of Project Settings.


#include "AmberWorker.h"

#pragma region Main Code
FAmberWorker::FAmberWorker()
{
	RunningThread = FRunnableThread::Create(this, TEXT("Amber Runnable Worker."));
}

FAmberWorker::~FAmberWorker()
{
	if (RunningThread)
	{
		RunningThread->Kill();
		delete RunningThread;
	}
}
#pragma endregion

bool FAmberWorker::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Amber Worker Init..."));

	// if return false, we want to abort the thread
	return true;
}

uint32 FAmberWorker::Run()
{
	while (bRunning)
	{
		UE_LOG(LogTemp, Warning, TEXT("Amber Worker is Running..."));
		//FPlatformProcess::Sleep(1.0f);
	}

	return 0;
}

void FAmberWorker::Stop()
{
	bRunning = false;
}
