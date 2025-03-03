// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ControllerDataAsset.generated.h"


USTRUCT(BlueprintType)
struct FControllerData
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FKey Key;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> ActorsReferences;
};

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class RUNTIMECONTROLLER_API UControllerDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FKey> Tags;
};


