// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HAL/Runnable.h"

/**
 * 
 */
class AMBER_API FAmberWorker : public FRunnable
{
public:
	FAmberWorker();
	virtual ~FAmberWorker() override;

public:
	bool Init() override;
	uint32 Run() override;
	void Stop() override;

private:
	FRunnableThread* RunningThread;
	bool bRunning;
};
